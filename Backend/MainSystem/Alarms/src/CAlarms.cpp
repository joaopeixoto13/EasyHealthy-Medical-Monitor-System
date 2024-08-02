#include "CAlarms.h"
#include <sstream>      /**< std::stringstream */
#include <iostream>

/**
 * @brief Construct a new CAlarms object
 */
CAlarms::CAlarms()
{ }

/**
 * @brief Destroy the CAlarms object
 */
CAlarms::~CAlarms()
{ }

/**
 * @brief Find the index of one alarm in the alarms list
 * @param alarm specifies the alarm
 * @return index if the element was found
 * @return -1 if the element was not found 
 */
int CAlarms::findIndex(CAlarm alarm)
{
    int index = 0;
    int found = 0;

    for (CAlarm i : m_alarms)
    {
        if (i.getTimestamp() == alarm.getTimestamp())
        {
            found = 1;
            break;
        }
        index++;
    }

    /** If the element was found */
    if (found)
        return index;
    else 
        return -1;
}

/**
 * @brief Insert a new element in the alarms list (in Ascending Order by the Timestamp)
 * @param alarm specifies the alarm to be inserted
 * @return true  
 */
bool CAlarms::insert(CAlarm alarm)
{
    for (auto it = m_alarms.begin(); it != m_alarms.end(); it++)
    {
        if (it->getTimestamp() > alarm.getTimestamp())
        {
            m_alarms.insert(it, alarm);
            return 1;
        }
    }
    m_alarms.push_back(alarm);
    return 1;
}

/**
 * @brief Get the Alarms between a lower and upper timestamp boundaries
 * @param lower specifies the lower timestamp boundary
 * @param upper specifies the upper timestamp boundary
 * @return std::vector<CAlarm> 
 */
std::vector<CAlarm> CAlarms::getAlarms(uint32_t lower, uint32_t upper)
{
    std::vector<CAlarm> vec;
    
    if (m_alarms.empty()) 
        vec.push_back({0, "0"});
    
    else
    {
        for (CAlarm i : m_alarms)
        {
            if (i.getTimestamp() >= lower && i.getTimestamp() <= upper)
                vec.push_back({i.getTimestamp(), i.getTestType()});
        }
    }
    return vec;
}

/**
 * @brief Remove one alarm from the list
 * @param alarm specifies the the alarm to be removed
 * @return 1 if the alarm was removed successfully 
 * @return 0 if the aalrm does not exist 
 */
bool CAlarms::remove(CAlarm alarm)
{
    int index = findIndex(alarm);

    if (index == -1)
        return 0;
    m_alarms.erase(m_alarms.begin() + index);
    return 1;
}

/**
 * @brief Print the alarms elements
 */
void CAlarms::print()
{
    for (auto it = m_alarms.begin(); it != m_alarms.end(); it++)
    {
        it->print();
    }
}