//
// Created by cyprien on 7/4/20.
//
#include "driverconfiguration.h"

struct Driver{
    char name[25];
    int driver_number;
    char team_name[25];
    int speed;
    int acceleration;
    int consumption;
    int reliability;
    int reflexes;
    int phy_condition;
    int temperament;
    int tyre_management;
};

char *DC_getName(Driver *self){
    return self->name;
}

char *DC_getTeamName(Driver *self){
    return self->team_name;
}

int DC_getDriverNumber(Driver *self){
    return self->driver_number;
}

int DC_getSpeed(Driver *self){
    return self->speed;
}

int DC_getAcceleration(Driver *self){
    return self->acceleration;
}

int DC_getConsumption(Driver *self){
    return self->consumption;
}

int DC_getReliability(Driver *self){
    return self->reliability;
}

int DC_getReflexes(Driver *self){
    return self->reflexes;
}

int DC_getPhysicalCondition(Driver *self){
    return self->phy_condition;
}

int DC_getTemperament(Driver *self){
    return self->temperament;
}

int DC_getTyreManagement(Driver *self){
    return self->tyre_management;
}
