#include <sys/types.h> 
#include <sys/stat.h>
#include <unistd.h> 
#include <stdlib.h>
#include <string.h>
#include <stdio.h> 
#include <fcntl.h>
#include <iostream>
#include "CDatabase.h"
#include "CDataFormat.h"
#include "CMessageQueue.h"

/**< Database Directory */
const char* dir = "/root/EasyHealthy/Database/EasyHealthy.db";

void writeIntoLogFile(char* arg)
{
	int fd;
	if ((fd = open("/var/log/daemonDB.log",	O_CREAT | O_WRONLY | O_APPEND, 0600)) < 0) {
		perror("open");
		exit(EXIT_FAILURE);
	}
	write(fd, arg, strlen(arg)+ 1);
	close(fd);
}

int main(int argc, char *argv[])
{
    pid_t pid, sid;

	/**< 1. Create a new Process */
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
    std::cout << "./daemonDB at: " << std::to_string((int)pid) << std::endl;

	/**< 2. Create a new session in the child */
	sid = setsid(); 

	if (sid < 0) 
	{ 
		perror("setsid");	/**< Error case */
		exit(EXIT_FAILURE);
	}

	/**< 3. Make '/' the root directory */
	if (chdir("/") < 0) 
	{ 
		perror("chdir failure");
		exit(EXIT_FAILURE);
	}

	/**< 4. Change the child process’s umask to 0 */
	umask(0);

	/**< 5. Close any unneeded file descriptor */
	/**< Note: There is no reason for a child to keep open descriptors inherited from parent. */
	close(STDIN_FILENO);  /**< close standard input file descriptor */
	close(STDOUT_FILENO); /**< close standard output file descriptor */
	close(STDERR_FILENO); /**< close standard error file descriptor */

	/*#######################################################################################*/

	/**< Create the Database Object */
    CDatabase db(dir);

	/*#######################################################################################*/

    /**< Create a object DataFormat */
    CDataFormat *df;

    /**< Create a object to help to manage the Message Queue protocol */
    CToDB toDB;

    /**< Assign the DataFormat as a toDB protocol */
    df = &toDB;

    /*#######################################################################################*/

	char msgcontent[MAX_MSG_LEN];
	char logFeedback[100];
	std::string out;

	/**< Create the toDB handler with the READ_ONLY flag */
    CMessageQueue mq_toDB(MSGQ_TO_DB, O_RDONLY | O_CREAT, S_IRWXU | S_IRWXG);

	/** Create the fromDB handler with the WRITE_ONLY flag */
	CMessageQueue mq_fromDB(MSGQ_FROM_DB, O_WRONLY | O_CREAT, S_IRWXU | S_IRWXG);

	strcpy(logFeedback, "Daemon DB Created");
    writeIntoLogFile(logFeedback);
    
    if (mq_toDB.open() == -1)
    {
		strcpy(logFeedback, "ERROR: toDB cannot open");
        writeIntoLogFile(logFeedback);
        exit(1);
    }
	
	if (mq_fromDB.open() == -1)
    {
		strcpy(logFeedback, "ERROR: fromDB cannot open");
        writeIntoLogFile(logFeedback);
        exit(1);
    }
	
	while (1) 
	{
		for(int i = 0; i < MAX_MSG_LEN; i++)
			msgcontent[i] = '\0';
		/**< Try to receive a message from toDB Message Queue */
        if( mq_toDB.receive( msgcontent ) == -1)
		{
			strcpy(logFeedback, "ERROR: Receive");
			writeIntoLogFile(logFeedback);
		}
		writeIntoLogFile(msgcontent);
		writeIntoLogFile("\n");
		/** Decode the Message Received */
		out = df->decode(static_cast<void *>(msgcontent));
		writeIntoLogFile(msgcontent);
		writeIntoLogFile("\n");
		switch (out[0])
		{
			case 'I':						/**< Insert into Database */
				db.insert(out);
				break;
			
			case 'D':						/**< Delete from Database */
				db.remove(out);
				break;

			case 'S':						/**< Select/Read from Database */
				db.select(out);
				break;

			case 'U':						/**< Update Database */
				db.update(out);
				break;
		}

		/**< Send the response to tDatabaseManager */
		strcpy(msgcontent, CDatabase::feedback.c_str());
		if( mq_fromDB.send( msgcontent ) != 0)
		{
			strcpy(logFeedback, "ERROR: Send");
			writeIntoLogFile(logFeedback);
		}
	}

	/**< Close the Queues */
	mq_toDB.close();
	mq_fromDB.close();

	exit(EXIT_SUCCESS);		
}
