#ifndef __OOP_DEFINES_H__
#define __OOP_DEFINES_H__

#define CLASS_FUNC_DEFINE(class_name, allocator) \
    void* allocator##_Alloc(size_t); \
    void  allocator##_Free(void*); \
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

#endif //__OOP_DEFINES_H__
