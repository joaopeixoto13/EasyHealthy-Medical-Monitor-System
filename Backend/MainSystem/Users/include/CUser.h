#ifndef CUSER_H
#define CUSER_H

#include <iostream>
#include <string>
#include "CAlarms.h"

/**
 * @brief User struct
 * @details Pack all User Information
 */
struct SUSER
{
    std::string name;                                                                   /**< User Name */ 
    int sex;                                                                            /**< User Sex */ 
    int age;                                                                            /**< User Age */ 
    int height;                                                                         /**< User Height */ 
    int weight;                                                                         /**< User Weight */ 
    std::string email_doctor;                                                           /**< Doctor Email */ 
    std::string email_user;                                                             /**< User Email */ 
    int activity_level;                                                                 /**< User Activity Level */ 
};

/**
 * @brief ID Enumerate
 */
enum EID
{
    EMPTY = -1,                                                                         /**< Invalid User */
    USER_0,                                                                             /**< User #0 */
    USER_1,                                                                             /**< User #1 */
    USER_2,                                                                             /**< User #2 */
    USER_3                                                                              /**< User #3 */
};

/**
 * @brief Handles the Alarms and User ID
 */
struct SUserAlarm
{
    EID userID;                                                                         /**< User ID */
    uint32_t timestamp;                                                                 /**< Timestamp */
    std::string testType;                                                               /**< Test Type */
};


/**
 * @brief User Class
 * @details Handles all User operations
 */
class CUser
{
    private:
        EID m_id;                                                                       /**< ID */
        struct SUSER m_info;                                                            /**< User Personal Information */
        CAlarms m_alarms;                                                               /**< User Alarms */

    public:
        CUser();                                                                        /**< Class Constructor */
        ~CUser();                                                                       /**< Class Destructor */
        struct SUSER getInfo();                                                         /**< Get the User Personal Information */
        EID getID();                                                                    /**< Get the User ID */
        void setInfo(struct SUSER info);                                                /**< Update the User Personal Information */
        void setID(EID id);                                                             /**< Update the User ID */
        void remove();                                                                  /**< Remove the User */
        void clean();                                                                   /**< Clean the User Information */
        void print();                                                                   /**< Print User Information */
        bool insertAlarm(CAlarm alarm);                                                 /**< Insert an Alarm */
        bool removeAlarm(CAlarm alarm);                                                 /**< Remove an Alarm */
        std::vector<struct SUserAlarm> getAlarms(uint32_t lower, uint32_t upper);       /**< Get the Alarms between a Lower and Upper Timestamp Boundaries */
        void printAlarms();                                                             /**< Print all User Alarms */
};

#endif