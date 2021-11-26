#ifndef __ASFIO__H__
#define __ASFIO__H__
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <assert.h>
#include "fiotypes.h"

typedef struct Asfio //asynchronous I/O
{
    FILE *Stream;
    //luck with asyio
    pthread_mutex_t AsfioLuck;
} Asfio;
//pthread_t redefine
typedef unsigned long long CALLBLACK_TH;

extern Asfio Asfio_create(const char *filepath, char *mode)
{
    Asfio asfio;
    //create a luck
    pthread_rwlock_init(&asfio.AsfioLuck, NULL);
    //get file port.
    FILE *p = fopen(filepath, mode);
    if (p == NULL)
    {
        fprintf(stderr,"%s",FILEOPENERR);
        asfio.Stream = NULL;
        return asfio;
    }
    //get file stream
    asfio.Stream = p;
    return asfio;
}

//read function
void *__read__(void *args)
{
    Asfio *asp = (Asfio *)args;
    pthread_rwlock_rdlock(&asp->AsfioLuck);
    char *fileText = (char *)malloc(FIO_TELL(asp->Stream) + 1);
    fseek(asp->Stream,0L,SEEK_SET);
    if (fread(fileText, sizeof(char), sizeof(fileText), asp->Stream) == sizeof(fileText))
    {
        rewind(asp->Stream);
        pthread_rwlock_unlock(&asp->AsfioLuck);
        return (void *)fileText;
    }
    else
    {
        rewind(asp->Stream);
        pthread_rwlock_unlock(&asp->AsfioLuck);
        fprintf(stderr,"%s\n","read fail");
        return (void *)NULL;
    }
}
extern CALLBLACK_TH Asfio_read(Asfio *asp)
{
    if (asp != NULL)
    {
        pthread_t th;
        if (pthread_create(&th, NULL, __read__, (void *)asp) == 0)
        {
            return th;
        }
        else
        {
            fprintf(stderr, "%s\n", "thread create fail");
            return -1;
        }
    }
    else
    {
        fprintf(stderr, "%s", FILEIOPOTERR);
        return 0;
    }
}
//callblack function
extern char *Asfio_callblack(CALLBLACK_TH th)
{
    if (th != -1 & th != 0)
    {
        char *res;
        if (pthread_join(th, (void **)&res) == 0)
        {
            if (res != NULL)
            {
                return res;
            }
            else
            {
                fprintf(stderr, "%s\n", "Callblack function::return NULL");
                return NULL;
            }
        }
        else
        {
            fprintf(stderr, "%s\n", "Callblack function::join() error.");
            return NULL;
        }
    }
    else
    {
        fprintf(stderr, "%s\n", "Callblack function error.");
        return NULL;
    }
}

//define a args struct
typedef struct
{
    Asfio *asp;
    const char *Element;
} W_args;
//write function
void *__write__(void *args)
{
    Asfio *asp = ((W_args *)args)->asp;
    pthread_rwlock_wrlock(&asp->AsfioLuck);
    const char *Element = ((W_args *)args)->Element;
    if (fwrite(Element, sizeof(char), sizeof(Element), asp->Stream) != sizeof(Element))
    {
        fprintf(stderr,"%s\n","writer fail");
        pthread_rwlock_unlock(&asp->AsfioLuck);
        return (void *)-1;
    }
    pthread_rwlock_unlock(&asp->AsfioLuck);
    return (void *)0;
};

extern int Asfio_write(Asfio *asp, const char *Element)
{
    if (asp != NULL)
    {
        W_args *args;
        args->asp = asp;
        args->Element = Element;
        pthread_t th;
        if (pthread_create(&th, NULL, __write__, (void *)args) == 0)
        {
            pthread_detach(th);
            return 1;
        }
        else
        {
            fprintf(stderr, "%s\n", "thread create fail");
            return 0;
        }
    }
    else
    {
        fprintf(stderr, "%s%s", FILEIOPOTERR);
        return 0;
    }
}
//Asfio close function
extern int Asfio_close(Asfio *asp, int mode)
{
    if (mode == 0)
    {
        pthread_rwlock_destroy(&asp->AsfioLuck);
        fclose(asp->Stream);
        return 1;
    }
    else if (mode == -1)
    {
        pthread_rwlock_destroy(&asp->AsfioLuck);
        free(asp);
        Asfio new_asp;
        asp = &new_asp;
        return 1;
    }
    else
    {
        fprintf(stderr, "%s\n", "didn't have this mode.");
        return 0;
    }
}
#endif //!__ASFIO__H__