#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <string>

//#include <winsock2.h>
//#include <windows.h>
//#include <pthread.h>
#include "../FIO/fio.h"
//using namespace std;

int main(int argc, char const *argv[])
{
    Asfio as = Asfio_create("K:\\Dome\\MnP\\bin\\000.txt","w+");
    Asfio_write(&as,"SB");
//    _sleep(100L);
//    CALLBLACK_TH th = Asfio_read(&as);
//    char* str = Asfio_callblack(th);
//    printf("%s\n",str);
    Asfio_close(&as,0);
    perror("Error:(_null_)");
    return 0;
}
