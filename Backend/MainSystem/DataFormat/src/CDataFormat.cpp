#include "CDataFormat.h"
#include "SUtils.h"
#include "CSingleton.h"
#include <string.h>
#include <sstream>      /**< std::stringstream */
#include <string>


/**< Get the EasyHealthy/Aplication Handler */
Singleton* MyApp = Singleton::getInstance();

/**
 * @brief Encode the Event received into a command 
 * @param command specifies the event to be encoded
 * @return std::string with the encoded command
 */
std::string CToDB::encode (void* command)
{
    std::string out;

    /**< Get the current user ID */
    int user_id = MyApp->getUsers().getCurrentUser();

    /**< Cast into an event */
    event_t *event = static_cast<event_t*>(command);

    switch (event->request_type.back().operation)
    {
        case OPERATIONS::EXIT:
            out = "EXIT";
            break;
        case OPERATIONS::DB_WRITE:
            out = "W " + std::to_string(user_id) + " " + event->payload;
            break;
        case OPERATIONS::DB_DELETE:
            out = "D " + std::to_string(user_id) + " " + event->payload;
            break;
        case OPERATIONS::DB_READ: 
            out = "R " + std::to_string(user_id) + " " + event->payload;
            break;
        case OPERATIONS::DB_UPDATE: 
            out = "U " + std::to_string(user_id) + " " + event->payload;
            break;
        default:
            break;
    }    
    return out;
}

/**
 * @brief Decode the command received to a SQL statement
 * @param cmd specifies the command to be decoded
 * @return std::string with the decoded SQL statement
 */
std::string CToDB::decode (void* command)
{
    char operation, code;       
    int user_id, sex, age, height, weight, activity_level; 
    std::string name, email_user, email_doctor, result, out, timestamp; 
    std::stringstream ss;  
    std::string delimiter = "\n";
    size_t pos = 0;
    std::string token; 

    /**< Convert to const char* */
    const char* cmd =  static_cast<const char*>(command);

    /**< Extract the defined fields */
    operation = cmd[0];         /**< Extract the Operation field */
    user_id = cmd[2] - 48;      /**< Extract the User ID */
    code = cmd[4];              /**< Extract the Code */

    /**< Convert the command to a stringstream object to process */
    ss << cmd;

    switch (operation)
    {
        case 'W':               /**< Write operation */
            switch (code)      
            {
                case 'C':       /**< Create user */
                    ss >> operation >> user_id >> code >> name >> sex >> age >> height >> weight >> email_user >> email_doctor >> activity_level;
                    out = "INSERT INTO users (id, name, sex, age, height, weight, email_user, email_doctor, activity_level) VALUES (" + std::to_string(user_id) + ", '" + name + "', " + std::to_string(sex) + ", " + std::to_string(age) + ", " + std::to_string(height) + ", " + std::to_string(weight) + ", '" + email_user + "', '" + email_doctor + "', " + std::to_string(activity_level) + ");"; 
                    break;

                case 'T':       /**< Temperature */
                    ss >> operation >> user_id >> code >> timestamp >> result;
                    out = "INSERT INTO measurements (timestamp, user_id, test_type, result) VALUES ('" + timestamp + "', " + std::to_string(user_id) + ", '" + "Temperature" + "', '" + result + "');";
                    break;

                case 'O':       /**< Oxygen Saturation */
                    ss >> operation >> user_id >> code >> timestamp >> result;
                    out = "INSERT INTO measurements (timestamp, user_id, test_type, result) VALUES ('" + timestamp + "', " + std::to_string(user_id) + ", '" + "Oxygen_Saturation" + "', '" + result + "');";
                    break;

                case 'H':       /**< Heartbeat Rate */
                    ss >> operation >> user_id >> code >> timestamp >> result;
                    out = "INSERT INTO measurements (timestamp, user_id, test_type, result) VALUES ('" + timestamp + "', " + std::to_string(user_id) + ", '" + "Heartbeat_Rate" + "', '" + result + "');";
                    break;

                case 'A':       /**< Alarm */
                    ss >> operation >> user_id >> code >> result >> timestamp;
                    out = "INSERT INTO alarms (user_id, test_type, timestamp) VALUES (" + std::to_string(user_id) + ", '" + result + "', '" + timestamp + "');";
                    break;
            }
            break;

        case 'D':               /**< Delete operation */
            switch (code)
            {
                case 'U':       /**< Delete the User */
                    out = "DELETE FROM users WHERE id = " + std::to_string(user_id) + ";";
                    break;
                
                case 'A':       /**< Delete the Alarm */
                    result = cmd;
                    result = result.substr(6);
                    pos = 0;
                    while ((pos = result.find(delimiter)) != std::string::npos) 
                    {
                        token = result.substr(0, pos);                  /**< Get the token */
                        out += "DELETE FROM alarms WHERE timestamp = " + token + ";";
                        result.erase(0, pos + delimiter.length());      /** Erase the token */
                    }
                    break;
            }
            break;

        case 'R':               /**< Read operation */
            switch (code)
            {
                case 'U':       /**< Read the users personal information */
                    out = "SELECT * FROM users ORDER BY id ASC LIMIT 4;";
                    break;

                case 'A':       /**< Read the users alarms */
                    out = "SELECT * FROM alarms ORDER BY timestamp ASC LIMIT 10;";
                    break;

                case 'S':       /**< Read the users sensors measurements */
                    out = "SELECT * FROM measurements WHERE user_id = " + std::to_string(user_id) + " ORDER BY timestamp DESC LIMIT 10;";
                    break;
            }
            break;

        case 'U':               /**< Update operation */
            ss >> operation >> user_id >> code >> name >> sex >> age >> height >> weight >> email_user >> email_doctor >> activity_level;
            out = "UPDATE users SET name = '" + name + "', sex = " + std::to_string(sex) + ", age = " + std::to_string(age) + ", height = " + std::to_string(height) + ", weight = " + std::to_string(weight) + ", email_user = '" + email_user + "', email_doctor = '" + email_doctor + "', activity_level = " + std::to_string(activity_level) + " WHERE id = " + std::to_string(user_id) + ";";
            break;
            
        default:
            break;
    }

    return out;
}

std::string CFromDB::encode (void* command)
{
    std::string a = "a";
    return a;
}

std::string CFromDB::decode (void* command)
{
    std::string a = "a";
    return a;
}

std::string CToGUI::encode (void* command)
{
    std::string a = "a";
    return a;
}

std::string CToGUI::decode (void* command)
{
    std::string a = "a";
    return a;
}

std::string CFromGUI::encode (void* command)
{
    std::string a = "a";
    return a;
}

std::string CFromGUI::decode (void* command)
{
    std::string a = "a";
    return a;
}