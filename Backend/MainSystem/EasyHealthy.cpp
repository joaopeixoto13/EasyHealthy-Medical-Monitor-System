#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>
#include <errno.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <signal.h>
#include <chrono>
#include <ctime>
#include <sstream>
#include <dirent.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <strings.h>
#include "CDataFormat.h"
#include "CMessageQueue.h"
#include "CSingleton.h"
#include "SUtils.h"
#include "CMAX30102.h"
#include "CMLX90614.h"
#include "CSensors.h"
#include "CBuzzer.h"

/**< Get the EasyHealthy/Aplication Handler */
Singleton *myApp = Singleton::getInstance();

pthread_mutex_t cond_mutex_alarm = PTHREAD_MUTEX_INITIALIZER; /**< Mutex for the alarm */
pthread_cond_t cond_alarm = PTHREAD_COND_INITIALIZER;         /**< Condition for the alarm */
bool isTimeToCheckAlarm = 0;                                  /**< Flag to check the alarm */
bool usbStatus = 0;                                           /**< USB status */

/**
 * @brief Main threads declaration
 * @param ptr
 * @return void*
 */
void *tDatabaseManager(void *ptr);
void *tDataAcquisition(void *ptr);
void *tExport(void *ptr);
void *tReceiveFromGUI(void *ptr);
void *tSendToGUI(void *ptr);
void *tAlarm(void *ptr);

/**
 * @brief Check if the thread was created corretly
 * @param status
 */
void CheckFail(int status)
{
    if (status)
    {
        if (status == EPERM)
            fprintf(stderr, "pthread_create() got EPERM at\n");
        else if (status == EINVAL)
            fprintf(stderr, "pthread_create() got EINVAL\n");
        else
            fprintf(stderr, "pthread_create() got neither EPERM nor EINVAL\n");

        fprintf(stderr, "pthread_create() got error %d\n", status);
        errno = status;
        perror("pthread_create()");
        exit(1);
    }
}

/**
 * @brief Setup the thread
 * @param prio specifies the thread priority
 * @param pthread_attr specifies the thread attribute handler
 * @param pthread_param specifies the sheduler handler
 */
void SetupThread(int prio, pthread_attr_t *pthread_attr, struct sched_param *pthread_param)
{
    pthread_attr_setschedpolicy(pthread_attr, SCHED_RR);
    pthread_param->sched_priority = prio;
    pthread_attr_setschedparam(pthread_attr, pthread_param);
    pthread_attr_setinheritsched(pthread_attr, PTHREAD_EXPLICIT_SCHED);
}

/**
 * @brief Check the thread policy and priority
 * @param threadID specifies the thread ID
 * @param threadName specifies the thread name
 */
void CheckPolicyPrio(pthread_t threadID, const char *threadName)
{
    int thread_policy;
    struct sched_param thread_attr;

    pthread_getschedparam(threadID, &thread_policy, &thread_attr);

    std::cout << "\n---------------\n";
    printf("[%s] running at %s/%d\n", threadName,
           (thread_policy == SCHED_FIFO ? "FIFO"
                                        : (thread_policy == SCHED_RR ? "RR"
                                                                     : (thread_policy == SCHED_OTHER ? "OTHER"
                                                                                                     : "unknown"))),
           thread_attr.sched_priority);
}

/**
 * @brief Set the Core Affinity
 * @param threadID specifies the thread ID
 * @param core specifies the core number
 * @param threadName specifies the thread name
 */
void SetCoreAffinity(pthread_t threadID, int core, const char *threadName)
{
    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    CPU_SET(core, &cpuset);
    if (pthread_setaffinity_np(pthread_self(), sizeof(cpu_set_t), &cpuset))
        std::cout << "Error setting affinity for thread " << threadName << std::endl;
    for (int i = 0; i < CPU_SETSIZE; i++)
        if (CPU_ISSET(i, &cpuset))
            std::cout << "Thread " << threadName << " is running on core " << i << std::endl;
}

/**
 * @brief Get the Current Time
 * @return std::string
 */
std::string getCurrentTime()
{
    time_t t = time(0); // get time now
    struct tm *now = localtime(&t);
    std::stringstream ss;
    ss << (now->tm_year + 1900) << "/"
       << (now->tm_mon + 1) << "/"
       << now->tm_mday << "-"
       << now->tm_hour << ":"
       << now->tm_min << ":"
       << now->tm_sec;
    return ss.str();
}

/**
 * @brief Download as CSV
 * @param str specifies the string to be converted
 * @return std::string name of the file
 */
std::string downloadAsCSV(std::string str)
{
    std::stringstream ss1(str);
    std::string line, s1, s2, s3, s4, aux;
    while (std::getline(ss1, line))
    {
        std::stringstream ss2(line);
        ss2 >> s1 >> s2 >> s3 >> s4;
        aux = aux + s1 + ";" + s3 + ";" + s4 + "\n";
    }
    str = "Time;Test;Result\n" + aux;
    std::ofstream file;
    std::string name = "EasyHealthyData" + getCurrentTime() + ".csv";
    name.replace(name.find("/"), 1, "_");
    name.replace(name.find("/"), 1, "_");
    name.replace(name.find(":"), 1, "_");
    name.replace(name.find(":"), 1, "_");
    name.insert(name.begin(), '/');
    file.open(name);
    file << str;
    file.close();
    return name;
}

/**
 * @brief Send Regular Email
 * @note User Email and Doctor Email
 * @param isDoctor specifies if the email to sent is for Doctor or for User
 * @param fileName specifies the file name to be sent
 */
void sendRegularEmail(bool isDoctor, std::string fileName)
{
    struct SUSER userInfo;
    std::string title, description, sex, email, timestamp, out, BMI_result, aux;
    int BMR, TDEE;
    float BMI;

    /**< Get the current user information */
    userInfo = myApp->getUsers().getInfo();

    /**< Fill the Title field */
    title = "EasyHealthy Report";

    /**< Fill the sex field */
    if (userInfo.sex == 0) /**< If the user is male */
        sex = "Mr. ";
    else /**< If the user is female */
        sex = "Ms. ";

    /**< Fill the email field */
    if (isDoctor)
        email = userInfo.email_doctor; /**< Doctor email */
    else
        email = userInfo.email_user; /**< User email */

    /**< Extract the current time */
    auto time = std::chrono::system_clock::now();
    std::time_t tt = std::chrono::system_clock::to_time_t(time);
    tm utc_tm = *gmtime(&tt);
    tm local_tm = *localtime(&tt);
    local_tm.tm_mon += 1;
    local_tm.tm_year += 1900;

    /**< Fill the timestamp field */
    timestamp = std::to_string(local_tm.tm_mday) + "/" + std::to_string(local_tm.tm_mon) + "/" + std::to_string(local_tm.tm_year) + " at " + std::to_string(local_tm.tm_hour) + ":" + std::to_string(local_tm.tm_min) + "h";

    /**< Fill the description field */
    if (isDoctor)
        description = "As requested at " + timestamp + ", by " + sex + userInfo.name + ", attached are the measurements already taken with the EasyHealthy product.";
    else
        description = "Hi " + sex + userInfo.name + ", as requested at " + timestamp + ", attached are the measurements already taken with the EasyHealthy product.";

    /**< Calculate the total number of calories for normal bodily functions using the Harris-Benedict Formula */
    if (userInfo.sex == 0) /**< If the user is male */
        BMR = 66 + (13.7 * userInfo.weight) + (5 * userInfo.height) - (6.8 * userInfo.age);
    else /**< If the user is female */
        BMR = 655 + (9.6 * userInfo.weight) + (1.8 * userInfo.height) - (4.7 * userInfo.age);

    /**< Calculate the total daily energy expenditure */
    if (userInfo.activity_level == 1)
        TDEE = BMR * 1.2;
    else if (userInfo.activity_level == 2)
        TDEE = BMR * 1.375;
    else if (userInfo.activity_level == 3)
        TDEE = BMR * 1.55;
    else if (userInfo.activity_level == 4)
        TDEE = BMR * 1.725;
    else
        TDEE = BMR * 1.9;

    /**< Calculate the Body Mass Index using the Metric System */
    BMI = (((float)userInfo.weight * 10000.0 / (float)userInfo.height) / (float)(userInfo.height));
    aux = std::to_string(BMI);
    aux.resize(5);
    if (BMI < 18.5)
        BMI_result = "Underweight";
    else if (BMI >= 18.5 && BMI < 24.9)
        BMI_result = "Normal";
    else if (BMI >= 24.9 && BMI < 29.9)
        BMI_result = "Overweighted";
    else if (BMI >= 29.9 && BMI < 35)
        BMI_result = "Obese";
    else
        BMI_result = "Extreme obese";
    description += "\n\nSome health information:";
    description += "\n1 - Total number of calories for normal bodily functions\n\tBMR: " + std::to_string(BMR) + " calories";
    description += "\n2 - Total daily energy expenditure\n\tTDEE: " + std::to_string(TDEE) + " calories";
    description += "\n3 - Body Mass Index\n\tBMI: " + aux + "%. Result: " + BMI_result;

    /**< Prepare the Email */
    out = "echo \"" + description + "\" | mutt -s \"" + title + "\" " + email + " -a " + fileName;

    /**< Send the Email */
    system(out.c_str());
}

/**
 * @brief Send Alarm Email
 * @note Receives a string with all the user(s) ID(s) and alarm(s) information
 * @param cmd specifies the string with the data
 */
void sendAlarmEmail(std::string cmd)
{
    std::string delimiter = "\n";
    std::string testType, token, title, description, sex, out;
    int timestamp, user_id, count;
    size_t pos = 0;
    std::vector<std::vector<CAlarm>> usrs(4);
    std::vector<struct SUSER> usersInfo;
    /**< Get all users information */
    usersInfo = myApp->getUsers().getAllInfo();
    /**< Fill the Title field */
    title = "EasyHealthy Alarm";

    /**< Parse the command received  */
    while ((pos = cmd.find(delimiter)) != std::string::npos)
    {
        token = cmd.substr(0, pos);             /**< Get the token */
        std::stringstream ss(token);            /** Convert to stringstream to process */
        ss >> user_id >> timestamp >> testType; /** Update the fields */
        if (user_id == 0)                       /**< User 0 */
            usrs[EID::USER_0].push_back(CAlarm(timestamp, testType));
        else if (user_id == 1) /**< User 1 */
            usrs[EID::USER_1].push_back(CAlarm(timestamp, testType));
        else if (user_id == 2) /**< User 2 */
            usrs[EID::USER_2].push_back(CAlarm(timestamp, testType));
        else if (user_id == 3) /**< User 3 */
            usrs[EID::USER_3].push_back(CAlarm(timestamp, testType));
        cmd.erase(0, pos + delimiter.length()); /** Erase the token */
    }
    count = 0;

    /**< For all users */
    for (auto i : usrs)
    {
        /**< If the corresponding user has pending alarms */
        if (!i.empty())
        {
            /**< Fill the sex field */
            if (usersInfo[count].sex == 0) /**< If the user is male */
                sex = "Mr. ";
            else /**< If the user is female */
                sex = "Ms. ";

            description = "";
            /**< For all the pending alarms */
            for (CAlarm j : i)
            {
                /**< Extract the alarm Timestamp */
                timestamp = j.getTimestamp();
                int month = int(timestamp / 10000);
                int day = int(timestamp / 100) % 100;
                int hour = int(timestamp % 100);

                /**< Update the description */
                if (j.getTestType() == "T")
                    testType = "Temperature";
                else if (j.getTestType() == "O")
                    testType = "Oxygen Saturation";
                else if (j.getTestType() == "H")
                    testType = "Heartbeat Rate";
                description += testType + " Test at " + std::to_string(month) + "/" + std::to_string(day) + " at " + std::to_string(hour) + "h\n";
            }

            /**< Fill the description field */
            description = "Hi " + sex + usersInfo[count].name + ", don't forget that you shedule:\n" + description;

            /**< Prepare the Email */
            out = "echo \"" + description + "\" | mutt -s \"" + title + "\" " + usersInfo[count].email_user;

            /**< Send the Email */
            system(out.c_str());
        }
        /**< Increment the counter */
        count++;
    }
}

/**
 * @brief Timer Callback
 * @param signo specifies the signal type
 */
static void TimCallback(int signo)
{
    if (signo == SIGALRM) /**< Only the signal matters */
    {
        pthread_mutex_lock(&cond_mutex_alarm);
        isTimeToCheckAlarm = 1;
        pthread_cond_signal(&cond_alarm);
        pthread_mutex_unlock(&cond_mutex_alarm);
    }
}

/**
 * @brief USB Signal Handler
 * @param sig specifies the signal type
 * @param siginfo specifies the signal information
 * @param context specifies the signal context
 */
void USBSignalHandler(int sig, siginfo_t *siginfo, void *context)
{
    usbStatus = (bool)siginfo->si_value.sival_int;
}

/**
 * @brief Check Internet Connection
 * @return true if there is internet connection
 * @return false if there is no internet connection
 */
bool checkInternetConnection()
{
    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    /**< Create a socket point */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) /**< If the socket creation fails */
        return false;
    server = gethostbyname("www.google.com"); /**< Get the host name */
    if (server == NULL)
        return false;

    bzero((char *)&serv_addr, sizeof(serv_addr));                                        /**< Initialize the socket structure */
    serv_addr.sin_family = AF_INET;                                                      /**< Set the socket type */
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length); /**< Set the IP address */
    serv_addr.sin_port = htons(80);                                                      /**< Set the port number */

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) /**< Connect to the server */
        return false;                                                          /**< If the connection fails */

    close(sockfd); /**< Close the socket */
    return true;   /**< If the connection succeeds */
}

/**
 * @brief Main thread
 * @return int
 */
int main()
{

    int err[THREADS_NUM - 2];
    pthread_t thread[THREADS_NUM - 2];

    pthread_attr_t thread_attr;
    struct sched_param thread_param;
    int thread_policy;

    event_t event;

    pthread_attr_init(&thread_attr);
    pthread_attr_getschedpolicy(&thread_attr, &thread_policy);
    pthread_attr_getschedparam(&thread_attr, &thread_param);

    printf(
        "Default policy is %s, priority is %d\n",
        (thread_policy == SCHED_FIFO ? "FIFO"
                                     : (thread_policy == SCHED_RR ? "RR"
                                                                  : (thread_policy == SCHED_OTHER ? "OTHER"
                                                                                                  : "unknown"))),
        thread_param.sched_priority);

    /**************************************************/
    myApp->getUsers().setCurrentUser(EID::USER_0);
    /**************************************************/

    /**
     * @brief Create the tDataAcquisition thread
     */
    SetupThread(DATA_ACQUISITION_PRIO, &thread_attr, &thread_param);
    err[THREAD_ID::DATA_ACQUISITION] = pthread_create(&thread[THREAD_ID::DATA_ACQUISITION], &thread_attr, tDataAcquisition, NULL);

    /**
     * @brief Create the tAlarm thread
     */
    SetupThread(ALARM_PRIO, &thread_attr, &thread_param);
    err[THREAD_ID::ALARM] = pthread_create(&thread[THREAD_ID::ALARM], &thread_attr, tAlarm, NULL);

    /**
     * @brief Create the tExport thread
     */
    SetupThread(EXPORT_PRIO, &thread_attr, &thread_param);
    err[THREAD_ID::EXPORT] = pthread_create(&thread[THREAD_ID::EXPORT], &thread_attr, tExport, NULL);

    /**
     * @brief Create the tDatabaseManager thread
     */
    SetupThread(DATABASE_MANAGER_PRIO, &thread_attr, &thread_param);
    err[THREAD_ID::DATABASE_MANAGER] = pthread_create(&thread[THREAD_ID::DATABASE_MANAGER], &thread_attr, tDatabaseManager, NULL);

    /**
     * @brief Create the tReceiveFromGUI thread
     */
    SetupThread(RECEIVE_FROM_GUI_PRIO, &thread_attr, &thread_param);
    err[THREAD_ID::RECEIVE_FROM_GUI] = pthread_create(&thread[THREAD_ID::RECEIVE_FROM_GUI], &thread_attr, tReceiveFromGUI, NULL);

    /**
     * @brief Create the tSendToGUI thread
     */
    SetupThread(SEND_TO_GUI_PRIO, &thread_attr, &thread_param);
    err[THREAD_ID::SEND_TO_GUI] = pthread_create(&thread[THREAD_ID::SEND_TO_GUI], &thread_attr, tSendToGUI, NULL);

    /**
     * @brief Check if an error occured
     */
    for (int i = 0; i < THREADS_NUM - 2; i++)
        CheckFail(err[i]);

    /*************************************************************************************************/
    /**< Just to ensure that tDatabaseManager is ready */
    sleep(2);

    /**< Import the Users from the Database */
    event.payload = "U";
    event.request_type.push_back({THREAD_ID::MAIN, OPERATIONS::DB_READ});
    event.request_type.push_back({THREAD_ID::DATABASE_MANAGER, OPERATIONS::DB_READ});
    myApp->getFSM().post(event, event.request_type.back().thread_id);

    while (myApp->getFSM().empty(THREAD_ID::MAIN))
        ;

    event = myApp->getFSM().front(THREAD_ID::MAIN);
    myApp->getFSM().pop(THREAD_ID::MAIN);

    if (event.ack == ACK::ERROR)
        std::cout << "ERROR: Import Users from the Database at [" << __func__ << "]" << std::endl;
    else
        myApp->getUsers().insertFromDB(event.payload);

    /**< Import the Alarms from the Database */
    event.payload = "A";
    event.request_type.push_back({THREAD_ID::MAIN, OPERATIONS::DB_READ});
    event.request_type.push_back({THREAD_ID::DATABASE_MANAGER, OPERATIONS::DB_READ});
    myApp->getFSM().post(event, event.request_type.back().thread_id);

    while (myApp->getFSM().empty(THREAD_ID::MAIN))
        ;

    event = myApp->getFSM().front(THREAD_ID::MAIN);
    myApp->getFSM().pop(THREAD_ID::MAIN);

    if (event.ack == ACK::ERROR)
        std::cout << "ERROR: Import Alarms from the Database at [" << __func__ << "]" << std::endl;
    else
        myApp->getUsers().insertAlarmsFromDB(event.payload);

    /**< Print all the Users Information */
    myApp->getUsers().print();

    /*************************************************************************************************/

    /**< Program the Timer to check the periodically Alarms*/
    struct itimerval itv;
    signal(SIGALRM, TimCallback); /**< Define the Signal Callback */
    itv.it_interval.tv_sec = 60;  /**< 60 sec */
    itv.it_interval.tv_usec = 0;
    itv.it_value.tv_sec = 60; /**< Period between now and the first interrupt */
    itv.it_value.tv_usec = 0;
    setitimer(ITIMER_REAL, &itv, NULL); /**< Start the Timer */

    /**< Set the USB Signal Handler */
    struct sigaction act;
    act.sa_sigaction = &USBSignalHandler;
    act.sa_flags = SA_SIGINFO;
    if (sigaction(SIGUSR1, &act, NULL) != 0)
    {
        std::cout << "Error" << std::endl;
        exit(1);
    }

    /*************************************************************************************************/

    /**
     * @brief Join
     */
    pthread_join(thread[THREAD_ID::DATA_ACQUISITION], NULL);
    pthread_join(thread[THREAD_ID::ALARM], NULL);
    pthread_join(thread[THREAD_ID::EXPORT], NULL);
    pthread_join(thread[THREAD_ID::DATABASE_MANAGER], NULL);
    pthread_join(thread[THREAD_ID::RECEIVE_FROM_GUI], NULL);
    pthread_join(thread[THREAD_ID::SEND_TO_GUI], NULL);

    exit(0);
}

void *tDataAcquisition(void *ptr)
{
    event_t event;
    bool RUN = 1;
    CSensors *sensors; /**< Sensors Object */
    float temp;
    int heartRate, oxygen;
    std::string aux;
    /**< Check the policy and the priority */
    CheckPolicyPrio(pthread_self(), __func__);

    /**< Set core affinity */
    SetCoreAffinity(pthread_self(), 0, __func__);

    while (RUN)
    {
        pthread_mutex_lock(&cond_mutex_dataAcquisition);
        while (myApp->getFSM().empty(THREAD_ID::DATA_ACQUISITION))
        {
            pthread_cond_wait(&cond_dataAcquisition, &cond_mutex_dataAcquisition);
        }
        pthread_mutex_unlock(&cond_mutex_dataAcquisition);
        event.request_type.clear();
        event = myApp->getFSM().front(THREAD_ID::DATA_ACQUISITION);

        switch (event.request_type.back().operation)
        {
        case OPERATIONS::EXIT:
            std::cout << "EXIT at [" << __func__ << "]" << std::endl;
            RUN = 0;
            break;
        case OPERATIONS::TEMPERATURE:
            std::cout << "TEMPERATURE_TEST at [" << __func__ << "]" << std::endl;
            sensors = &myApp->getMLX90614(); /**< Select the Sensor */
            temp = sensors->readData();      /**< Read the Data */
            if (temp == -1.0)                /**< Check the Data */
            {
                myApp->getFSM().clear(THREAD_ID::DATABASE_MANAGER);                                /**< Clear the Queue */
                event.payload = std::to_string(ACK::ERROR);                                        /**< Format the Payload */
                event.request_type.push_back({THREAD_ID::SEND_TO_GUI, OPERATIONS::FEEDBACK_TEST}); /**< Send the Feedback to the GUI */
            }
            else /**< Format the Data */
            {
                aux = std::to_string(temp);
                aux.resize(4);
                event.payload = "T " + getCurrentTime() + " " + aux + "°C"; /**< Format the Timestamp and Data */
            }
            myApp->getBuzzer().beep(500); /**< Beep the Buzzer */
            break;
        case OPERATIONS::HEARTBEAT_RATE:
            std::cout << "HEARTBEAT_RATE_TEST at [" << __func__ << "]" << std::endl;
            sensors = &myApp->getMAX30102();                      /**< Select the Sensor */
            sensors->selectDataToRead(MAX30102EData::HEART_RATE); /**< Select the Data to Read */
            heartRate = sensors->readData();                      /**< Read the Data */
            if (heartRate == -1.0)                                /**< Check the Data */
            {
                myApp->getFSM().clear(THREAD_ID::DATABASE_MANAGER);                                /**< Clear the Queue */
                event.payload = std::to_string(ACK::ERROR);                                        /**< Format the Payload */
                event.request_type.push_back({THREAD_ID::SEND_TO_GUI, OPERATIONS::FEEDBACK_TEST}); /**< Send the Feedback to the GUI */
            }
            else
                event.payload = "H " + getCurrentTime() + " " + std::to_string(heartRate) + "bpm"; /**< Format the Timestamp and Data */
            myApp->getBuzzer().beep(500);                                                          /**< Beep the Buzzer */
            break;
        case OPERATIONS::OXYGEN:
            std::cout << "OXYGEN_TEST at [" << __func__ << "]" << std::endl;
            sensors = &myApp->getMAX30102();                /**< Select the Sensor */
            sensors->selectDataToRead(MAX30102EData::SPO2); /**< Select the Data to Read */
            oxygen = sensors->readData();                   /**< Read the Data */
            if (oxygen == -1.0)
            {
                myApp->getFSM().clear(THREAD_ID::DATABASE_MANAGER);                                /**< Clear the Queue */
                event.payload = std::to_string(ACK::ERROR);                                        /**< Format the Payload */
                event.request_type.push_back({THREAD_ID::SEND_TO_GUI, OPERATIONS::FEEDBACK_TEST}); /**< Send the Feedback to the GUI */
            }
            else
                event.payload = "O " + getCurrentTime() + " " + std::to_string(oxygen) + "%"; /**< Format the Timestamp and Data */
            myApp->getBuzzer().beep(500);                                                     /**< Beep the Buzzer */
            break;
        default:
            std::cout << "ERROR: Default at [" << __func__ << "]" << std::endl;
            break;
        }

        if (event.request_type.size() > 1) /* If exist more operations to do */
        {
            event.request_type = myApp->getFSM().next(THREAD_ID::DATA_ACQUISITION); /* Next Jump */

            myApp->getFSM().pop(THREAD_ID::DATA_ACQUISITION);

            myApp->getFSM().post(event, event.request_type.back().thread_id);
        }

        else
        {
            myApp->getFSM().pop(THREAD_ID::DATA_ACQUISITION);
        }
    }
}

void *tAlarm(void *ptr)
{
    /**< Variables declaration */
    event_t event;
    uint32_t actualTimestamp;
    std::vector<struct SUserAlarm> usersAlarms;
    bool RUN = 1;

    /**< Check the policy and the priority */
    CheckPolicyPrio(pthread_self(), __func__);

    /**< Set core affinity */
    SetCoreAffinity(pthread_self(), 1, __func__);

    while (RUN)
    {
        pthread_mutex_lock(&cond_mutex_alarm);
        while (!isTimeToCheckAlarm)
        {
            pthread_cond_wait(&cond_alarm, &cond_mutex_alarm);
        }
        pthread_mutex_unlock(&cond_mutex_alarm);
        event.request_type.clear();
        /**< Extract the current time */
        system("/etc/init.d/S49ntp reload");
        auto time = std::chrono::system_clock::now();
        std::time_t tt = std::chrono::system_clock::to_time_t(time);
        tm utc_tm = *gmtime(&tt);
        tm local_tm = *localtime(&tt);
        local_tm.tm_mon += 1;

        /**< Convert into a timestamp */
        actualTimestamp = local_tm.tm_mon * 10000 + local_tm.tm_mday * 100 + local_tm.tm_hour;

        /** Get all the Users Alarms between a window of 1h */
        usersAlarms = myApp->getUsers().getAlarms(actualTimestamp, actualTimestamp + 1);

        /**< If the Users have at least one alarm in the system on a 1h window from now */
        if (!usersAlarms.empty())
        {
            /**< Clear the payload field */
            event.payload = "";

            /**< Update the Payload */
            for (auto it = usersAlarms.begin(); it != usersAlarms.end(); it++)
                event.payload += std::to_string((int)(it->userID)) + " " + std::to_string((int)(it->timestamp)) + " " + it->testType + "\n";

            /**< Delete the Alarms from Database */
            event.request_type.push_back({THREAD_ID::DATABASE_MANAGER, OPERATIONS::DB_DELETE}); // # 2

            /**< Export */
            event.request_type.push_back({THREAD_ID::EXPORT, OPERATIONS::ALARM_EMAIL}); // # 1

            /**< Post the Event */
            myApp->getFSM().post(event, event.request_type.back().thread_id);
        }

        /**< Update the alarm flag */
        isTimeToCheckAlarm = 0;
    }
}

void *tExport(void *ptr)
{
    event_t event;
    bool RUN = 1;
    std::string delimiter = "\n";
    std::string testType, token, payload, payload2, fileName;
    int timestamp, user_id;
    std::string partitionFolder;
    DIR *dh;
    struct dirent *contents;
    size_t pos = 0;
    int deleteAlarmsDB = 0;

    /**< Check the policy and the priority */
    CheckPolicyPrio(pthread_self(), __func__);

    /**< Set core affinity */
    SetCoreAffinity(pthread_self(), 1, __func__);

    while (RUN)
    {
        pthread_mutex_lock(&cond_mutex_export);
        while (myApp->getFSM().empty(THREAD_ID::EXPORT))
        {
            pthread_cond_wait(&cond_export, &cond_mutex_export);
        }
        pthread_mutex_unlock(&cond_mutex_export);
        event.request_type.clear();
        event = myApp->getFSM().front(THREAD_ID::EXPORT);
        switch (event.request_type.back().operation)
        {
        case OPERATIONS::EXIT:
            std::cout << "EXIT at [" << __func__ << "]" << std::endl;
            RUN = 0;
            break;
        case OPERATIONS::ALARM_EMAIL:
            std::cout << "ALARM_EMAIL at [" << __func__ << "]" << std::endl;
            payload = "A ";   /**< For Database */
            payload2.clear(); /**< For RAM */

            /**< Parse the command received  */
            while ((pos = event.payload.find(delimiter)) != std::string::npos)
            {
                token = event.payload.substr(0, pos);   /**< Get the token */
                std::stringstream ss(token);            /** Convert to stringstream to process */
                ss >> user_id >> timestamp >> testType; /** Update the fields */
                payload2 += std::to_string(user_id) + " " + std::to_string(timestamp) + " " + testType + "\n";

                /**< Verify if not exist the timestamp */
                if (payload.find(std::to_string(timestamp)) == std::string::npos)
                    payload += std::to_string(timestamp) + "\n";

                event.payload.erase(0, pos + delimiter.length()); /** Erase the token */
            }
            event.payload = payload;

            /**< Send the Alarm Email */
            if(checkInternetConnection())
                sendAlarmEmail(payload2);

            /**< If it is necessary to delete the alarms from RAM */
            if (!payload2.empty())
                myApp->getUsers().removeAlarmsFromString(payload2);

            /**< If it is necessary to delete the alarms from Database */
            if (event.payload != "A ")
                deleteAlarmsDB = 1;
            else
                deleteAlarmsDB = 0;

            break;
        case OPERATIONS::USER_EMAIL:
            std::cout << "USER_EMAIL at [" << __func__ << "]" << std::endl;
            if (event.payload.size() > 2)
            {
                if (!checkInternetConnection())
                    event.payload = "Error: No Internet Connection";
                else
                {
                    fileName = downloadAsCSV(event.payload.substr(2));
                    event.payload = "Exported to User Email";
                    sendRegularEmail(0, fileName);
                }
            }
            else
                event.payload = "Info: No measurements to export";
            break;
        case OPERATIONS::DOCTOR_EMAIL:
            std::cout << "DOCTOR_EMAIL at [" << __func__ << "]" << std::endl;
            if (event.payload.size() > 2)
            {
                if (!checkInternetConnection())
                    event.payload = "Error: No Internet Connection";
                else
                {
                    fileName = downloadAsCSV(event.payload.substr(2));
                    event.payload = "Exported to Doctor Email";
                    sendRegularEmail(1, fileName);
                }
            }
            else
                event.payload = "Info: No measurements to export";
            break;
        case OPERATIONS::USB_DOWNLOAD:
            std::cout << "USB_DOWNLOAD at [" << __func__ << "]" << std::endl;
            if (event.payload.size() > 2)
            {
                if (usbStatus)
                {
                    partitionFolder.clear();
                    dh = opendir("/media/usb");
                    while ((contents = readdir(dh)))
                    {
                        partitionFolder = contents->d_name;
                        if (partitionFolder != "." && partitionFolder != "..")
                        {
                            partitionFolder = "/media/usb/" + partitionFolder;
                            break;
                        }
                    }
                    closedir(dh);
                    if (partitionFolder.empty())
                        event.payload = "Error: USB doesn't have partitions";
                    else
                    {
                        fileName = downloadAsCSV(event.payload.substr(2));
                        event.payload = "Exported to USB";
                        system(("mv " + fileName + " " + partitionFolder + "/").c_str());
                        system(("sync -d " + partitionFolder + fileName).c_str());
                    }
                }
                else
                    event.payload = "Error: USB not connected";
            }
            else
                event.payload = "Info: No measurements to export";
            break;
        default:
            std::cout << "ERROR: Default at [" << __func__ << "]" << std::endl;
            break;
        }
        system("rm /*.csv");
        if (event.request_type.size() > 1) /* If exist more operations to do */
        {
            /**< If the operation is ALARM_EMAIL and is not necessary to delete any alarm ==> Pop the 2 events */
            if (event.request_type.back().operation == OPERATIONS::ALARM_EMAIL && !deleteAlarmsDB)
            {
                myApp->getFSM().clear(THREAD_ID::EXPORT);
            }
            else
            {
                event.request_type = myApp->getFSM().next(THREAD_ID::EXPORT); /* Next Jump */

                myApp->getFSM().pop(THREAD_ID::EXPORT);

                myApp->getFSM().post(event, event.request_type.back().thread_id);
            }
        }
        else
        {
            myApp->getFSM().pop(THREAD_ID::EXPORT);
        }
    }
}

void *tDatabaseManager(void *ptr)
{
    event_t event;
    std::string out;
    char msg[MAX_MSG_LEN];
    bool RUN = 1;

    /**< Create a object DataFormat */
    CDataFormat *df;

    /**< Create a object to help to manage the Message Queue protocol */
    CToDB toDB;

    /**< Assign the DataFormat as a toDB protocol */
    df = &toDB;

    /**< Create the toDB handler with the WRITE_ONLY flag */
    CMessageQueue mq_toDB(MSGQ_TO_DB, O_WRONLY | O_CREAT, S_IRWXU | S_IRWXG);

    /**< Create the fromDB handler with the READ_ONLY flag */
    CMessageQueue mq_fromDB(MSGQ_FROM_DB, O_RDONLY | O_CREAT, S_IRWXU | S_IRWXG);

    /**< Check the policy and the priority */
    CheckPolicyPrio(pthread_self(), __func__);

    /**< Set core affinity */
    SetCoreAffinity(pthread_self(), 1, __func__);

    /** Verify if the toDB open id fine */
    if (mq_toDB.open() == -1)
    {
        std::cout << "ERROR: toDB cannot open at [" << __func__ << "]" << std::endl;
        exit(1);
    }

    /** Verify if the fromDB open id fine */
    if (mq_fromDB.open() == -1)
    {
        std::cout << "ERROR: fromDB cannot open at [" << __func__ << "]" << std::endl;
        exit(1);
    }

    while (RUN)
    {
        pthread_mutex_lock(&cond_mutex_dbManager);
        while (myApp->getFSM().empty(THREAD_ID::DATABASE_MANAGER))
        {
            pthread_cond_wait(&cond_dbManager, &cond_mutex_dbManager);
        }
        pthread_mutex_unlock(&cond_mutex_dbManager);

        event.request_type.clear();
        event = myApp->getFSM().front(THREAD_ID::DATABASE_MANAGER);

        switch (event.request_type.back().operation)
        {
        case OPERATIONS::EXIT:
            std::cout << "EXIT at [" << __func__ << "]" << std::endl;
            mq_toDB.close();
            mq_fromDB.close();
            RUN = 0;
            break;
        default:
            std::cout << "DB operation at [" << __func__ << "]" << std::endl;
            /**< If it is a READ, WRITE or DELETE operation ==> Encode the Event into a command to send it to the Database */
            out = df->encode(static_cast<void *>(&event));

            /**< Convert into an array */
            snprintf(msg, MAX_MSG_LEN, out.c_str());

            /**< Send the command to Database Daemon */
            if (mq_toDB.send(msg) != 0)
                std::cout << "ERROR: Send via toDB at [" << __func__ << "]" << std::endl;

            /**< Wait for Database Daemon response */
            if (mq_fromDB.receive(msg) == -1)
                std::cout << "ERROR: Receive at [" << __func__ << "]" << std::endl;

            /**< Extract the command received */
            out = msg;

            /**< Fill the ACK flag */
            event.ack = (ack_t)(msg[0] - 48);

            /**< Fill the payload if is necessary */
            if (out.length() > 2)
                event.payload = out.substr(2);

            break;
        }

        if (event.request_type.size() > 1) /* If exist more operations to do */
        {
            event.ack = ACK::SUCCESS;

            event.request_type = myApp->getFSM().next(THREAD_ID::DATABASE_MANAGER); /* Next Jump */

            myApp->getFSM().pop(THREAD_ID::DATABASE_MANAGER);

            myApp->getFSM().post(event, event.request_type.back().thread_id); /* Post the new event */
        }

        else
        {
            myApp->getFSM().pop(THREAD_ID::DATABASE_MANAGER);
        }
    }
}

void *tReceiveFromGUI(void *ptr)
{
    char msgcontent[MAX_MSG_LEN];
    event_t event;
    int id;
    struct SUSER info;
    uint32_t timestamp;
    std::string testType , wifiSSID, wifiPassword, wifiTime;
    char c;
    std::stringstream ss;

    /**< Create the fromGUI handler with the READ_ONLY flag */
    CMessageQueue mq_fromGUI(MSGQ_FROM_GUI, O_RDONLY | O_CREAT, S_IRWXU | S_IRWXG);

    /** Verify if the fromGUI can open */
    if (mq_fromGUI.open() == -1)
    {
        std::cout << "ERROR: fromGUI cannot open" << std::endl;
        exit(1);
    }

    /**< Check the policy and the priority */
    CheckPolicyPrio(pthread_self(), __func__);

    /**< Set core affinity */
    SetCoreAffinity(pthread_self(), 1, __func__);

    for (;;)
    {
        /**< Wait to receive a message from the FrontEnd (fromGUI Message Queue) */
        if (mq_fromGUI.receive(msgcontent) == -1)
        {
            std::cout << "ERROR: Receive" << std::endl;
            exit(1);
        }

        /* Clear the Events Requests to prepare the nexts Requests */
        event.request_type.clear();
        switch (msgcontent[0])
        {
        case 'N': /**< Change/Select User */
            std::cout << "Change/Select User option at [" << __func__ << "]" << std::endl;

            /**< Extract the user ID */
            id = msgcontent[2] - 48;

            /**< Update the current user ID */
            myApp->getUsers().setCurrentUser(EID(id));

            /**< If the User doesn't exist */
            if (myApp->getUsers().isEmpty(id))
                event.ack = ACK::ERROR;

            /**< If the Users already exist */
            else
                event.ack = ACK::SUCCESS;

            event.request_type.push_back({THREAD_ID::SEND_TO_GUI, OPERATIONS::FEEDBACK_CHANGE_PROFILE});
            myApp->getFSM().post(event, event.request_type.back().thread_id);
            break;

        case 'D': /**< Delete current Profile */
            std::cout << "Delete current Profile option at [" << __func__ << "]" << std::endl;
            event.payload = "U";
            event.request_type.push_back({THREAD_ID::SEND_TO_GUI, OPERATIONS::FEEDBACK_USERS_NAMES});
            event.request_type.push_back({THREAD_ID::SEND_TO_GUI, OPERATIONS::FEEDBACK_DELETE_PROFILE});
            event.request_type.push_back({THREAD_ID::DATABASE_MANAGER, OPERATIONS::DB_DELETE});
            myApp->getFSM().post(event, event.request_type.back().thread_id);
            break;

        case 'C': /**< Create Profile */
            std::cout << "Update Profile option at [" << __func__ << "]" << std::endl;
            event.payload = msgcontent;
            ss.clear();
            ss.str(event.payload);
            ss >> c >> info.name >> info.sex >> info.age >> info.height >> info.weight >> info.email_user >> info.email_doctor >> info.activity_level;
            myApp->getUsers().insert(info, myApp->getUsers().getCurrentUser());
            event.request_type.push_back({THREAD_ID::DATABASE_MANAGER, OPERATIONS::DB_WRITE});
            myApp->getFSM().post(event, event.request_type.back().thread_id);
            break;

        case 'S': /**< Consult Sensors Measuremnts */
            std::cout << "Consult Sensors Measuremnts option at [" << __func__ << "]" << std::endl;
            event.payload = "S";
            event.request_type.push_back({THREAD_ID::SEND_TO_GUI, OPERATIONS::FEEDBACK_CONSULT}); // #2
            event.request_type.push_back({THREAD_ID::DATABASE_MANAGER, OPERATIONS::DB_READ});     // #1
            myApp->getFSM().post(event, event.request_type.back().thread_id);
            break;

        case 'R': /**< Do a Test */
            std::cout << "Do a Test option at [" << __func__ << "]" << std::endl;
            event.request_type.push_back({THREAD_ID::SEND_TO_GUI, OPERATIONS::FEEDBACK_TEST}); // #3
            event.request_type.push_back({THREAD_ID::DATABASE_MANAGER, OPERATIONS::DB_WRITE}); // #2
            switch (msgcontent[2])
            {
            case 'T':
                event.request_type.push_back({THREAD_ID::DATA_ACQUISITION, OPERATIONS::TEMPERATURE}); // #1
                break;
            case 'O':
                event.request_type.push_back({THREAD_ID::DATA_ACQUISITION, OPERATIONS::OXYGEN}); // #1
                break;
            case 'H':
                event.request_type.push_back({THREAD_ID::DATA_ACQUISITION, OPERATIONS::HEARTBEAT_RATE}); // #1
                break;
            default:
                break;
            }
            myApp->getFSM().post(event, event.request_type.back().thread_id);
            break;

        case 'E': /**< Export the Measurements */
            std::cout << "Export the Measurments option at [" << __func__ << "]" << std::endl;
            event.request_type.push_back({THREAD_ID::SEND_TO_GUI, OPERATIONS::FEEDBACK_EXPORT}); // #3
            switch (msgcontent[2])
            {
            case 'U':
                event.request_type.push_back({THREAD_ID::EXPORT, OPERATIONS::USER_EMAIL}); // #2
                break;
            case 'D':
                event.request_type.push_back({THREAD_ID::EXPORT, OPERATIONS::DOCTOR_EMAIL}); // #2
                break;
            case 'X':
                event.request_type.push_back({THREAD_ID::EXPORT, OPERATIONS::USB_DOWNLOAD}); // #2
                break;
            default:
                break;
            }
            event.payload = "S";
            event.request_type.push_back({THREAD_ID::DATABASE_MANAGER, OPERATIONS::DB_READ}); // #1
            myApp->getFSM().post(event, event.request_type.back().thread_id);
            break;

        case 'A': /**< Alarm introduced */
            std::cout << "Alarm introduced option at [" << __func__ << "]" << std::endl;
            event.payload = msgcontent;
            ss.clear();
            ss.str(event.payload);
            ss >> c >> testType >> timestamp;
            myApp->getUsers().insertAlarm(CAlarm(timestamp, testType), myApp->getUsers().getCurrentUser());
            event.request_type.push_back({THREAD_ID::SEND_TO_GUI, OPERATIONS::FEEDBACK_ALARMS});
            event.request_type.push_back({THREAD_ID::DATABASE_MANAGER, OPERATIONS::DB_WRITE});
            myApp->getFSM().post(event, event.request_type.back().thread_id);
            break;
        case 'M': /**< User names requested */
            std::cout << "User names requested option at [" << __func__ << "]" << std::endl;
            event.request_type.push_back({THREAD_ID::SEND_TO_GUI, OPERATIONS::FEEDBACK_USERS_NAMES});
            myApp->getFSM().post(event, event.request_type.back().thread_id);
            break;
        case 'I': /**< User info requested */
            std::cout << "User info requested option at [" << __func__ << "]" << std::endl;
            info = myApp->getUsers().getInfo();
            event.payload = info.name + " " + std::to_string(info.sex) + " " + std::to_string(info.age) + " " + std::to_string(info.height) + " " + std::to_string(info.weight) + " " + info.email_user + " " + info.email_doctor + " " + std::to_string(info.activity_level);
            event.request_type.push_back({THREAD_ID::SEND_TO_GUI, OPERATIONS::FEEDBACK_USER_DATA});
            myApp->getFSM().post(event, event.request_type.back().thread_id);
            break;
        case 'U': /**< Update user information*/
            std::cout << "Update user information option at [" << __func__ << "]" << std::endl;
            event.payload = msgcontent;
            ss.clear();
            ss.str(event.payload);
            ss >> c >> info.name >> info.sex >> info.age >> info.height >> info.weight >> info.email_user >> info.email_doctor >> info.activity_level;
            myApp->getUsers().insert(info, myApp->getUsers().getCurrentUser());
            event.request_type.push_back({THREAD_ID::DATABASE_MANAGER, OPERATIONS::DB_UPDATE});
            myApp->getFSM().post(event, event.request_type.back().thread_id);
        case 'T': /**< Get current user alarms*/
            std::cout << "Get current user alarms option at [" << __func__ << "]" << std::endl;
            event.request_type.push_back({THREAD_ID::SEND_TO_GUI, OPERATIONS::FEEDBACK_ALARMS});
            myApp->getFSM().post(event, event.request_type.back().thread_id);
            break;
        case 'W': /**< Wifi credentials and time*/
            std::cout << "Wifi credentials and time option at [" << __func__ << "]" << std::endl;
            event.payload = msgcontent;
            ss.clear();
            ss.str(event.payload);
            ss >> c >> wifiSSID >> wifiPassword >> wifiTime;
            std::cout << event.payload << std::endl;
            system(("date +%Y%m%d%H%M -s \"" + wifiTime + "\"").c_str());
            system("wpa_cli terminate -i wlan0");
            system("echo 'ctrl_interface=/var/run/wpa_supplicant\nap_scan=1\n' > /etc/wpa_supplicant.conf");
            system(("wpa_passphrase " + wifiSSID + " " + wifiPassword + " >> /etc/wpa_supplicant.conf").c_str());
            system(("wpa_supplicant -B -i wlan0 -c <(wpa_passphrase " + wifiSSID + " " + wifiPassword + ")").c_str());
            break;
        default:
            break;
        }
    }

    /**< Close the Queue */
    mq_fromGUI.close();
}

void *tSendToGUI(void *ptr)
{
    event_t event;
    std::string aux;
    std::vector<struct SUSER> usersInfo;
    std::vector<std::string> names;
    std::string alarms;
    std::vector<struct SUserAlarm> userAlarms;
    EID cuser;
    char msgcontent[MAX_MSG_LEN];
    bool RUN = 1;

    /**< Create the fromGUI handler with the WRITE_ONLY flag */
    CMessageQueue mq_toGUI(MSGQ_TO_GUI, O_WRONLY | O_CREAT, S_IRWXU | S_IRWXG);

    /** Verify if the toGUI can open */
    if (mq_toGUI.open() == -1)
    {
        std::cout << "ERROR: toGUI cannot open at [" << __func__ << "]" << std::endl;
        exit(1);
    }

    /**< Check the policy and the priority */
    CheckPolicyPrio(pthread_self(), __func__);

    /**< Set core affinity */
    SetCoreAffinity(pthread_self(), 1, __func__);

    while (RUN)
    {
        pthread_mutex_lock(&cond_mutex_sendToGUI);
        while (myApp->getFSM().empty(THREAD_ID::SEND_TO_GUI))
        {
            pthread_cond_wait(&cond_sendToGUI, &cond_mutex_sendToGUI);
        }
        pthread_mutex_unlock(&cond_mutex_sendToGUI);
        event.request_type.clear();
        event = myApp->getFSM().front(THREAD_ID::SEND_TO_GUI);

        switch (event.request_type.back().operation)
        {
        case OPERATIONS::EXIT:
            std::cout << "EXIT at [" << __func__ << "]" << std::endl;
            mq_toGUI.close();
            RUN = 0;
            break;
        case OPERATIONS::FEEDBACK_CHANGE_PROFILE:
            std::cout << "FEEDBACK_CHANGE_PROFILE at [" << __func__ << "]" << std::endl;
            aux = "N " + std::to_string(event.ack);
            break;
        case OPERATIONS::FEEDBACK_CONSULT:
            std::cout << "FEEDBACK_CONSULT at [" << __func__ << "]" << std::endl;
            aux = "S " + event.payload;
            break;
        case OPERATIONS::FEEDBACK_EXPORT:
            std::cout << "FEEDBACK_EXPORT at [" << __func__ << "]" << std::endl;
            aux = "E " + event.payload;
            break;
        case OPERATIONS::FEEDBACK_TEST:
            std::cout << "FEEDBACK_TEST at [" << __func__ << "]" << std::endl;
            aux = "R " + event.payload;
            break;
        case OPERATIONS::FEEDBACK_DELETE_PROFILE:
            std::cout << "FEEDBACK_DELETE_PROFILE at [" << __func__ << "]" << std::endl;
            myApp->getUsers().remove();
            aux = "D " + event.payload;
            break;
        case OPERATIONS::FEEDBACK_USERS_NAMES:
            std::cout << "FEEDBACK_USERS_NAMES at [" << __func__ << "]" << std::endl;
            usersInfo.clear();
            names.clear();
            usersInfo = myApp->getUsers().getAllInfo(); /**< Get users info*/
            for (int i = 0; i < usersInfo.size(); i++)
            {
                if (usersInfo[i].name.empty()) /**< If the user doesn't exist, fill with "User_i" */
                    names.push_back("User_" + std::to_string(i + 1));
                else
                    names.push_back(usersInfo[i].name);
            }
            aux = "M " + names[0] + " " + names[1] + " " + names[2] + " " + names[3];
            ;
            break;
        case OPERATIONS::FEEDBACK_USER_DATA:
            std::cout << "FEEDBACK_USERS_NAMES at [" << __func__ << "]" << std::endl;
            aux = "I " + event.payload;
            break;
        case OPERATIONS::FEEDBACK_ALARMS:
            std::cout << "FEEDBACK_ALARMS at [" << __func__ << "]" << std::endl;
            userAlarms.clear();
            alarms.clear();
            userAlarms = myApp->getUsers().getAlarms(0,999999);
            cuser = myApp->getUsers().getCurrentUser();
            for (auto &alarm : userAlarms)
            {
                if (alarm.userID == cuser)
                    alarms = alarms + alarm.testType + " " + std::to_string(alarm.timestamp) + "\n";
            }
            aux = "T " + alarms;
            break;
        default:
            break;
        }

        /**< Fill the message */
        snprintf(msgcontent, MAX_MSG_LEN, aux.c_str());

        /**< Send the message to FrontEnd through 'toGUI' Message Queue */
        if (mq_toGUI.send(msgcontent) != 0)
        {
            std::cout << "ERROR: Send via toGUI at [" << __func__ << "]" << std::endl;
        }

        if (event.request_type.size() > 1) /* If exist more operations to do */
        {
            event.request_type = myApp->getFSM().next(THREAD_ID::SEND_TO_GUI); /* Next Jump */

            myApp->getFSM().pop(THREAD_ID::SEND_TO_GUI);

            myApp->getFSM().post(event, event.request_type.back().thread_id);
        }
        else
        {
            myApp->getFSM().pop(THREAD_ID::SEND_TO_GUI);
        }
    }
}