//
// Created by cyprien on 7/4/20.
//

#include "raceresult.h"
#include "driverraceresult.h"
#include "string.h"
#include "stdio.h"

struct RaceResult{
    DriverRaceResult **driverRaceResults;
};

DriverRaceResult *RACE_RESULT_getDriverRaceResult(RaceResult *self, char *name) {
    int i;
    DriverRaceResult *aux = DRIVER_RESULT_initDriverRaceResult();
    if(aux == NULL){
        printf("Error allocating memory.\n");
    } else {

        for (i = 0; i < NUM_DRIVERS; i++) {
            if (strcmp(DRIVER_RESULT_getName(self->driverRaceResults[i]), name) == 0) {
                aux = *self->driverRaceResults;
            }
        }
    }
    return aux;
}

RaceResult *RACE_RESULT_sortDriverRaceResults(RaceResult *self){
    int i;
    DriverRaceResult *aux = DRIVER_RESULT_initDriverRaceResult();
    for(i = 0; i<NUM_DRIVERS; i++){
        if(DRIVER_RESULT_getPosition(self->driverRaceResults[i+1]) > DRIVER_RESULT_getPosition(self->driverRaceResults[i])){
            aux = self->driverRaceResults[i];
            self->driverRaceResults[i] = self->driverRaceResults[i+1];
            self->driverRaceResults[i+1] = aux;
        }
    }
    return self;
}