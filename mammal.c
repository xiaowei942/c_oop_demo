#include <stdio.h>
#include "mammal.h"
#include "mammal_def.h"

void Mammal_Class_Init()
{
    //!建立继承关系
    class_inhert_map[ClassID_Mammal] = ClassID_Animal;
    //!TODO: 其它初始化功能
}

void Mammal_Class_Destory()
{
    //!TODO: 其它释放功能
}

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
    func->base._Breed = Mammal_Breed;

    //!TODO: 初始化数据
}

void Mammal_Destruct(ObjectPtr obj)
{
    //!TODO: 析构对象
    
    Animal_Destruct(obj);
}

BASE_FUNC_DEFINE(Mammal, OOP)
