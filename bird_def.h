#ifndef __BIRD_DEF__
#define __BIRD_DEF__

#include "animal_def.h"

typedef struct {
    Animal_Data base;
} Bird_Data;

typedef struct {
    Animal_Func base;
} Bird_Func;

typedef struct {
    class_info_t info;
    Bird_Data data;
    Bird_Func func;
} Bird;

void Bird_Construct(ObjectPtr obj);
void Bird_Destruct(ObjectPtr obj);

#endif  //__BIRD_DEF__
