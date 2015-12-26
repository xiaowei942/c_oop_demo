#include <stdio.h>
#include <malloc.h>
#include "tiger.h"
#include "tiger_def.h"

void Tiger_Class_Init()
{
    //!建立继承关系
    class_inhert_map[ClassID_Tiger] = ClassID_Mammal;
    //!TODO: 其它初始化功能
}

void Tiger_Class_Destory()
{
    //!TODO: 其它释放功能
}

static void Tiger_Eat(ObjectPtr obj)
{
    puts("老虎要吃肉");
}

void Tiger_Construct(ObjectPtr obj)
{
    Mammal_Construct(obj);

    class_info_t* info = (class_info_t*)obj;

    //!TODO: 初始化虚函数
    Tiger_Func* func = (Tiger_Func*)(info->vfun);
    func->base.base.Eat = Tiger_Eat;

    //!TODO: 初始化数据
}

void Tiger_Destruct(ObjectPtr obj)
{
    //!TODO: 析构对象
    
    Mammal_Destruct(obj);
}

void Tiger_InitInfo(Tiger *ptr) 
{
    ptr->info.tag = MAKE_CLASS_TAG(ClassID_Tiger);
    ptr->info.vfun = &ptr->func;

    //! 建立继承关系
    class_inhert_map[ClassID_Tiger] = ClassID_Mammal;
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

