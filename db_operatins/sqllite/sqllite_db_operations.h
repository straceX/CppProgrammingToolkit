#ifndef SQLLITE_DB_OPERATIONS_H
#define SQLLITE_DB_OPERATIONS_H

#include "sqlite3.h"
#include <iostream>

class sqllitedb {
private:
    sqlite3 *db;
    const std::string dbname;
    char *errMsg;
public:
    sqllitedb(const std::string &dbname);

    std::string db_version();

    bool exec_querry(std::string querry);

    bool create_table(std::string querry);
    bool update_table(std::string querry);
    bool delete_table(std::string querry);

};


#endif // SQLLITE_DB_OPERATIONS_H
