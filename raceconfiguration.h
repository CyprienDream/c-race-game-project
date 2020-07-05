//
// Created by cyprien on 7/4/20.
//

#ifndef SEMESTER2PROJECT_RACECONFIGURATION_H
#define SEMESTER2PROJECT_RACECONFIGURATION_H

#include "sortedlist.h"


int RC_getCircuitNumber (SortedList *self);

char *RC_getName (SortedList *self);

int RC_getSpeed (SortedList *self);

int RC_getConsumption (SortedList *self);

int RC_getReliability (SortedList *self);

int RC_getAcceleration (SortedList *self);

float RC_getTime (SortedList *self);

int RC_getPitStopTime (SortedList *self);

int RC_getNumPitStops (SortedList *self);

#endif //SEMESTER2PROJECT_RACECONFIGURATION_H
