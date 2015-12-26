#ifndef __ANIMAL_H__
#define __ANIMAL_H__

#include "common.h"

ObjectPtr Animal_New();
void Animal_Delete(ObjectPtr obj);

void Animal_Eat(ObjectPtr obj);
void Animal_Breed(ObjectPtr obj);

#endif  //__ANIMAL_H__
