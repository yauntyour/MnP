#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <iostream>
#include <string>
#include <vector>
//#include <winsock2.h>
//#include <windows.h>
//#include <pthread.h>
#include "../FIO/fio.h"
#include "../sqlapi/sqlapi.h"
//#include "../libevent/event.h"
// using namespace std;

int main(int argc, char const *argv[])
{
    clock_t s,e;
    double Total_time;
    Asfio as = Asfio_create("K:\\Dome\\MnP\\bin\\000.txt","rb+");

    s = clock();
    Asfio_write(&as,"HelloWorld-------");
    e = clock();
    Total_time = (double)(e - s) / CLOCKS_PER_SEC;
    printf("\n函数运行时间:%0.3fms \n", Total_time);

    s = clock();
    CALLBLACK_TH th = Asfio_readall(&as);
    char* str = (char*)Asfio_callblack(th);
    e = clock();
    Total_time = (double)(e - s) / CLOCKS_PER_SEC;
    printf("\n函数运行时间:%0.3fms \n", Total_time);
    Asfio_close(&as,0);

    
    MYSQL db = MySQL_create("127.0.0.1", "root", "", "tsdb", 3306, NULL, 0);
    MySQL_insert(db,"test","(name,age)","('SB',12)");

    std::vector<std::string> sele = MySQL_select(db,"select * from test");
    
    for (std::vector<std::string>::iterator it = sele.begin(); it != sele.end(); it++) {
		std::cout << *it << std::endl;
	}
    mysql_close(&db);
    
    return 0;
}
