#include <stdio.h>
#include <malloc.h>
#include "mammal.h"
#include "mammal_def.h"

static void Mammal_Breed(ObjectPtr obj)
{
    puts("胎生");
}

void Mammal_Construct(ObjectPtr obj)
{
    Animal_Construct(obj);

    class_info_t* info = (class_info_t*)obj;

    //!TODO: 初始化虚函数
    Mammal_Func* func = (Mammal_Func*)(info->vfun);
    func->base.Breed = Mammal_Breed;

    //!TODO: 初始化数据
}

void Mammal_Destruct(ObjectPtr obj)
{
    //!TODO: 析构对象
    
    Animal_Destruct(obj);
}

void Mammal_InitInfo(Mammal *ptr) 
{
    ptr->info.tag = MAKE_CLASS_TAG(ClassID_Mammal);
    ptr->info.vfun = &ptr->func;

    //! 建立继承关系
    class_inhert_map[ClassID_Mammal] = ClassID_Animal;
}

ObjectPtr Mammal_New()
{
    Mammal *ptr = malloc(sizeof(Mammal));
    if (ptr != NULL) {
        Mammal_InitInfo(ptr);
        Mammal_Construct(ptr);
    }

    return ptr;
}

void Mammal_Delete(ObjectPtr obj)
{
    Mammal_Destruct(obj);
    free(obj);
}

