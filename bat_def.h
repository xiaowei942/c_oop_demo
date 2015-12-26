#ifndef __BAT_DEF_H__
#define __BAT_DEF_H__

#include "mammal_def.h"

typedef struct {
    Mammal_Data base;
} Bat_Data;

typedef struct {
    Mammal_Func base;
} Bat_Func;

typedef struct {
    class_info_t info;
    Bat_Data data;
    Bat_Func func;
} Bat;

void Bat_Class_Init();
void Bat_Class_Destory();

void Bat_Construct(ObjectPtr obj);
void Bat_Destruct(ObjectPtr obj);

#endif //__BAT_DEF_H__
