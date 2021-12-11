#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <string>

//#include <winsock2.h>
//#include <windows.h>
//#include <pthread.h>
#include "../FIO/fio.h"
#include "../sqlapi/sqlapi.h"
// using namespace std;

int main(int argc, char const *argv[])
{
    /*
    Asfio as = Asfio_create("K:\\Dome\\MnP\\bin\\000.txt","rb+");
    Asfio_write(&as,"HelloWorld");
    _sleep(100L);
    CALLBLACK_TH th = Asfio_read(&as);
    char* str = (char*)Asfio_callblack(th);
    printf("%s\n",str);
    _sleep(1000);
    perror("Error:(_null_)");
    Asfio_close(&as,0);
    */
    MYSQL db = MySQL_create("127.0.0.1", "root", "", "tsdb", 3306, NULL, 0);
    MySQL_insert(db,"test","(name,age)","('SB',12)");
    MySQL_select(db,"select * from test");
    mysql_close(&db);
    return 0;
}
