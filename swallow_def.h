#ifndef __SWALLOW_DEF_H__
#define __SWALLOW_DEF_H__

#include "bird_def.h"

typedef struct {
    Bird_Data base;
} Swallow_Data;

typedef struct {
    Bird_Func base;
} Swallow_Func;

typedef struct {
    class_info_t info;
    Swallow_Data data;
    Swallow_Func func;
} Swallow;

void Swallow_Construct(ObjectPtr obj);
void Swallow_Destruct(ObjectPtr obj);

#endif //__SWALLOW_DEF_H__
