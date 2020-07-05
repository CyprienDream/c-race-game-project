//
// Created by cyprien on 7/4/20.
//
//

#ifndef SEMESTER2PROJECT_DRIVERCONFIGURATION_H
#define SEMESTER2PROJECT_DRIVERCONFIGURATION_H

typedef struct Driver Driver;

char *DC_getName(Driver *self);

char *DC_getTeamName(Driver *self);

int DC_getDriverNumber(Driver *self);

int DC_getSpeed(Driver *self);

int DC_getAcceleration(Driver *self);

int DC_getConsumption(Driver *self);

int DC_getReliability(Driver *self);

int DC_getReflexes(Driver *self);

int DC_getPhysicalCondition(Driver *self);

int DC_getTemperament(Driver *self);

#endif //SEMESTER2PROJECT_DRIVERCONFIGURATION_H
