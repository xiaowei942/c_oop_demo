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
    func->base.base._Eat = Tiger_Eat;

    //!TODO: 初始化数据
}

void Tiger_Destruct(ObjectPtr obj)
{
    //!TODO: 析构对象
    
    Mammal_Destruct(obj);
}

CLASS_FUNC_DEFINE(Tiger, OOP)
