#include <stdio.h>
#include <malloc.h>
#include "penguin.h"
#include "penguin_def.h"

static void Swallow_Eat(ObjectPtr obj)
{
    puts("燕子吃虫子");
}

void Swallow_Construct(ObjectPtr obj)
{
    Bird_Construct(obj);

    class_info_t* info = (class_info_t*)obj;

    //!TODO: 初始化虚函数
    Swallow_Func* func = (Swallow_Func*)(info->vfun);
    func->base.base.Eat = Swallow_Eat;

    //!TODO: 初始化数据
}

void Swallow_Destruct(ObjectPtr *obj)
{
    //!TODO: 析构对象
    
    Bird_Destruct(obj);
}

void Swallow_InitInfo(Swallow *ptr) 
{
    ptr->info.tag = MAKE_CLASS_TAG(ClassID_Swallow);
    ptr->info.vfun = &ptr.func;

    //! 建立继承关系
    class_inhert_map[ClassID_Swallow] = ClassID_Bird;
}

ObjectPtr Swallow_New()
{
    Swallow *ptr = malloc(sizeof(Swallow));
    if (ptr != NULL) {
        Swallow_InitInfo(ptr);
        Swallow_Construct(ptr);
    }

    return ptr;
}

void Swallow_Delete(ObjectPtr obj)
{
    Swallow_Destruct(obj);
    free(obj);
}

