//
// Created by cyprien on 7/4/20.
//

#include "category.h"
#include "stdlib.h"


struct Category {
    char *name;
    int num_parts;
    struct Part *parts;
};

Category *CAT_allocateMemoryForCategory(){
    Category *category = (Category*)malloc(sizeof(Category));
    return category;
}

char *CAT_getName (Category *self){
    return self->name;
}

int CAT_getNumParts (Category *self){
    return self->num_parts;
}

Part *CAT_getParts(Category *self){
    return self->parts;
}
