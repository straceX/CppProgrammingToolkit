#include "sqllite_db_operations.h"

sqllitedb::sqllitedb(const std::string &dbname) : dbname(dbname)
{
    try {

        if (sqlite3_open(dbname.c_str(), &db) != SQLITE_OK)
        {
            throw sqlite3_errmsg(db);
        }

    }
    catch (const char* msg) {
        std::cerr << msg << std::endl;
        sqlite3_close(db);
    }

}

std::string sqllitedb::db_version()
{
    return std::string(sqlite3_libversion());
}

bool sqllitedb::table_row_count(std::string table_name,int &row_count)
{
    std::string querry = "select count(*) from " + table_name;

    try {

         if (sqlite3_exec(db, querry.c_str(), callback, &row_count, &errMsg) != SQLITE_OK)
         {
            throw errMsg;
         }
         std::cout << "Querry execed" << std::endl;

    } catch (const char* msg) {
         std::cerr << msg << std::endl;
         sqlite3_free(errMsg);
         sqlite3_close(db);
         return false;
    }

    return true;

}

bool sqllitedb::db_table_list()
{
    std::string querry = "SELECT name FROM my_db.sqlite_master WHERE type='table'";

    try {

         if (sqlite3_exec(db, querry.c_str(), callback, NULL, &errMsg) != SQLITE_OK)
         {
            throw errMsg;
         }

    } catch (const char* msg) {
         std::cerr << msg << std::endl;
         sqlite3_free(errMsg);
         sqlite3_close(db);
         return false;
    }

    return true;
}

bool sqllitedb::exec_querry(std::string querry)
{
    try {

         if (sqlite3_exec(db, querry.c_str(), NULL, NULL, &errMsg) != SQLITE_OK)
         {
            throw errMsg;
         }
         std::cout << "Querry execed" << std::endl;

    } catch (const char* msg) {
         std::cerr << msg << std::endl;
         sqlite3_free(errMsg);
         sqlite3_close(db);
         return false;
    }

    return true;
}
bool sqllitedb::create_table(std::string querry)
{
    try {

        if (sqlite3_exec(db, querry.c_str(), NULL, NULL, &errMsg) != SQLITE_OK)
        {
           throw errMsg;
        }
        std::cout << "Table created" << std::endl;

    } catch (const char* msg) {
        std::cerr << msg << std::endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return false;
    }
    return true;
}

bool sqllitedb::update_table(std::string querry)
{
    try {

        if (sqlite3_exec(db, querry.c_str(), NULL, NULL, &errMsg) != SQLITE_OK)
        {
           throw errMsg;
        }
        std::cout << "Table updated" << std::endl;

    } catch (const char* msg) {
        std::cerr << msg << std::endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return false;
    }
    return true;
}

bool sqllitedb::delete_table(std::string querry)
{
    try {

        if (sqlite3_exec(db, querry.c_str(), NULL, NULL, &errMsg) != SQLITE_OK)
        {
           throw errMsg;
        }
        std::cout << "Table deleted" << std::endl;

    } catch (const char* msg) {
        std::cerr << msg << std::endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return false;
    }
    return true;
}


sqllitedb::sqllitedb(const sqllitedb &sqllitedbObj)
{
    return sqllitedb(sqllitedbObj.dbname);
}

sqllitedb &sqllitedb::operator=(const sqllitedb &sqllitedbObj)
{
    this->db = sqllitedbObj.db;
    this->column_count = sqllitedbObj.column_count;
    this->table_list = sqllitedbObj.table_list;
    this->dbname = sqllitedbObj.dbname;
    this->table = sqllitedbObj.table;
    this->row_count = sqllitedbObj.row_count;
    this->column_count = sqllitedbObj.column_count;
}

sqllitedb::~sqllitedb()
{
    /*will write*/
}
