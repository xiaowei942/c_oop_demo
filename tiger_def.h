#ifndef __TIGER_DEF_H__
#define __TIGER_DEF_H__

#include "mammal_def.h"

typedef struct {
    Mammal_Data base;
} Tiger_Data;

typedef struct {
    Mammal_Func base;
} Tiger_Func;

typedef struct {
    class_info_t info;
    Tiger_Data data;
    Tiger_Func func;
} Tiger;

void Tiger_Construct(ObjectPtr obj);
void Tiger_Destruct(ObjectPtr obj);

#endif //__TIGER_DEF_H__
