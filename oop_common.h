#ifndef __COMMON_H__
#define __COMMON_H__

#include <stdbool.h>
#include <stdlib.h>
#include "typeid.h"

#define CLASS_TAG       0x4352
#define INTERFACE_TAG   0xaced

#define MAKE_CLASS_TAG(class_id)        ((CLASS_TAG << 16) | class_id)
#define MAKE_INTERFACE_TAG(class_id)    ((INTERFACE_TAG << 16) | class_id)

typedef unsigned int uint32_t;

typedef void* ObjectPtr;
typedef void* InterfacePtr;

/**
 * 类信息结构体
 */
typedef struct {
    uint32_t tag;   //! 高16位为TAG，低16位为class_id
    void* vfun;     //! 虚函数结构体
} class_info_t;

/**
 * 接口信息结构体
 */
typedef struct {
    uint32_t tag;   //! 高16位为TAG，低16位为interface_id
    void* obj;      //! 对象地址
} interface_info_t;

//! 类继承关系表
extern int class_inhert_map[ClassID_MAX];

//! 是否为对象
bool is_object(ObjectPtr obj);

//! 获取对象的类型id
class_id get_class_id(ObjectPtr obj);

//! 判断对象是否为某个类的实例
bool is_instance_of(ObjectPtr obj, class_id id);

//! 是否为接口
bool is_interface(InterfacePtr obj);

//! 获取接口的类型id
class_id get_interface_id(InterfacePtr obj);

void* OOP_Alloc(size_t size);
void  OOP_Free(void *ptr);

//======================================================================

#define CLASS_FUNC_DEFINE(class_name, allocator) \
void class_name##_InitInfo(class_name *ptr) { \
    ptr->info.tag = MAKE_CLASS_TAG(ClassID_##class_name); \
    ptr->info.vfun = &ptr->func; \
} \
ObjectPtr class_name##_New() { \
    class_name *ptr = allocator##_Alloc(sizeof(class_name)); \
    if (ptr != NULL) { \
        class_name##_InitInfo(ptr); \
        class_name##_Construct(ptr); \
    } \
    return ptr; \
} \
void class_name##_Delete(ObjectPtr obj) { \
    class_name##_Destruct(obj); \
    allocator##_Free(obj); \
}

#define CLASS_VIRTUAL_INVOKE_FUNC_DEFINE_0(class_name, func_name) \
void class_name##_##func_name(ObjectPtr obj) { \
    if (is_instance_of(obj, ClassID_##class_name)) { \
        class_info_t *info = (class_info_t*)obj; \
        class_name##_Func *func = info->vfun; \
        if (func->_##func_name) \
            func->_##func_name(obj); \
    } \
}

#endif //__COMMON_H__
