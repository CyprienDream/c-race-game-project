//
// Created by cyprien on 7/4/20.
//

#ifndef SEMESTER2PROJECT_CATEGORY_H
#define SEMESTER2PROJECT_CATEGORY_H

#include "part.h"


typedef struct Category Category;

Category *CAT_allocateMemoryForCategory();

char *CAT_getName (Category *self);

int CAT_getNumParts (Category *self);

Part *CAT_getParts(Category *self);


#endif //SEMESTER2PROJECT_CATEGORY_H
