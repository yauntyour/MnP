#ifndef __SYFIO__H__
#define __SYFIO__H__
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "fiotypes.h"

typedef struct Syfio //synchronization I/O
{
    FILE *stream;
    size_t len;
    char* err;
} Syfio;

extern Syfio* Syfio_create(const char* filepath,char* mode){
    Syfio syfio;
    FILE* p = fopen(filepath,mode);
    if (p == NULL)
    {
        syfio.err = FILEOPENERR;
        syfio.stream = NULL;
        syfio.len = 0;
        return &syfio;
    }
    syfio.err = NULL;
    fseek(p,0L,SEEK_END);
    syfio.len = ftell(p);
    rewind(p);
    syfio.stream = p;
    return &syfio;
}
#endif  //!__SYFIO__H__