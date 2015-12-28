#ifndef __BIRD_DEF__
#define __BIRD_DEF__

#include "animal_def.h"

typedef struct {
    Animal_Data base;
} Bird_Data;

typedef struct {
    Animal_Func base;
} Bird_Func;

CLASS_BASIC_INFO(Bird);

#endif  //__BIRD_DEF__
