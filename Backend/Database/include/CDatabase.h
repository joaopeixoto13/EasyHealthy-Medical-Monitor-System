#ifndef CDATABASE_H
#define CDATABASE_H

#include <iostream>
#include <string>
#include "sqlite3.h"

/**
 * @brief Database Class
 * @details Handles all Database Operations
 */
class CDatabase
{
    private:
        const char* m_path;                                                             /**< Database Path */
        sqlite3* m_db;                                                                  /**< Database Handler */
        void createDB();                                                                /**< Create the Database */
        static int callback(void* NotUsed, int argc, char** argv, char** azColName);    /**< Database Callback, independent of any particular object of the class */

    public:
        CDatabase(const char* path);                                                    /**< Class Constructor */
        ~CDatabase();                                                                   /**< Class Destructor */
        int insert(std::string sql);                                                    /**< Insert into the Database */
        int update(std::string sql);                                                    /**< Update the Database */
        int remove(std::string sql);                                                    /**< Remove from Database */
        int select(std::string sql);                                                    /**< Select/read from Database */
        static std::string feedback;                                                    /**< Feedback */
};

#endif