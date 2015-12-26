#ifndef  __CLASS_ID__
#define  __CLASS_ID__

typedef enum {
    ClassID_Base,
    ClassID_Animal,
    ClassID_Bird,
    ClassID_Penguin,
    ClassID_Swallow,
    ClassID_Mammal,
    ClassID_Bat,
    ClassID_Tiger,
    ClassID_Plan,
    ClassID_MAX
} class_id;

typedef enum {
    InterfaceID_Base,
    InterfaceID_IFly,
    InterfaceID_MAX
} interface_id;

#endif //__ClassID__
