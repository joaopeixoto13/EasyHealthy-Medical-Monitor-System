#include "CUSB.h"
#include <iostream>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/syslog.h>
#include <sys/types.h> 
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <cstring>

/**
 * @brief Write into log file
 * @param arg String to write
 */
void writeIntoLogFile(char *arg)
{
    int fd;
    if ((fd = open("/var/log/daemonUSB.log", O_CREAT | O_WRONLY | O_APPEND, 0600)) < 0)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }
    write(fd, arg, strlen(arg) + 1);
    close(fd);
}

/**
 * @brief Send a signal with a message
 * @param id Process ID
 * @param signo Signal number
 * @param val Value to send
 */
void sigSendVal(pid_t id, int signo, int val)
{
    union sigval *sigdata;
    sigdata = (sigval*)malloc(sizeof(union sigval));
    sigdata->sival_int = val;
    sigqueue(id, signo, *sigdata);
    free(sigdata);
}

/**
 * @brief Check if a string is a number
 * @param arg string to check
 * @return true if arg is a number
 * @return false if arg is not a number
 */
bool isNumber(char *arg)
{
    for (int i = 0; i < (strlen(arg) - 1); i++)
    {
        if (arg[i] < '0' || arg[i] > '9')
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[])
{
    pid_t pid, sid;

	/**< Create a new Process */
	pid = fork(); 

	if (pid < 0) 
	{
		perror("fork");		/**< Error case */
		exit(EXIT_FAILURE);
	}

	if (pid > 0)
	{  	
		exit(EXIT_SUCCESS); /**< Exit the parent process */
	}

    pid = getpid();
    std::cout << "./daemonUSB at: " << std::to_string((int)pid) << std::endl;

	/**< Create a new session in the child */
	sid = setsid(); 

	if (sid < 0) 
	{ 
		perror("setsid");	/**< Error case */
		exit(EXIT_FAILURE);
	}

	/**< Make '/' the root directory */
	if (chdir("/") < 0) 
	{ 
		perror("chdir failure");
		exit(EXIT_FAILURE);
	}

	/**< Change the child process’s umask to 0 */
	umask(0);

	/**< Close any unneeded file descriptor */
	/**< Note: There is no reason for a child to keep open descriptors inherited from parent. */
	close(STDIN_FILENO);  /**< close standard input file descriptor */
	close(STDOUT_FILENO); /**< close standard output file descriptor */
	close(STDERR_FILENO); /**< close standard error file descriptor */

    /**< Behavior */

    std::string message;
    bool oldUSBState = false;

    /**< Get main process ID*/
    char line[20];
    FILE *cmd = NULL;
    writeIntoLogFile((char *)"Waiting for main process...\n\n");
    do
    {
        cmd = popen("pidof -s EasyHealthy", "r");
        fgets(line, 20, cmd);
        pclose(cmd);
    } while (!isNumber(line));                                      
    pid_t mainProcessID = atoi(line);
    message = "Main process ID: " + std::to_string(mainProcessID) + "\n\n";
    writeIntoLogFile((char *)message.c_str());

    /**< Create a new USB object */
    CUSB usb;

    if (usb.isMounted())
    {
        oldUSBState = true;
        writeIntoLogFile((char *)"USB is mounted\n");
        sigSendVal(mainProcessID, SIGUSR1, 1);  /**< Send a signal to main process */
        message = "Signal sent to main process(" + std::to_string(mainProcessID) + ") with value: " + std::to_string(usb.isMounted()) + "\n\n";
        writeIntoLogFile((char *)message.c_str());
    }
    else
        writeIntoLogFile((char *)"USB is not mounted\n");

    /**< Monitor USB */
    while (1)
    {
        std::string device = usb.monitor();
        if (device != "")
        {
            writeIntoLogFile((char *)"Monitor: ");
            message = device + "\n";
            writeIntoLogFile((char *)message.c_str());
            if(oldUSBState != usb.isMounted())                              /**< If the state of the USB has changed */
            {
                oldUSBState = usb.isMounted();
                if (usb.isMounted())
                    writeIntoLogFile((char *)"USB is mounted\n");
                else
                    writeIntoLogFile((char *)"USB is not mounted\n");
                message = "Signal sent to main process(" + std::to_string(mainProcessID) + ") with value: " + std::to_string(usb.isMounted()) + "\n\n";
                writeIntoLogFile((char *)message.c_str());
                sigSendVal(mainProcessID, SIGUSR1, (int)usb.isMounted());   /**< Send a signal to main process */
            }
        }
    }
    exit(EXIT_SUCCESS);
}
