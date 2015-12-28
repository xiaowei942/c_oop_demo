#ifndef __COMMON_H__
#define __COMMON_H__

#include <stdbool.h>
#include <stdlib.h>
#include "typeid.h"
#include "oop_defines.h"

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

#endif //__COMMON_H__
