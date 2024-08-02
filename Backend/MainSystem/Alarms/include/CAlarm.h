#ifndef CALARM_H
#define CALARM_H

#include <iostream>

/**
 * @brief Alarm Class
 * @details Handles all Alarm operations
 */
class CAlarm
{
    private:
        uint32_t m_date;                                /**< Timestamp */
        std::string m_testType;                         /**< Test Type */

    public:
        CAlarm(uint32_t date, std::string testType);    /**< Class Constructor */
        ~CAlarm();                                      /**< Class Destructor */
        uint32_t getTimestamp();                        /**< Get the Timestamp */
        std::string getTestType();                      /**< Get the Test Type */
        void print();                                   /**< Print the Alarm Information */
};

#endif