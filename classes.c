#include "animal_def.h"
#include "bird_def.h"
#include "mammal_def.h"
#include "penguin_def.h"
#include "swallow_def.h"
#include "bat_def.h"
#include "tiger_def.h"

void ClassInit()
{
    Animal_Class_Init();
    Bird_Class_Init();
    Mammal_Class_Init();
    Penguin_Class_Init();
    Swallow_Class_Init();
    Bat_Class_Init();
    Tiger_Class_Init();
}

void ClassDestory()
{
    Tiger_Class_Destory();
    Bat_Class_Destory();
    Swallow_Class_Destory();
    Penguin_Class_Destory();
    Mammal_Class_Destory();
    Bird_Class_Destory();
    Animal_Class_Destory();
}
