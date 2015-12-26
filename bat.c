#include <stdio.h>
#include <malloc.h>
#include "bat.h"
#include "bat_def.h"

static void Bat_Eat(ObjectPtr obj)
{
    puts("蝙蝠吃飞虫");
}

void Bat_Construct(ObjectPtr obj)
{
    Mammal_Construct(obj);

    class_info_t* info = (class_info_t*)obj;

    //!TODO: 初始化虚函数
    Bat_Func* func = (Bat_Func*)(info->vfun);
    func->base.base.Eat = Bat_Eat;

    //!TODO: 初始化数据
}

void Bat_Destruct(ObjectPtr obj)
{
    //!TODO: 析构对象
    
    Mammal_Destruct(obj);
}

void Bat_InitInfo(Bat *ptr) 
{
    ptr->info.tag = MAKE_CLASS_TAG(ClassID_Bat);
    ptr->info.vfun = &ptr->func;

    //! 建立继承关系
    class_inhert_map[ClassID_Bat] = ClassID_Mammal;
}

ObjectPtr Bat_New()
{
    Bat *ptr = malloc(sizeof(Bat));
    if (ptr != NULL) {
        Bat_InitInfo(ptr);
        Bat_Construct(ptr);
    }

    return ptr;
}

void Bat_Delete(ObjectPtr obj)
{
    Bat_Destruct(obj);
    free(obj);
}

