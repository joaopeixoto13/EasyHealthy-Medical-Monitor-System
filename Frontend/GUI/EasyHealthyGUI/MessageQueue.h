#ifndef MESSAGEQUEUE_H
#define MESSAGEQUEUE_H

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
 * @details Handles all message queue operations
 */
class CMessageQueue
{
    private:
        const char* m_name;           /**< Queue name */
        int m_flags;                  /**< Flags (O_RDONLY, O_WRONLY, O_CREAT, O_EXCL) */
        mode_t m_mode;                /**< Mode (S_IRWXU, S_IRWXG) */
        struct mq_attr m_msgq_attr;   /**< Attributes */
        mqd_t m_msq_queue;            /**< Handler */
        unsigned int m_prio;          /**< Priority */

    public:
        CMessageQueue( const char* name, int flags, mode_t mode);
        ~CMessageQueue();
        int open();
        void close();
        int send( char* msg);
        int receive( char* msg);

};

#endif