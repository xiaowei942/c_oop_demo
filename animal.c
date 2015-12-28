#include <stdio.h>
#include "animal.h"
#include "animal_def.h"

void Animal_Class_Init()
{
    //!建立继承关系
    class_inhert_map[ClassID_Animal] = ClassID_Base;
    //!TODO: 其它初始化功能
}

void Animal_Class_Destory()
{
    //!TODO: 其它释放功能
}

static void Animal_V_Eat(ObjectPtr obj)
{
    puts("动物吃东西");
}

static void Animal_V_Breed(ObjectPtr obj)
{
    puts("动物生育");
}

void Animal_Construct(ObjectPtr obj)
{
    class_info_t* info = (class_info_t*)obj;

    //! 初始化虚函数
    Animal_Func* func = (Animal_Func*)(info->vfun);
    func->_Eat = Animal_V_Eat;
    func->_Breed = Animal_V_Breed;

    //! 初始化数据
    Animal_Data* data = (Animal_Data*)(info + 1);
    data->_health = 100;
}

void Animal_Destruct(ObjectPtr obj)
{
    //! DO NOTHING
}

VIRTUAL_FUNC_DEFINE(Animal, Eat)
VIRTUAL_FUNC_DEFINE(Animal, Breed)

BASE_FUNC_DEFINE(Animal, OOP)
