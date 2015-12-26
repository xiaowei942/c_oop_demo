#include <stdio.h>
#include <malloc.h>
#include "bird.h"
#include "bird_def.h"

void Bird_Class_Init()
{
    //!建立继承关系
    class_inhert_map[ClassID_Bird] = ClassID_Animal;
    //!TODO: 其它初始化功能
}

void Bird_Class_Destory()
{
    //!TODO: 其它释放功能
}

static void Bird_V_Breed(ObjectPtr obj)
{
    puts("蛋生");
}

void Bird_InitInfo(Bird *ptr) 
{
    ptr->info.tag = MAKE_CLASS_TAG(ClassID_Bird);
    ptr->info.vfun = &ptr->func;
}

void Bird_Construct(ObjectPtr obj)
{
    Animal_Construct(obj);

    class_info_t* info = (class_info_t*)obj;

    //!TODO: 初始化虚函数
    Bird_Func* func = (Bird_Func*)(info->vfun);
    func->base.Breed = Bird_V_Breed;

    //!TODO: 初始化数据
}

void Bird_Destruct(ObjectPtr obj)
{
    //!TODO: 析构对象
    
    Animal_Destruct(obj);
}

ObjectPtr Bird_New()
{
    Bird *ptr = malloc(sizeof(Bird));
    if (ptr != NULL) {
        Bird_InitInfo(ptr);
        Bird_Construct(ptr);
    }

    return ptr;
}

void Bird_Delete(ObjectPtr obj)
{
    Bird_Destruct(obj);
    free(obj);
}

