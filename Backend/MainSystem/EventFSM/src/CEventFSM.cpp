#include "CEventFSM.h"
#include <iostream>

pthread_mutex_t cond_mutex_dataAcquisition = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t cond_mutex_export = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t cond_mutex_dbManager = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t cond_mutex_sendToGUI = PTHREAD_MUTEX_INITIALIZER;

pthread_cond_t cond_dataAcquisition = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond_export = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond_dbManager = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond_sendToGUI = PTHREAD_COND_INITIALIZER;

/**
 * @brief Construct a new Event FSM object
 */
CEventFSM::CEventFSM()
{
}

/**
 * @brief Destroy the Event FSM object
 */
CEventFSM::~CEventFSM()
{
}

/**
 * @brief Shedule the next thread to be executed
 * @details Accordintly to the type of the event, the sheduler selects the thread that must be executed
 * @param id specifies the ThreadID
 */
void CEventFSM::dispatch( thread_id_t id )
{
   switch (m_events[id].front().request_type.back().thread_id)
    {
        case THREAD_ID::DATA_ACQUISITION:
            pthread_mutex_lock( &cond_mutex_dataAcquisition );
            pthread_cond_signal( &cond_dataAcquisition );
            pthread_mutex_unlock( &cond_mutex_dataAcquisition );
            break;

        case THREAD_ID::EXPORT:
            pthread_mutex_lock( &cond_mutex_export );
            pthread_cond_signal( &cond_export );
            pthread_mutex_unlock( &cond_mutex_export );
            break;

        case THREAD_ID::DATABASE_MANAGER:
            pthread_mutex_lock( &cond_mutex_dbManager );
            pthread_cond_signal( &cond_dbManager );
            pthread_mutex_unlock( &cond_mutex_dbManager );
            break;

        case THREAD_ID::SEND_TO_GUI:
            pthread_mutex_lock( &cond_mutex_sendToGUI );
            pthread_cond_signal( &cond_sendToGUI );
            pthread_mutex_unlock( &cond_mutex_sendToGUI );
            break;

        default:
            break;
    }
}

/**
 * @brief Post an Event in the Thread Events Queue
 * @param ev specifies the Event to be inserted
 * @param id specifies the Queue that the event will be inserted
 */
void CEventFSM::post( event_t ev, thread_id_t id )
{
    pthread_mutex_lock(&m_mutex);
    m_events[id].push(ev);
    pthread_mutex_unlock(&m_mutex);

    dispatch(id);
}

/**
 * @brief Pop the last Event from a Thread Events Queue
 * @param id specifies the Queue 
 */
void CEventFSM::pop (thread_id_t id)
{
    pthread_mutex_lock(&m_mutex);
    m_events[id].pop();  
    pthread_mutex_unlock(&m_mutex);    
}

/**
 * @brief Returns the front element of Queue
 * @param id specifies the Queue
 * @return event_t 
 */
event_t CEventFSM::front (thread_id_t id)
{
    return m_events[id].front();
}

/**
 * @brief Verify if a certain Queue has Events
 * @param id specifies the Queue to be tested
 * @return true if the Queue is empty
 * @return false if the Queue is not empty
 */
bool CEventFSM::empty (thread_id_t id)
{
    return m_events[id].empty();
}

/**
 * @brief Returns the number of Events of a certain Queue
 * @param id specifies the Queue
 * @return size_t 
 */
size_t CEventFSM::size (thread_id_t id)
{
    return m_events[id].size();
}

/**
 * @brief Selects the next request to be executed
 * @details This function is very important because one request can have more than one hop. This means that a thread can communicate 7
 * with not only one thread, but can establish a connection between some of them. This function pops the front element from the 
 * queue (the older one) and returns the next operations to do.
 * @param id specifies the Queue
 * @return std::vector<request_type_t> 
 */
std::vector<request_type_t> CEventFSM::next (thread_id_t id)
{
    pthread_mutex_lock(&m_mutex);
    m_events[id].front().request_type.pop_back();
    pthread_mutex_unlock(&m_mutex); 
    return m_events[id].front().request_type;
} 

/**
 * @brief Clear all Thread Events Queue
 * @param id specifies the Queue 
 */
void CEventFSM::clear (thread_id_t id)
{
    for (size_t i = 0; i < m_events[id].size(); i++)
        pop(id); 
}