#ifndef __PENGUIN_DEF_H__
#define __PENGUIN_DEF_H__

#include "bird_def.h"

typedef struct {
    Bird_Data base;
} Penguin_Data;

typedef struct {
    Bird_Func base;
} Penguin_Func;

typedef struct {
    class_info_t info;
    Penguin_Data data;
    Penguin_Func func;
} Penguin;

void Penguin_Construct(ObjectPtr obj);
void Penguin_Destruct(ObjectPtr obj);

#endif //__PENGUIN_DEF_H__
