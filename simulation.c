//
// Created by cyprien on 7/4/20.
//

#include "simulation.h"

struct Simulation {
    Driver *my_driver;
    Driver *racers;
    SortedList *race;
};

Driver *SIM_getMyDriver(Simulation *self){
    return self->my_driver;
}

Driver *SIM_getRacers(Simulation *self){
    return self->racers;
}

SortedList *SIM_getRaceConfig(Simulation *self){
    return self->race;
}