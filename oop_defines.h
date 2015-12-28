#ifndef __OOP_DEFINES_H__
#define __OOP_DEFINES_H__

#define OOP_ASSERT(cond)

/**
 * 参数列表宏定义
 */
#define TYPE_PARAM_LIST_0
#define TYPE_PARAM_LIST_1(T1)   ,T1 a1
#define TYPE_PARAM_LIST_2(T1, T2)   ,T1 a1, T2 a2
#define TYPE_PARAM_LIST_3(T1, T2, T3)   ,T1 a1, T2 a2, T3 a3
#define TYPE_PARAM_LIST_4(T1, T2, T3, T4)   ,T1 a1, T2 a2, T3 a3, T4 a4
#define TYPE_PARAM_LIST_5(T1, T2, T3, T4, T5)   ,T1 a1, T2 a2, T3 a3, T4 a4, T5 a5
#define TYPE_PARAM_LIST_6(T1, T2, T3, T4, T5, T6)   ,T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6
#define TYPE_PARAM_LIST_7(T1, T2, T3, T4, T5, T6, T7)   ,T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7
#define TYPE_PARAM_LIST_8(T1, T2, T3, T4, T5, T6, T7, T8)   ,T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8
#define TYPE_PARAM_LIST_9(T1, T2, T3, T4, T5, T6, T7, T8, T9)   ,T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9

#define PARAM_LIST_0
#define PARAM_LIST_1    , a1
#define PARAM_LIST_2    PARAM_LIST_1, a2
#define PARAM_LIST_3    PARAM_LIST_2 ,a3
#define PARAM_LIST_4    PARAM_LIST_3 ,a4
#define PARAM_LIST_5    PARAM_LIST_4 ,a5
#define PARAM_LIST_6    PARAM_LIST_5 ,a6
#define PARAM_LIST_7    PARAM_LIST_6 ,a7
#define PARAM_LIST_8    PARAM_LIST_7 ,a8
#define PARAM_LIST_9    PARAM_LIST_8 ,a9

/**
 * 基本函数宏定义
 *
 * \param   class_name 类名称
 * \param   allocator  空间配置器名称，默认使用OOP
 *
 * \note 需要提前指定 PARAM_LIST 与 TYPE_PARAM_LIST 宏
 */
#define BASE_FUNC_DEFINE(class_name, allocator) \
    void* allocator##_Alloc(size_t); \
    void  allocator##_Free(void*); \
    \
    void class_name##_InitInfo(class_name *ptr) { \
        ptr->info.tag = MAKE_CLASS_TAG(ClassID_##class_name); \
        ptr->info.vfun = &ptr->func; \
    } \
    \
    ObjectPtr class_name##_New(TYPE_PARAM_LIST) { \
        class_name *ptr = allocator##_Alloc(sizeof(class_name)); \
        if (ptr != NULL) { \
            class_name##_InitInfo(ptr); \
            class_name##_Construct(ptr PARAM_LIST); \
        } \
        return ptr; \
    } \
    \
    void class_name##_Delete(ObjectPtr obj) { \
        class_name##_Destruct(obj); \
        allocator##_Free(obj); \
    }

//! 默认虚函数无参数
#define TYPE_PARAM_LIST TYPE_PARAM_LIST_0
#define PARAM_LIST      PARAM_LIST_0

/**
 * 无返回虚函数定义宏
 * 如果有参数，则需要提前指定 TYPE_PARAM_LIST 与 PARAM_LIST 宏，默认不带参数
 *
 * \param class_name    类名
 * \param func_name     虚函数名
 */
#define VIRTUAL_FUNC_DEFINE(class_name, func_name) \
    void class_name##_##func_name(ObjectPtr obj TYPE_PARAM_LIST) { \
        OOP_ASSERT(is_instance_of(obj, ClassID_##class_name)) \
        class_info_t *info = (class_info_t*)obj; \
        class_name##_Func *func = info->vfun; \
        OOP_ASSERT(func->_##func_name != NULL); \
        func->_##func_name(obj PARAM_LIST); \
    }

/**
 * 有返回虚函数定义宏
 * 如果有参数，则需要提前指定 TYPE_PARAM_LIST 与 PARAM_LIST 宏，默认不带参数
 *
 * \param class_name    类名
 * \param func_name     虚函数名
 *
 * \note  需要定义RETURN_TYPE
 */
#define VIRTUAL_FUNC_DEFINE_RET(class_name, func_name) \
    RETURN_TYPE class_name##_##func_name(ObjectPtr obj TYPE_PARAM_LIST) { \
        OOP_ASSERT(is_instance_of(obj, ClassID_##class_name)) \
        class_info_t *info = (class_info_t*)obj; \
        class_name##_Func *func = info->vfun; \
        OOP_ASSERT(func->_##func_name != NULL); \
        return func->_##func_name(obj PARAM_LIST); \
    }

/**
 * 类型定义宏
 */
#define CLASS_TYPE_DEFINE(class_name) \
    typedef struct class_name { \
        class_info_t info; \
        class_name##_Data data; \
        class_name##_Func func; \
    } class_name;

/**
 * 类基本函数申明
 */
#define CLASS_FUNC_DECLARE(class_name) \
    void class_name##_Class_Init(); \
    void class_name##_Class_Destory(); \
    \
    void class_name##_Construct(ObjectPtr obj TYPE_PARAM_LIST); \
    void class_name##_Destruct(ObjectPtr obj);

#define CLASS_BASIC_INFO(class_name) \
    CLASS_TYPE_DEFINE(class_name) \
    CLASS_FUNC_DECLARE(class_name)
#endif //__OOP_DEFINES_H__
