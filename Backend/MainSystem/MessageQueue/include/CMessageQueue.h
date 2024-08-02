#ifndef CMESSAGEQUEUE_H
#define CMESSAGEQUEUE_H

#include <mqueue.h>
#include <iostream>
#include <string>

/**
 * @brief Message Queues definition
 */
#define MSGQ_TO_DB      "/toDB"
#define MSGQ_FROM_DB    "/fromDB"
#define MSGQ_TO_GUI     "/toGUI"
#define MSGQ_FROM_GUI   "/fromGUI"

/**
 * @brief Maximum legth
 */
#define MAX_MSG_LEN     10000

/**
 * @brief Message Queue Class
 * @details Handles all Message Queue operations
 */
class CMessageQueue
{
    private:
        const char* name;                                           /**< Message Queue Name */
        int flags;                                                  /**< Message Queue Flags */
        mode_t mode;                                                /**< Message Queue Mode */
        struct mq_attr msgq_attr;                                   /**< Message Queue Attributes */
        mqd_t msq_queue;                                            /**< Message Queue Handler */
        unsigned int prio;                                          /**< Message Queue Priority */

    public:
        CMessageQueue( const char* name, int flags, mode_t mode);   /**< Class Constructor */
        ~CMessageQueue();                                           /**< Class Destructor */
        int open();                                                 /**< Open the Message Queue */
        void close();                                               /**< Close the Message Queue */
        int send( char* msg);                                       /**< Send through Message Queue */
        int receive( char* msg);                                    /**< Receive from Message Queue */
};

#endif