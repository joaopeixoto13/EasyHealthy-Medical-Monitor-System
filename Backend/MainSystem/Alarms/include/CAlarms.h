#ifndef CALARMS_H
#define CALARMS_H

#include "CAlarm.h"
#include <vector>

/**
 * @brief Alarms Class
 * @details Handles all Alarms operations
 */
class CAlarms
{
    private:
        std::vector<CAlarm> m_alarms;                                   /**< Alarms List */
        int findIndex(CAlarm alarm);                                    /**< Find an Alarm index */

    public:
        CAlarms();                                                      /**< Class Constructor */
        ~CAlarms();                                                     /**< Class Destructor */
        bool insert(CAlarm alarm);                                      /**< Insert a New Alarm */
        bool remove(CAlarm alarm);                                      /**< Remove an Alarm */
        std::vector<CAlarm> getAlarms(uint32_t lower, uint32_t upper);  /**< Get the Alarms between an upper and lower timestamp */
        void print();                                                   /**< Print all Alarms Informations */
};
 
#endif