#ifndef __BAT_DEF_H__
#define __BAT_DEF_H__

#include "mammal_def.h"
#include "oop_defines.h"

typedef struct {
    Mammal_Data base;
} Bat_Data;

typedef struct {
    Mammal_Func base;
} Bat_Func;

CLASS_BASIC_INFO(Bat);

#endif //__BAT_DEF_H__
