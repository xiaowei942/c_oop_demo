#include <stdio.h>
#include <malloc.h>
#include "bat.h"
#include "bat_def.h"

void Bat_Class_Init()
{
    //!建立继承关系
    class_inhert_map[ClassID_Bat] = ClassID_Mammal;
    //!TODO: 其它初始化功能
}

void Bat_Class_Destory()
{
    //!TODO: 其它释放功能
}

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
    func->base.base._Eat = Bat_Eat;

    //!TODO: 初始化数据
}

void Bat_Destruct(ObjectPtr obj)
{
    //!TODO: 析构对象
    
    Mammal_Destruct(obj);
}

CLASS_FUNC_DEFINE(Bat, OOP)
