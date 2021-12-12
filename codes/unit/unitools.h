#ifndef __UNITOOLS__H__
#define __UNITOOLS__H__
#include <stdlib.h>
size_t bufflen(const void *buff)
{
    size_t i = 0;
    while (((char*)buff)[i] != NULL)
    {
        i++;
    }
    return i;
}
#endif  //!__UNITOOLS__H__