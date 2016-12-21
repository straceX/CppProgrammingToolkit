/**
 * @file   sqllite_db_operations.h
 * @Author sX
 * @date   December, 2016
 * @brief  Brief description of file.
 **/

#ifndef SQLLITE_DB_OPERATIONS_H
#define SQLLITE_DB_OPERATIONS_H

#if defined(_pragma_once_support)
    #pragma once
#endif

#include "sqlite3.h"

#include <iostream>
#include <vector>
#include <map>
class sqllitedb final
{

private:
    sqlite3 *db;
    const std::string dbname;
    char *errMsg;
    std::vector< std::map<std::string,std::string> > table;

    size_t row_count = 0;
    size_t column_count = 0;



    int callback(void *arg, int argc, char **argv, char **colName)
    {
        int *c = arg;
        *c = atoi(argv[0]);
        return 0;
    }

    int callback2(void *arg, int argc, char **argv, char **colName)
    {
        std::map<std::string,std::string> row;
        for(int i=0; i<argc; i++)
        {
            row.insert(std::pair<colName[i],argv[i] ? argv[i] : "NULL">);
            if(!(i%row_count))
            {
                table.push_back(row);
                row.clear();
            }
        }
        return 0;
    }


public:

    sqllitedb(const std::string &dbname);
    sqllitedb(const sqllitedb &sqllitedbObj);
    sqllitedb &operator=(const sqllitedb &sqllitedbObj);
    ~sqllitedb();

    std::string db_version();
    int sqllitedb::db_version_number();
    bool sqllitedb::table_row_count(std::string table_name,int &row_count);
    bool sqllitedb::db_table_list();

    bool exec_querry(std::string querry);

    bool create_table(std::string querry);
    bool update_table(std::string querry);
    bool delete_table(std::string querry);

    bool delete_rows(std::vector<std::string> cond);

protected:
    std::vector<std::string> table_list;

};


#endif // SQLLITE_DB_OPERATIONS_H
