#ifndef __ANIMAL_DEF_H__
#define __ANIMAL_DEF_H__

typedef struct {
    int health; 
} Animal_Data;

typedef struct {
    void (*Eat)();
    void (*Breed)();
} Animal_Func;

typedef struct {
    class_info_t info;
    Animal_Data data;
    Animal_Func func;
} Animal;

void Animal_Construct(ObjectPtr obj);
void Animal_Destruct(ObjectPtr obj);

#endif  //__ANIMAL_DEF_H__
