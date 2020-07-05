#include "Class.h"

struct Class {
    size_t size;
    void (*destr)(void* self);
};

void stub_destr(void* self) {};


void* CLASS_new(Class* class) {

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

    if(!class->destr) {
        class->destr = stub_destr;
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
