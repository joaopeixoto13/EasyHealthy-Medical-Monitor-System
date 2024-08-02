#include "CAlarm.h"

/**
 * @brief Construct a new CAlarm object
 * @param date specifies the timestamp
 * @param testType specifies the test type
 */
CAlarm::CAlarm( uint32_t date, std::string testType )
    : m_testType(testType), m_date(date)
{ }

/**
 * @brief Destroy the CAlarm object
 */
CAlarm::~CAlarm()
{ }

/**
 * @brief Get the alarm timestamp
 * @return uint32_t 
 */
uint32_t CAlarm::getTimestamp()
{
    return m_date;
}

/**
 * @brief Get the alarm test type
 * @return std::string 
 */
std::string CAlarm::getTestType()
{
    return m_testType;
}

/**
 * @brief Print the alarm
 */
void CAlarm::print()
{
    uint8_t month = int(m_date / 10000);
    uint8_t day = int(m_date / 100) % 100;
    uint8_t hour = int(m_date % 100);
    std::cout << "Month: " << std::to_string(month) << ", Day: " << std::to_string(day) << ", Hour: " << std::to_string(hour) << " " << m_testType << std::endl;
}