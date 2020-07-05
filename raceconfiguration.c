//
// Created by cyprien on 7/4/20.
//
#include "raceconfiguration.h"


int RC_getCircuitNumber (SortedList *self){
    Element aux;
    aux = SORTEDLIST_get(self);
    return aux.circuit_number;
}

char *RC_getName (SortedList *self){
    Element aux;
    aux = SORTEDLIST_get(self);
    return aux.name;
}

int RC_getSpeed (SortedList *self){
    Element aux;
    aux = SORTEDLIST_get(self);
    return aux.speed;
}

int RC_getConsumption (SortedList *self){
    Element aux;
    aux = SORTEDLIST_get(self);
    return aux.consumption;
}

int RC_getReliability (SortedList *self){
    Element aux;
    aux = SORTEDLIST_get(self);
    return aux.reliability;
}

int RC_getAcceleration (SortedList *self){
    Element aux;
    aux = SORTEDLIST_get(self);
    return aux.acceleration;
}

float RC_getTime (SortedList *self){
    Element aux;
    aux = SORTEDLIST_get(self);
    return aux.time;
}

int RC_getPitStopTime (SortedList *self){
    Element aux;
    aux = SORTEDLIST_get(self);
    return aux.pit_stop_time;
}

int RC_getNumPitStops (SortedList *self){
    Element aux;
    aux = SORTEDLIST_get(self);
    return aux.num_pit_stop;
}