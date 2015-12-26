#include <stdio.h>
#include <malloc.h>
#include "penguin.h"
#include "penguin_def.h"

void Penguin_Class_Init()
{
    //!建立继承关系
    class_inhert_map[ClassID_Penguin] = ClassID_Bird;
    //!TODO: 其它初始化功能
}

void Penguin_Class_Destory()
{
    //!TODO: 其它释放功能
}

static void Penguin_Eat(ObjectPtr obj)
{
    puts("企鹅吃鱼");
}

void Penguin_Construct(ObjectPtr obj)
{
    Bird_Construct(obj);

    class_info_t* info = (class_info_t*)obj;

    //!TODO: 初始化虚函数
    Penguin_Func* func = (Penguin_Func*)(info->vfun);
    func->base.base.Eat = Penguin_Eat;

    //!TODO: 初始化数据
}

void Penguin_Destruct(ObjectPtr obj)
{
    //!TODO: 析构对象
    
    Bird_Destruct(obj);
}

void Penguin_InitInfo(Penguin *ptr) 
{
    ptr->info.tag = MAKE_CLASS_TAG(ClassID_Penguin);
    ptr->info.vfun = &ptr->func;
}

ObjectPtr Penguin_New()
{
    Penguin *ptr = malloc(sizeof(Penguin));
    if (ptr != NULL) {
        Penguin_InitInfo(ptr);
        Penguin_Construct(ptr);
    }

    return ptr;
}

void Penguin_Delete(ObjectPtr obj)
{
    Penguin_Destruct(obj);
    free(obj);
}

