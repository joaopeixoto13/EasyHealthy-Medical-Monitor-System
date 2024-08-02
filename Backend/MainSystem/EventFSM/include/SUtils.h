#ifndef SUTILS_H
#define SUTILS_H

#include <vector>
#include <string>
#include <fstream>

/**
 * @brief Define all the main threads priorities
 */
#define DATA_ACQUISITION_PRIO   25
#define ALARM_PRIO              20
#define EXPORT_PRIO             20
#define DATABASE_MANAGER_PRIO   15
#define RECEIVE_FROM_GUI_PRIO   10
#define SEND_TO_GUI_PRIO        10

/**
 * @brief Thread ID enumerate
 * @details Handles the main Thread ID's
 */
typedef enum THREAD_ID
{
    DATA_ACQUISITION = 0,
    ALARM,   
    EXPORT,
    DATABASE_MANAGER,
    RECEIVE_FROM_GUI,
    SEND_TO_GUI,
    MAIN
} thread_id_t;

/**
 * @brief Operations enumerate
 * @details Handles the type of operations
 * @note Each thread can have more than one operation type (e.g the EXIT is common for all of them)
 */
typedef enum OPERATIONS
{
    EXIT = 0,
    TEMPERATURE,
    OXYGEN,
    HEARTBEAT_RATE,
    ALARM_EMAIL,
    USER_EMAIL,
    DOCTOR_EMAIL,
    USB_DOWNLOAD,
    USB_ON,
    USB_OFF,
    DB_READ,
    DB_WRITE,
    DB_DELETE,
    DB_UPDATE,
    ALARM_READ,
    FEEDBACK_EXPORT,
    FEEDBACK_TEST,
    FEEDBACK_CONSULT,
    FEEDBACK_CHANGE_PROFILE,
    FEEDBACK_DELETE_PROFILE,
    FEEDBACK_USERS_NAMES,
    FEEDBACK_USER_DATA,
    FEEDBACK_ALARMS
} operation_t;

/**
 * @brief Request Type struct
 * @details Pack the request type of each event
 * @public thread_id specifies the Thread ID
 * @public operation specifies the Operation type
 */
typedef struct REQUEST_TYPE
{
    thread_id_t thread_id;
    operation_t operation;
} request_type_t;

/**
 * @brief Acknoledgement enumerate
 * @details Indentify if an event was done and with sucess
 * @public O if the event is not yet been completed
 * @public -1 if the event is completed with errors
 * @public 1 if the event is completed correctly
 */
typedef enum ACK
{
    NOT_COMPLETE = -1,
    ERROR = 0,
    SUCCESS = 1
} ack_t;

/**
 * @brief Event struct
 * @details Handles all infomration necessary to an event
 */
typedef struct EVENT
{
    std::vector<request_type_t> request_type;       /**< Request type */  
    ack_t ack;                                      /**< Acknoledgment */
    std::string payload;                            /**< Payload */
} event_t;

#endif