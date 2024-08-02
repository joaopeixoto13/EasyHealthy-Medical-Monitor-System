#ifndef CDATAFORMAT_H
#define CDATAFORMAT_H

#include <iostream>
#include <string>

/**
 * @brief Data Format Class
 * @details Handles all Data Formats
 */
class CDataFormat
{
    public:
        virtual std::string encode (void* command) = 0;
        virtual std::string decode (void* command) = 0;
};

/**
 * @brief To-Database Data Format
 * @details Implements the Data Formats between the DatabaseManager thread and the Database daemon
 */
class CToDB : public CDataFormat
{
    public:
        std::string encode (void* command);     /**< tDatabaseManager:  Encode the Event received into a command */
        std::string decode (void* command);     /**< dDatabase:         Decode the command received to a SQL statement */
};

/**
 * @brief From-Database Data Format
 * @details Implements the Data Formats between the Database daemon and the DatabaseManager thread
 */
class CFromDB : public CDataFormat
{
    public:
        std::string encode (void* command);     /**< dDatabase:         Encode the database data into a command */
        std::string decode (void* command);     /**< tDatabaseManager:  Decode the command received by dDatabase */
};

/**
 * @brief To-GUI Data Format
 * @details Implements the Data Formats between the SendToGUI and the UpdateGUI threads
 */
class CToGUI : public CDataFormat
{
    public:
        std::string encode (void* command);     /**< tSendToGUI:        Encode the command */
        std::string decode (void* command);     /**< tUpdateGUI:        Decode the command */
};

/**
 * @brief From-GUI Data Format
 * @details Implements the Data Formats between the Interface and the ReceiveFromGUI threads
 */
class CFromGUI : public CDataFormat
{
    public:
        std::string encode (void* command);     /**< tInterface:        Encode the command */
        std::string decode (void* command);     /**< tReceiveFromGUI:   Decode the command */
};

#endif