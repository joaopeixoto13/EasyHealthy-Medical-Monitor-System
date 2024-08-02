#ifndef CUSERS_H
#define CUSERS_H

#include "CUser.h"
#include <pthread.h>

/**
 * @brief Define the Maximum Number of Users in the System 
 */
#define MAX_USERS 4

/**
 * @brief Users Class
 * @details Handles all Users Operations
 */
class CUsers
{
    private:
        CUser m_users[MAX_USERS];                                                   /**< Users */
        EID m_currentUser;                                                          /**< Current User */
        pthread_mutex_t m_mutex = PTHREAD_MUTEX_INITIALIZER;                        /**< Mutex */
        void update(int slot);                                                      /**< Update the Current User on the System */

    public:
        CUsers();                                                                   /**< Class Constructor */
        ~CUsers();                                                                  /**< Class Destructor */
        bool isEmpty(int slot);                                                     /**< Verify if the User Already Exist */
        bool insert(struct SUSER info, int slot);                                   /**< Insert a New User in the System */
        bool insertFromDB(std::string cmd);                                         /**< Insert Multiple Users in the System given a Pre-Formatted string */
        void remove();                                                              /**< Remove the Current User from the System */
        void clean();                                                               /**< Clean the Current User Personal Informations */
        void print();                                                               /**< Print all Users Informations */
        struct SUSER getInfo();                                                     /**< Get the Current User Personal Information */
        std::vector<struct SUSER> getAllInfo();                                     /**< Get all Users Informations */
        EID getCurrentUser();                                                       /**< Get the Current User in the System */
        void setCurrentUser(EID user);                                              /**< Set the Current User in the System */
        bool insertAlarm(CAlarm alarm, EID usr);                                    /**< Insert an Alarm */
        bool insertAlarmsFromDB(std::string cmd);                                   /**< Insert Alarms given a Pre-Formatted string */
        bool removeAlarm(CAlarm alarm, EID usr);                                    /**< Remove an Alarm */
        bool removeAlarmsFromString(std::string cmd);                               /**< Remove Alarms given a Pre-Formatted string */
        std::vector<struct SUserAlarm> getAlarms(uint32_t lower, uint32_t upper);   /**< Get all the Users Alarms between a Lower and Upper Timestamp Boundaries */
        void printAlarms();                                                         /**< Print all Users Alarms */
};

#endif