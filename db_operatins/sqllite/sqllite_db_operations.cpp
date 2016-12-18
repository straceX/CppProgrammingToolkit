#include "sqllite_db_operations.h"

class sqllitedb {
private:
    sqlite3 *db;
    const std::string dbname;
public:
    sqllitedb(const std::string &dbname) : dbname(dbname)
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

    std::string db_version()
    {
        return std::string(sqlite3_libversion());
    }

    bool db_exec(std::string querry)
    {
        char *errMsg;
        try {

            if (sqlite3_exec(db, querry.c_str(), NULL, NULL, &errMsg) != SQLITE_OK)
            {
                throw errMsg;
            }
        }
        catch (const char* msg) {
            std::cerr << msg << std::endl;
            sqlite3_free(errMsg);
            sqlite3_close(db);
            return false;
        }

        return true;
    }

};
