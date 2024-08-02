#include "CUsers.h"
#include <string.h>
#include <sstream>      /**< std::stringstream */
#include <string>

/**
 * @brief struct a new CUsers object
 */
CUsers::CUsers()
{
    m_users[EID::USER_0].setID(EID::EMPTY);
    m_users[EID::USER_1].setID(EID::EMPTY);
    m_users[EID::USER_2].setID(EID::EMPTY);
    m_users[EID::USER_3].setID(EID::EMPTY);
    m_currentUser = EID::EMPTY;
}

/**
 * @brief Destroy the CUsers object 
 */
CUsers::~CUsers()
{ }

/**
 * @brief Verify if the slot is empty
 * @param slot specifies the slot that will be verified
 * @return true if the slot is empty
 * @return false if the slot is already filled
 */
bool CUsers::isEmpty(int slot)
{
    if (slot > 4 || slot < 0)
        return 0;

    pthread_mutex_lock(&m_mutex);
    EID id = m_users[slot].getID();
    pthread_mutex_unlock(&m_mutex);

    if (id == EID::EMPTY)
        return 1;
    
    return 0;
}

/**
 * @brief Update the current user 
 * @param slot specifies the user slot
 */
void CUsers::update(int slot)
{
    pthread_mutex_lock(&m_mutex);
    m_currentUser = EID(slot);
    pthread_mutex_unlock(&m_mutex);
}

/**
 * @brief Insert a new User
 * @param info specifies the User information
 * @param slot specifies the slot that will be inserted 
 * @return true if the User can be added to the slot
 * @return false if the slot is already filled
 */
bool CUsers::insert(struct SUSER info, int slot)
{  
    pthread_mutex_lock(&m_mutex);
    m_users[slot].setInfo(info);        /**< Update the user information */
    m_users[slot].setID(EID(slot));     /**< Update the ID */
    pthread_mutex_unlock(&m_mutex);

    update(EID(slot));                  /**< Update the current User */

    return 1;
}

/**
 * @brief Insert the users given a pre formatted string
 * @note cmd = "0 Joao 0 180 88 pg50479@alunos.uminho.pt doctor@gmail.com 4\n"
 * @param cmd specifies the string with the users
 * @return true 
 * @return false 
 */
bool CUsers::insertFromDB(std::string cmd)
{
    std::string delimiter = "\n";
    struct SUSER user;
    int user_id;
    size_t pos = 0;
    std::string token;
    while ((pos = cmd.find(delimiter)) != std::string::npos) 
    {
        token = cmd.substr(0, pos);                         /**< Get the token */
        std::stringstream ss(token);                        /** Convert to stringstream to process */
        ss >> user_id >> user.name >> user.sex >> user.age >> user.height >> user.weight >> user.email_user >> user.email_doctor >> user.activity_level;      /** Update the fields */
        insert(user, user_id);                              /** Insert the Alarm */
        cmd.erase(0, pos + delimiter.length());             /** Erase the token */
    }
    return 1;
}

/**
 * @brief Get all the Users Alarms between a lower and upper timestamp boundaries
 * @param lower specifies the lower timestamp boundary
 * @param upper specifies the upper timestamp boundary
 * @return std::vector<struct SUserAlarm>
 */
std::vector<struct SUserAlarm> CUsers::getAlarms(uint32_t lower, uint32_t upper)
{
    std::vector<struct SUserAlarm> userAlarms0;
    std::vector<struct SUserAlarm> userAlarms1;
    std::vector<struct SUserAlarm> userAlarms2;
    std::vector<struct SUserAlarm> userAlarms3;
    std::vector<struct SUserAlarm> usersAlarms;

    /**< Get the User Alarms */
    pthread_mutex_lock(&m_mutex);
    userAlarms0 = m_users[EID::USER_0].getAlarms(lower, upper);
    userAlarms1 = m_users[EID::USER_1].getAlarms(lower, upper);
    userAlarms2 = m_users[EID::USER_2].getAlarms(lower, upper);
    userAlarms3 = m_users[EID::USER_3].getAlarms(lower, upper);
    pthread_mutex_unlock(&m_mutex);

    /**< Push back the valid User 0 alarms */
    for (auto it = userAlarms0.begin(); it != userAlarms0.end(); it++)
    {
        if (it->timestamp != 0)
            usersAlarms.push_back(*it);
    }

    /**< Push back the valid User 1 alarms */
    for (auto it = userAlarms1.begin(); it != userAlarms1.end(); it++)
    {
        if (it->timestamp != 0)
            usersAlarms.push_back(*it);
    }

    /**< Push back the valid User 2 alarms */
    for (auto it = userAlarms2.begin(); it != userAlarms2.end(); it++)
    {
        if (it->timestamp != 0)
            usersAlarms.push_back(*it);
    }

    /**< Push back the valid User 3 alarms */
    for (auto it = userAlarms3.begin(); it != userAlarms3.end(); it++)
    {
        if (it->timestamp != 0)
            usersAlarms.push_back(*it);
    }

    /**< Returns all Users Alarms between the lower and upper limits */
    return usersAlarms;
}

/**
 * @brief Remove the current user from the system
 */
void CUsers::remove()
{
    pthread_mutex_lock(&m_mutex);
    m_users[m_currentUser].setID(EID::EMPTY);
    clean();
    m_currentUser = EID::EMPTY;
    pthread_mutex_unlock(&m_mutex);
}

/**
 * @brief Clean the user personal informations
 */
void CUsers::clean()
{
    m_users[m_currentUser].clean();
}

/**
 * @brief Print all the Users information
 * 
 */
void CUsers::print()
{
    pthread_mutex_lock(&m_mutex);
    for (int i = 0; i < MAX_USERS; i++)
    {
        if (m_users[i].getID() == EID::EMPTY)
            std::cout << "User #" << std::to_string(i) << " does not exist." << std::endl;
        else
            m_users[i].print();
    }
    pthread_mutex_unlock(&m_mutex);
}

/**
 * @brief Get the current user information
 * @return SUSER 
 */
struct SUSER CUsers::getInfo()
{
    return m_users[m_currentUser].getInfo();
}

/**
 * @brief Get the Users information
 * @return std::vector<struct SUSER> 
 */
std::vector<struct SUSER> CUsers::getAllInfo()
{
    std::vector<struct SUSER> usersInfo;

    /**< Extract the Users Information */
    for (int i = 0; i < MAX_USERS; i++)
        usersInfo.push_back(m_users[i].getInfo());

    /**< Return the content */
    return usersInfo;
}

/**
 * @brief Get the current user on the system
 * @return EID 
 */
EID CUsers::getCurrentUser()
{
    return m_currentUser;
}

/**
 * @brief Set the current system user
 * @param user specifies the user
 */
void CUsers::setCurrentUser(EID user)
{
    pthread_mutex_lock(&m_mutex);
    if (user < 4 && user >= 0)
        m_currentUser = user;
    pthread_mutex_unlock(&m_mutex);
}

/**
 * @brief Insert one alarm in one user
 * @param alarm specifies the alarm to be inserted
 * @param usr specifies the user 
 * @return true 
 * @return false 
 */
bool CUsers::insertAlarm(CAlarm alarm, EID usr)
{
    return m_users[(int)usr].insertAlarm(alarm);
}

/**
 * @brief Insert the alarms from Database
 * @param cmd specifies the alarms command
 * @return true 
 * @return false 
 */
bool CUsers::insertAlarmsFromDB(std::string cmd)
{
    /**< cmd = "4 2 Temperature 350\n2 0 Oxygen Saturation 450\n1 0 Temperature 500\n3 1 Heartbeat Rate 680\n" */

    std::string delimiter = "\n";
    std::string testType, token;
    int user_id, alarm_id, date;
    std::vector<CAlarm> usr0;
    std::vector<CAlarm> usr1;
    std::vector<CAlarm> usr2;
    std::vector<CAlarm> usr3;
    size_t pos = 0;

    while ((pos = cmd.find(delimiter)) != std::string::npos) 
    {
        token = cmd.substr(0, pos);                         /**< Get the token */
        std::stringstream ss(token);                        /**< Convert to stringstream to process */
        ss >> alarm_id >> user_id >> testType >> date;      /**< Update the fields */

        if (user_id == 0)                                   /**< User 0 */
            usr0.push_back(CAlarm(date, testType));
        else if (user_id == 1)                              /**< User 1 */
            usr1.push_back(CAlarm(date, testType));
        else if (user_id == 2)                              /**< User 2 */
            usr2.push_back(CAlarm(date, testType));
        else if (user_id == 3)                              /**< User 3 */
            usr3.push_back(CAlarm(date, testType));

        cmd.erase(0, pos + delimiter.length());             /**< Erase the token */
    }

    /**< Insert the User 0 alarms */
    for (CAlarm i : usr0)
        insertAlarm(i, EID::USER_0);
    
    /**< Insert the User 1 alarms */
    for (CAlarm i : usr1)
        insertAlarm(i, EID::USER_1);

    /**< Insert the User 2 alarms */
    for (CAlarm i : usr2)
        insertAlarm(i, EID::USER_2);

    /**< Insert the User 3 alarms */
    for (CAlarm i : usr3)
        insertAlarm(i, EID::USER_3);

    return 1;
}

/**
 * @brief Remove an alarm 
 * @param alarm specifies the alarm to be removed
 * @return true 
 * @return false 
 */
bool CUsers::removeAlarm(CAlarm alarm, EID usr)
{
    return m_users[(int)usr].removeAlarm(alarm);
}

/**
 * @brief Remove the alarms given a pre formatted string
 * @param cmd specifies the string with the alarms
 * @return true 
 * @return false 
 */
bool CUsers::removeAlarmsFromString(std::string cmd)
{
    /**< cmd = "0 121109\n1 121110\n" */

    std::string delimiter = "\n";
    std::string token, testType;
    int date, user_id;
    std::vector<CAlarm> usr0;
    std::vector<CAlarm> usr1;
    std::vector<CAlarm> usr2;
    std::vector<CAlarm> usr3;
    size_t pos = 0;

    while ((pos = cmd.find(delimiter)) != std::string::npos) 
    {
        token = cmd.substr(0, pos);                         /**< Get the token */
        std::stringstream ss(token);                        /**< Convert to stringstream to process */
        ss >> user_id >> date >> testType;                  /**< Update the fields */

        if (user_id == 0)                                   /**< User 0 */
            usr0.push_back(CAlarm(date, testType));
        else if (user_id == 1)                              /**< User 1 */
            usr1.push_back(CAlarm(date, testType));
        else if (user_id == 2)                              /**< User 2 */
            usr2.push_back(CAlarm(date, testType));
        else if (user_id == 3)                              /**< User 3 */
            usr3.push_back(CAlarm(date, testType));

        cmd.erase(0, pos + delimiter.length());             /**< Erase the token */
    }

    /**< Insert the User 0 alarms */
    for (CAlarm i : usr0)
        removeAlarm(i, EID::USER_0);
    
    /**< Insert the User 1 alarms */
    for (CAlarm i : usr1)
        removeAlarm(i, EID::USER_1);

    /**< Insert the User 2 alarms */
    for (CAlarm i : usr2)
        removeAlarm(i, EID::USER_2);

    /**< Insert the User 3 alarms */
    for (CAlarm i : usr3)
        removeAlarm(i, EID::USER_3);

    return 1;
}

/**
 * @brief Print the alarms elements
 */
void CUsers::printAlarms()
{
    m_users[m_currentUser].printAlarms();
}