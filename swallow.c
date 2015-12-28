#include <stdio.h>
#include "swallow.h"
#include "swallow_def.h"

void Swallow_Class_Init()
{
    //!建立继承关系
    class_inhert_map[ClassID_Swallow] = ClassID_Bird;
    //!TODO: 其它初始化功能
}

void Swallow_Class_Destory()
{
    //!TODO: 其它释放功能
}

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
    func->base.base._Eat = Swallow_Eat;

    //!TODO: 初始化数据
}

void Swallow_Destruct(ObjectPtr obj)
{
    //!TODO: 析构对象
    
    Bird_Destruct(obj);
}

BASE_FUNC_DEFINE(Swallow, OOP)
