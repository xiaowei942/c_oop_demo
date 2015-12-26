#include <stdio.h>
#include <malloc.h>
#include "animal.h"
#include "animal_def.h"

static void Animal_V_Eat(ObjectPtr obj)
{
    puts("动物吃东西");
}

static void Animal_V_Breed(ObjectPtr obj)
{
    puts("动物生育");
}

void Animal_InitInfo(Animal *ptr) 
{
    ptr->info.tag = MAKE_CLASS_TAG(ClassID_Animal);
    ptr->info.vfun = &ptr->func;

    //! 建立继承关系
    class_inhert_map[ClassID_Animal] = ClassID_Base;
}

void Animal_Construct(ObjectPtr obj)
{
    class_info_t* info = (class_info_t*)obj;

    //! 初始化虚函数
    Animal_Func* func = (Animal_Func*)(info->vfun);
    func->Eat = Animal_V_Eat;
    func->Breed = Animal_V_Breed;

    //! 初始化数据
    Animal_Data* data = (Animal_Data*)(info + 1);
    data->health = 100;
}

void Animal_Destruct(ObjectPtr obj)
{
    //! DO NOTHING
}

ObjectPtr Animal_New()
{
    Animal *ptr = malloc(sizeof(Animal));
    if (ptr != NULL) {
        Animal_InitInfo(ptr);
        Animal_Construct(ptr);
    }

    return ptr;
}

void Animal_Delete(ObjectPtr obj)
{
    Animal_Destruct(obj);
    free(obj);
}

void Animal_Eat(ObjectPtr obj)
{
    if (is_instance_of(obj, ClassID_Animal)) {
        class_info_t *info = (class_info_t*)obj;
        Animal_Func *func = info->vfun;
        if (func->Eat)
            func->Eat(obj);
    }
}

void Animal_Breed(ObjectPtr obj)
{
    if (is_instance_of(obj, ClassID_Animal)) {
        class_info_t *info = (class_info_t*)obj;
        Animal_Func *func = info->vfun;
        if (func->Breed)
            func->Breed(obj);
    }
}

