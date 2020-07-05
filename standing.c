//
// Created by cyprien on 7/4/20.
//
#include "standing.h"
#include "stdlib.h"

struct Standing{
    int driver_number;
    int points;
    char *name;
};

Standing **STANDING_initStanding(){
    Standing **s = (Standing**)malloc(sizeof(Standing*)*NUM_DRIVERS);
    int i;
    for(i = 0; i<NUM_DRIVERS; i++) {
        s[i]->name = NULL;
        s[i]->points = 0;
        s[i]->driver_number = 0;
    }
    return s;
}

int STANDING_getDriverNumber(Standing *self){
    return self->driver_number;
}

int STANDING_getPoints(Standing *self){
    return self->points;
}

char *STANDING_getName(Standing *self) {
    return self->name;
}

Standing *STANDING_setDriverNumber(Standing *self, int driver_number){
    self->driver_number = driver_number;
    return self;
}

Standing *STANDING_setPoints(Standing *self, int points){
    self->points = points;
    return self;
}

Standing *STANDING_setName(Standing *self, char *name){
    self->name = name;
    return self;
}