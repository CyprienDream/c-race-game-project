//
// Created by cyprien on 7/4/20.
//

#include "part.h"
#include "stdlib.h"

struct Part {
    char *name;
    int speed;
    int acceleration;
    int consumption;
    int reliability;
};

Part *PART_allocateMemoryForPart(){
    Part *part = (Part*)malloc(sizeof(Part));
    return part;
}

char *PART_getName (Part *self){
    return self->name;
}

int PART_getSpeed (Part *self){
    return self->speed;
}

int PART_getConsumption (Part *self){
    return self->consumption;
}

int PART_getReliability (Part *self){
    return self->reliability;
}

int PART_getAcceleration (Part *self){
    return self->acceleration;
}

void PART_setAcceleration(Part *self, char *name){
    self->name = name;
}
