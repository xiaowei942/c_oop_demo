#ifndef __TIGER_DEF_H__
#define __TIGER_DEF_H__

#include "oop_defines.h"
#include "mammal_def.h"

typedef struct {
    Mammal_Data base;
} Tiger_Data;

typedef struct {
    Mammal_Func base;
} Tiger_Func;

CLASS_BASIC_INFO(Tiger);

#endif //__TIGER_DEF_H__
