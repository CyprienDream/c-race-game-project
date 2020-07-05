#include "Class.h"
#include "stdio.h"

struct Class {
    size_t size;
    void (*destr)(void* self);
};

void stub_destr(void* self) {};

Class* CLASS_create(size_t size, void (*destr)(void* self)) {
    struct Class* class = calloc(1, size);

    if(class) {
        if(destr) {
            class->destr = destr;
        }
        else {
            class->destr = stub_destr;
        }
    }
    else {
        printf("Failed to alloc memory for object of size ");
        printf("%zu", size);
    }

    return class;
}

void* CLASS_new(const  Class* class) {

    //no class? no object!
    if(!class) {
        return NULL;
    }

    //allocate for object of specified class size
    void* obj = calloc(1, class->size);

    //failed to alloc return
    if(!obj) {
        return NULL;
    }

    //since all objects start with a class definition
    //as the first field opy class pointer to the first position
    *(const struct Class**) obj = class;

    return obj;
}

void CLASS_destruct(Class *self) {
    self->destr(self);

    free(self->destr);
    self->destr = NULL;
}
