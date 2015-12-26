#include <stdio.h>
#include <malloc.h>
#include "penguin.h"
#include "penguin_def.h"

static void Tiger_Eat(ObjectPtr obj)
{
    puts("企鹅吃鱼");
}

void Tiger_Construct(ObjectPtr obj)
{
    Bird_Construct(obj);

    class_info_t* info = (class_info_t*)obj;

    //!TODO: 初始化虚函数
    Tiger_Func* func = (Tiger_Func*)(info->vfun);
    func->base.base.Eat = Tiger_Eat;

    //!TODO: 初始化数据
}

void Tiger_Destruct(ObjectPtr *obj)
{
    //!TODO: 析构对象
    
    Bird_Destruct(obj);
}

void Tiger_InitInfo(Tiger *ptr) 
{
    ptr->info.tag = MAKE_CLASS_TAG(ClassID_Tiger);
    ptr->info.vfun = &ptr.func;

    //! 建立继承关系
    class_inhert_map[ClassID_Tiger] = ClassID_Bird;
}

ObjectPtr Tiger_New()
{
    Tiger *ptr = malloc(sizeof(Tiger));
    if (ptr != NULL) {
        Tiger_InitInfo(ptr);
        Tiger_Construct(ptr);
    }

    return ptr;
}

void Tiger_Delete(ObjectPtr obj)
{
    Tiger_Destruct(obj);
    free(obj);
}

