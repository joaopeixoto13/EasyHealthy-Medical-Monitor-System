#include "CDatabase.h"
#include <string.h>
#include <sstream>      /**< std::stringstream */

#define SUCCESS 0
#define ERROR -1

/**< Initialize the static member */
std::string CDatabase::feedback = "";

/**< By default, Foreign Keys are disable in sqlite3, so we must enable it */
std::string ss = "PRAGMA foreign_keys = ON; ";

/**< Temporary string to handle the callback message */
std::string temp;

/**
 * @brief Construct a new CDatabase object
 * @param path specifies where the database will be stored
 */
CDatabase::CDatabase(const char* path)
    : m_path(path)
{
    createDB();
}

/**
 * @brief Destroy the CDatabase object
 */
CDatabase::~CDatabase()
{ }

/**
 * @brief Create the Database Tables
 */
void CDatabase::createDB()
{
    int exit = 0;
    char* messageError;

    /**< Open the Database */
    exit = sqlite3_open(m_path, &m_db);

    if( exit )
    {
        std::cout << "DB Error: " << sqlite3_errmsg(m_db) << std::endl; /**< Show the error message*/
        sqlite3_close(m_db);                                            /**< Close the connection */
        return;
    }    

    /**< SQL message for tables creation */
    std::string sql = "CREATE TABLE IF NOT EXISTS users("
    "id INTEGER PRIMARY KEY, "
    "name TEXT, "
    "sex BOOL, "
    "age INTEGER, "
    "height INTEGER, "
    "weight INTEGER, "
    "email_user TEXT, "
    "email_doctor TEXT, "
    "activity_level INTEGER);"
    "CREATE TABLE IF NOT EXISTS measurements("
    "timestamp TEXT PRIMARY KEY, "
    "user_id INTEGER, "
    "test_type TEXT, "
    "result TEXT, "
    "CONSTRAINT fk_userID FOREIGN KEY(user_id) REFERENCES users(id) ON DELETE CASCADE);"
    "CREATE TABLE IF NOT EXISTS alarms("
    "alarm_id INTEGER PRIMARY KEY AUTOINCREMENT, "
    "user_id INTEGER, "
    "test_type TEXT, "
    "timestamp INTEGER, "
    "CONSTRAINT fk_userID FOREIGN KEY(user_id) REFERENCES users(id) ON DELETE CASCADE);";
    
    /**< An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
    exit = sqlite3_exec(m_db, (ss + sql).c_str(), NULL, 0, &messageError);
    
    if (exit != SQLITE_OK) 
    {
        std::cout << "Error: in [Users] createTable function" << std::endl;
        sqlite3_free(messageError);
    }
    /**< Close the Database */
    sqlite3_close(m_db);
}

/**
 * @brief retrieve contents of database used by CDatabase::select()
 * @param NotUsed 
 * @param argc specifies the number of rows
 * @param argv specifies the values
 * @param azColName specifies the columns names
 * @return int 
 */
int CDatabase::callback(void* NotUsed, int argc, char** argv, char** azColName)
{
    std::string aux1, aux2;
    std::stringstream ss;
	for (int i = 0; i < argc; i++) 
    {
        aux2 = argv[i];

        if (temp != "" && temp[temp.length()-1] != '\n')         
            temp = temp + " ";
            
        temp = temp + aux2;  /**< Add the value */
	}

    temp = temp + "\n";     /**< Add a break */

    /**< If an sqlite3_exec() callback returns non-zero, the sqlite3_exec() routine returns SQLITE_ABORT 
     *   without invoking the callback again and without running any subsequent SQL statements. */
    return 0;  
}

/**
 * @brief Insert data into Database
 * @param sql specifies the command
 * @return int 
 */
int CDatabase::insert(std::string sql)
{
    int exit = 0;
    int count = 3;
    char* messageError;

    /**< Open the Database */
    exit = sqlite3_open(m_path, &m_db);
    exit = 1;

    /**< Try 3 times */
    while ((count-- != 0) && exit != SQLITE_OK)
    {
        /**< An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
        exit = sqlite3_exec(m_db, (ss + sql).c_str(), NULL, 0, &messageError);  
    }

    /**< Give the feedback */
    feedback = std::to_string(!exit);  

    if (exit != SQLITE_OK) 
    {
        std::cout << "Error in insert function: " << messageError << std::endl;
        sqlite3_free(messageError);
        return ERROR;
    }
    return SUCCESS;
}

/**
 * @brief Update data in the database
 * @param sql specifies the command
 * @return int 
 */
int CDatabase::update(std::string sql)
{
    int exit = 0;
    int count = 3;
    char* messageError;

    /**< Open the Database */
    exit = sqlite3_open(m_path, &m_db);
    exit = 1;

    /**< Try 3 times */
    while ((count-- != 0) && exit != SQLITE_OK)
    {
        /**< An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
        exit = sqlite3_exec(m_db, (ss + sql).c_str(), NULL, 0, &messageError);  
    } 

    /**< Give the feedback */
    feedback = std::to_string(!exit);

    if (exit != SQLITE_OK) 
    {
        std::cout << "Error in update function: " << messageError << std::endl;
        sqlite3_free(messageError);
        return ERROR;
    }
    return SUCCESS;        
}

/**
 * @brief Remove data in the database
 * @param sql specifies the command
 * @return int 
 */
int CDatabase::remove(std::string sql)
{
    int exit = 0;
    int count = 3; 
    char* messageError;

    /**< Open the Database */
    exit = sqlite3_open(m_path, &m_db);
    exit = 1;

    /**< Try 3 times */
    while ((count-- != 0) && exit != SQLITE_OK)
    {
        /**< An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
        exit = sqlite3_exec(m_db, (ss + sql).c_str(), NULL, 0, &messageError);  
    } 

    /**< Give the feedback */
    feedback = std::to_string(!exit);

    if (exit != SQLITE_OK) 
    {
        std::cout << "Error in remove function: " << messageError << std::endl;
        sqlite3_free(messageError);
        return ERROR;
    }
    return SUCCESS;    
}

/**
 * @brief Select data from the database
 * @param sql specifies the command
 * @return int 
 */
int CDatabase::select(std::string sql)
{
    int exit = 0;
    int count = 3;
    char* messageError;

    /**< Open the Database */
    exit = sqlite3_open(m_path, &m_db);

    exit = 1;
    temp = "";

    /**< Try 3 times */
    while ((count-- != 0) && exit != SQLITE_OK)
    {
        /**< An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
        exit = sqlite3_exec(m_db, (ss + sql).c_str(), callback, NULL, &messageError);  
    } 

    /**< Give the feedback */
    feedback = std::to_string(!exit) + " " + temp;

    if (exit != SQLITE_OK) 
    {
        std::cout << "Error in select function: " << messageError << std::endl;
        sqlite3_free(messageError);
        return ERROR;
    }
    return SUCCESS;  
}