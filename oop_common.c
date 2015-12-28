#include "oop_common.h"

/**
 * 类继承关系表
 */
int class_inhert_map[ClassID_MAX] = {-1,0};

//! 是否为对象
bool is_object(ObjectPtr obj)
{
    if (obj == NULL)
        return false;

    return (((*(uint32_t*)obj) >> 16) == CLASS_TAG);
}

//! 获取对象的类型id
class_id get_class_id(ObjectPtr obj)
{
    if (obj == NULL)
        return -1;

    class_info_t *class_info = (class_info_t*)obj;

    //! 检查是不是对象
    if ((class_info->tag >> 16) != CLASS_TAG)
        return -1;

    return (class_info->tag & 0xffff);
}

//! 判断对象是否为某个类的实例
bool is_instance_of(ObjectPtr obj, class_id id)
{
    class_id this_id = get_class_id(obj);
    if (this_id == -1)
        return false;

    do {
        if (this_id == id)
            return true;

        this_id = class_inhert_map[this_id];
    } while (this_id < ClassID_MAX && this_id >= 0);

    return false;
}

//! 是否为接口
bool is_interface(InterfacePtr obj)
{
    if (obj == NULL)
        return false;

    return (((*(uint32_t*)obj) >> 16) == INTERFACE_TAG);
}

//! 获取接口的类型id
class_id get_interface_id(InterfacePtr obj)
{
    if (obj == NULL)
        return -1;

    class_info_t *class_info = (class_info_t*)obj;

    //! 检查是不是对象
    if ((class_info->tag >> 16) != INTERFACE_TAG)
        return -1;

    return (class_info->tag & 0xffff);
}

void* OOP_Alloc(size_t size)
{
    malloc(size);
}

void OOP_Free(void *ptr)
{
    free(ptr);
}

