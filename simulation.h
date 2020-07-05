//
// Created by cyprien on 7/4/20.
//

#ifndef SEMESTER2PROJECT_SIMULATION_H
#define SEMESTER2PROJECT_SIMULATION_H

#include "driverconfiguration.h"
#include "raceconfiguration.h"

typedef struct Simulation Simulation;

Driver *SIM_getMyDriver(Simulation *self);

Driver *SIM_getRacers(Simulation *self);

SortedList *SIM_getRaceConfig(Simulation *self);

//tick & resolve

#endif //SEMESTER2PROJECT_SIMULATION_H
