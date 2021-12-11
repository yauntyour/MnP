#pragma once
#ifndef __SQLAPI__H__
#define __SQLAPI__H__

#include <iostream>
#include <string>
#include <vector>

#include <stdio.h>
#include "../mysql/mysql.h"
#pragma comment(lib, "../lib/mysql.lib")

// Test db: "127.0.0.1", "root", "", "tsdb", 3306, NULL, 0
MYSQL MySQL_create(const char *host, const char *user, const char *passwd, const char *db, unsigned int port, const char *unix_socket, unsigned long clientflag)
{
    MYSQL mysql_db;
    try
    {
        mysql_init(&mysql_db);
        if (!mysql_real_connect(&mysql_db, host, user, passwd, db, port, unix_socket, clientflag))
        {
            perror("MySQL connect fail");
        };
        printf("Server::stat[out]:%s\n", mysql_stat(&mysql_db));
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    return mysql_db;
}

std::vector<std::string> MySQL_select(MYSQL mysql_db,const char *SELECT)
{
    MYSQL_RES *res;
    MYSQL_ROW row;
    std::vector<std::string> sele;
    if (mysql_real_query(&mysql_db, SELECT, strlen(SELECT)) == 0)
    {
        res = mysql_store_result(&mysql_db);
        while (row = mysql_fetch_row(res))
        {
            for (size_t i = 0; i < mysql_num_fields(res); i++)
            {
                sele.push_back(row[i]);
            }
        }
        mysql_free_result(res);
    }
    else
    {
        printf("Failed to query: %s\n", mysql_error(&mysql_db));
    }
    return sele;
}

//表名 table //指定列(column1,column2,column3,...) // data list (value1,value2,value3,...)
int MySQL_insert(MYSQL mysql_db,
                 //表名 table
                 char *table,
                 //指定列(column1,column2,column3,...)
                 char *column,
                 // data list (value1,value2,value3,...)
                 char *ver)
{
    std::string str = "insert into ";
    str = str + table + column + "VALUES" + ver;
    if (mysql_query(&mysql_db, str.c_str()))
    {
        printf("Failed to query: %s\n", mysql_error(&mysql_db));
        return -1;
    }
    return 0;
};

class ClassMySQL
{
private:
    MYSQL mysql_db;
public:
    ClassMySQL(const char *host, const char *user, const char *passwd, const char *db, unsigned int port, const char *unix_socket, unsigned long clientflag)
    {
        MySQL_create(host, user, passwd, db, port, unix_socket, clientflag);
    };
    ~ClassMySQL()
    {
        mysql_close(&mysql_db);
    };
    int ClassMySQL_insert(
        //表名 table
        char *table,
        //指定列(column1,column2,column3,...)
        char *column,
        // data list (value1,value2,value3,...)
        char *ver){
            return MySQL_insert(mysql_db,table,column,ver);
    };
    std::vector<std::string> ClassMySQL_select(MYSQL mysql_db, char *SELECT){
        return MySQL_select(mysql_db,SELECT);
    }
};
#endif //!__SQLAPI__H__