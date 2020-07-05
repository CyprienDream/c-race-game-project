#ifndef SEMESTER2PROJECT_CLASS_H
#define SEMESTER2PROJECT_CLASS_H

#include "stdlib.h"

typedef struct Class Class;

Class* CLASS_create(size_t size, void (*destr)(void* self));

void* CLASS_new(const Class* class);

void CLASS_destruct(Class *self);

#endif //SEMESTER2PROJECT_CLASS_H
