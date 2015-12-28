#ifndef __ANIMAL_DEF_H__
#define __ANIMAL_DEF_H__

#include "oop_common.h"

typedef struct {
    int _health; 
} Animal_Data;

typedef struct {
    void (*_Eat)();
    void (*_Breed)();
} Animal_Func;

typedef struct {
    class_info_t info;
    Animal_Data data;
    Animal_Func func;
} Animal;

void Animal_Class_Init();
void Animal_Class_Destory();

void Animal_Construct(ObjectPtr obj);
void Animal_Destruct(ObjectPtr obj);

#endif  //__ANIMAL_DEF_H__
