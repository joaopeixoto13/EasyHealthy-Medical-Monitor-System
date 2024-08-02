#ifndef CEVENTFSM_H
#define CEVENTFSM_H

#include <pthread.h>
#include <queue> 
#include "SUtils.h"

#define THREADS_NUM 8

/**
 * @brief Event Driven State Machine Mutexes and Condition Variables
 * @details Declare all necessary mutexes and condition variables to perform a secure and fully responsive thread communication
 */ 

extern pthread_mutex_t cond_mutex_dataAcquisition;
extern pthread_mutex_t cond_mutex_export;
extern pthread_mutex_t cond_mutex_dbManager;
extern pthread_mutex_t cond_mutex_sendToGUI;

extern pthread_cond_t cond_dataAcquisition;
extern pthread_cond_t cond_export;
extern pthread_cond_t cond_dbManager;
extern pthread_cond_t cond_sendToGUI;

/**
 * @brief Event Driven State Machine Class 
 * @details This Class implements the communication between the main threads
 */

class CEventFSM
{
    private:
        std::queue <event_t> m_events[THREADS_NUM];                         /**< Threads Event Queues */
        pthread_mutex_t m_mutex = PTHREAD_MUTEX_INITIALIZER;                /**< Mutex */
        void dispatch( thread_id_t id);                                     /**< Dispatch (Scheduling Point) */

    public:
        CEventFSM();                                                        /**< Class Constructor */
        ~CEventFSM();                                                       /**< Class Destructor */
        void post ( event_t ev, thread_id_t id );                           /**< Post an Event */
        void pop (thread_id_t id);                                          /**< Pop the last Event */
        event_t front (thread_id_t id);                                     /**< Get the first Event */         
        bool empty (thread_id_t id);                                        /**< Verify if the Event Queue is Empty or not */
        size_t size (thread_id_t id);                                       /**< Get the number of Events in the Queue of Events */
        std::vector<request_type_t> next (thread_id_t id);                  /**< Selects the Next Request to be Executed */
        void clear (thread_id_t id);                                        /*< Clear all events */
};

#endif