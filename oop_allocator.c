#include <string.h>

void* OOP_Alloc(size_t size)
{
    malloc(size);
}

void OOP_Free(void *ptr)
{
    free(ptr);
}

