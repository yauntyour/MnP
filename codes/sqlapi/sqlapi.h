#pragma once
#ifndef __SQLAPI__H__
#define __SQLAPI__H__

#include <iostream>
#include <string>
#include <stdio.h>
#include "../mysql/mysql.h"
#pragma comment(lib, "../lib/mysql.lib")

int SQLAPI()
{
    MYSQL tsdb_db;
    MYSQL_RES *res;
    MYSQL_ROW row;
    try
    {
        mysql_init(&tsdb_db);
        if (!mysql_real_connect(&tsdb_db, "127.0.0.1", "root", "", "tsdb", 3306, NULL, 0))
        {
            perror("MySQL connect fail");
        };
        printf("Server::stat[out]:%s",mysql_stat(&tsdb_db));
        mysql_real_query(&tsdb_db, "select * from test;", strlen("describe test;"));
        res = mysql_store_result(&tsdb_db);
        while (row = mysql_fetch_row(res))
        {
            if (row[0] != NULL)
            {
                size_t i = 0;
                while (row[i])
                {
                    printf("%s ", row[i]);
                    i++;
                }
                printf("\n");
            }else{
                continue;
            }
        }
        mysql_free_result(res);
        mysql_close(&tsdb_db);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
#endif //!__SQLAPI__H__