//
// Created by cyprien on 7/4/20.
//

#include "driverraceresult.h"
#include "stdlib.h"

struct DriverRaceResult{
    char *name;
    int points_earned;
    int position;
    int driver_number;
    float total_time;
};

DriverRaceResult *DRIVER_RESULT_initDriverRaceResult(){
    DriverRaceResult *d = (DriverRaceResult*)malloc(sizeof(DriverRaceResult));
    d->name = NULL;
    d->position = 0;
    d->points_earned = 0;
    d->driver_number = 0;
    d->total_time = 0;
    return d;
}

char *DRIVER_RESULT_getName(DriverRaceResult *self){
    return self->name;
}

int DRIVER_RESULT_getPointsEarned(DriverRaceResult *self){
    return self->points_earned;
}

int DRIVER_RESULT_getPosition(DriverRaceResult *self){
    return self->position;
}

int DRIVER_RESULT_getDriverNumber(DriverRaceResult *self){
    return self->driver_number;
}

float DRIVER_RESULT_getToTalTime(DriverRaceResult *self){
    return self->total_time;
}

DriverRaceResult *DRIVER_RESULT_setPointsEarned(DriverRaceResult *self, int points_earned){
    self->points_earned = points_earned;
    return self;
}

DriverRaceResult *DRIVER_RESULT_setPosition(DriverRaceResult *self, int position){
    self->position = position;
    return self;
}

DriverRaceResult *DRIVER_RESULT_setDriverNumber(DriverRaceResult *self, int driver_number){
    self->driver_number = driver_number;
    return self;
}

DriverRaceResult *DRIVER_RESULT_setTotalTime(DriverRaceResult *self, float total_time){
    self->total_time = total_time;
    return self;
}

DriverRaceResult *DRIVER_RESULT_setName(DriverRaceResult *self, char *name){
    self->name = name;
    return self;
}