#ifndef SEMESTER2PROJECT_CLASS_H
#define SEMESTER2PROJECT_CLASS_H

#include "stdlib.h"

typedef struct Class Class;

void* CLASS_new(Class* class);

void CLASS_destruct(Class *self);

#endif //SEMESTER2PROJECT_CLASS_H
