#include "CUser.h"

/**
 * @brief Construct a new CUser object
 */
CUser::CUser()
{ }

/**
 * @brief Destroy the CUser object
 */
CUser::~CUser()
{ }

/**
 * @brief Get the personal information
 * @return struct SUSER 
 */
struct SUSER CUser::getInfo()
{
    return m_info;
}

/**
 * @brief Get the User identifier
 * @note A ID greater or equal than 0 is a valid one, otherwise return -1
 * @return EID 
 */
EID CUser::getID()
{
    return m_id;
}

/**
 * @brief Set the User Information
 * @param info specifies the user personal information
 */
void CUser::setInfo(struct SUSER info)
{
    this->m_info = info;
}

/**
 * @brief Set the user ID
 * @param id specifies the user identifier
 */
void CUser::setID(EID id)
{
    this->m_id = id;
}

/**
 * @brief Remove the User
 * @note The removing process is setting the ID to EMPTY
 */
void CUser::remove()
{
    this->m_id = EID::EMPTY;
}

/**
 * @brief Clean the Users informations
 */
void CUser::clean()
{
    this->m_info.name = "";
    this->m_info.sex = 0;
    this->m_info.age = 0;
    this->m_info.height = 0;
    this->m_info.weight = 0;
    this->m_info.activity_level = 0;
    this->m_info.email_doctor = "";
    this->m_info.email_user = "";
}

/**
 * @brief Print the User Information
 */
void CUser::print()
{
    std::cout << "*********************************************" << std::endl;
    std::cout << "User #" << std::to_string((int)m_id) << std::endl;
    std::cout << "Name: " << m_info.name << std::endl;
    std::cout << "Sex: " << std::to_string(m_info.sex) << std::endl;
    std::cout << "Age: " << std::to_string(m_info.age) << std::endl;
    std::cout << "Height: " << std::to_string(m_info.height) << std::endl;
    std::cout << "Weight: " << std::to_string(m_info.weight) << std::endl;
    std::cout << "Email User: " << m_info.email_user << std::endl;
    std::cout << "Email Doctor: " << m_info.email_doctor << std::endl;
    std::cout << "Activity Level: " << std::to_string(m_info.activity_level) << std::endl;
    printAlarms();
    std::cout << "*********************************************" << std::endl;
}

/**
 * @brief Insert one alarm 
 * @param alarm specifies the alarm to be inserted
 * @return true 
 * @return false 
 */
bool CUser::insertAlarm(CAlarm alarm)
{
    return m_alarms.insert(alarm);
}

/**
 * @brief Remove an alarm 
 * @param alarm specifies the alarm to be removed
 * @return true 
 * @return false 
 */
bool CUser::removeAlarm(CAlarm alarm)
{
    return m_alarms.remove(alarm);
}

/**
 * @brief Get the Alarms between a lower and upper timestamp boundaries
 * @param lower specifies the lower timestamp boundary
 * @param upper specifies the upper timestamp boundary
 * @return std::vector<struct SUserAlarm>
 */
std::vector<struct SUserAlarm> CUser::getAlarms(uint32_t lower, uint32_t upper)
{
    /**< Get the alarms between the lower and upper limits */
    std::vector<CAlarm> alarms = m_alarms.getAlarms(lower, upper);

    /**< Create a handler to merge the alarms and the corresponding User ID */
    std::vector<struct SUserAlarm> userAlarms;

    /**< For all the user alarms*/
    for (CAlarm i : alarms)
    {
        /**< Insert into the Users Alarms the User Id with the Alarm */
        userAlarms.push_back({m_id, i.getTimestamp(), i.getTestType()});
    }

    /**< Return the User Alarms */
    return userAlarms;
}

/**
 * @brief Print the alarms elements
 */
void CUser::printAlarms()
{
    m_alarms.print();
}