#ifndef __MAMMAL_DEF_H__
#define __MAMMAL_DEF_H__

#include "animal_def.h"

typedef struct {
    Animal_Data base;
} Mammal_Data;

typedef struct {
    Animal_Func base;
} Mammal_Func;

typedef struct {
    class_info_t info;
    Mammal_Data data;
    Mammal_Func func;
} Mammal;

void Mammal_Class_Init();
void Mammal_Class_Destory();

void Mammal_Construct(ObjectPtr obj);
void Mammal_Destruct(ObjectPtr obj);

#endif //__MAMMAL_DEF_H__
