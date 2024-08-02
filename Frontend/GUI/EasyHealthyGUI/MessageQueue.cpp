#include "MessageQueue.h"
#include <string.h>

/**
 * @brief Construct a new CMessageQueue object
 * @param name specifies the Message Queue name
 * @param flags specifies the Message Queue flags
 * @param mode specifies the Message Queue mode
 */
CMessageQueue::CMessageQueue( const char* name, int flags, mode_t mode)
    : m_name(name), m_flags(flags), m_mode(mode), m_prio(1)
{ }

/**
 * @brief Destroy the CMessageQueue object
 */
CMessageQueue::~CMessageQueue()
{ }

/**
 * @brief Open the Message Queue
 * @return 0 if Ok, -1 if occured any error 
 */
int CMessageQueue::open()
{
    /**< Open the queue */
    m_msq_queue = mq_open( m_name, m_flags, m_mode, NULL);

    /**< Verify if an error occured */
    if (m_msq_queue == ((mqd_t) - 1))
        return -1;
    
    /**< Get the attributes from the queue */
    mq_getattr( m_msq_queue, &m_msgq_attr);

    std::cout << "Queue [" << m_name << "] stores at most " << m_msgq_attr.mq_maxmsg << " messages and can have at most " << m_msgq_attr.mq_msgsize << " bytes each" << std::endl;

    return 0;
}

/**
 * @brief Close the Message Queue
 */
void CMessageQueue::close()
{
    /**< Close the Queue */   
    mq_close(m_msq_queue);

    /**< Removes the specified message queue name */   
    //mq_unlink(name);
}
 
/**
 * @brief Send message to Message Queue
 * @param msg specifies the message to sent
 * @return int 
 */
int CMessageQueue::send( char* msg )
{
    /**< Send the message */
    return mq_send(m_msq_queue, msg, strlen(msg)+1, m_prio);
}

/**
 * @brief Receive message from Message Queue
 * @param msg specifies the message to be received
 * @return number of bytes read correctly (-1 if error)
 */
int CMessageQueue::receive( char* msg )
{
    unsigned int sender;

    /**< Get the attributes */
    mq_getattr(m_msq_queue, &m_msgq_attr);

    /**< Receive the message */
    if (mq_receive(m_msq_queue, msg, MAX_MSG_LEN, &sender) == -1)
        return -1;
    return sender;
}