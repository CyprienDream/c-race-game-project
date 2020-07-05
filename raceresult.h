//
// Created by cyprien on 7/4/20.
//

#ifndef SEMESTER2PROJECT_RACERESULT_H
#define SEMESTER2PROJECT_RACERESULT_H

#include "driverraceresult.h"

#define NUM_DRIVERS 8

typedef struct RaceResult RaceResult;

DriverRaceResult *RACE_RESULT_getDriverRaceResult(RaceResult *self, char *name);

RaceResult *RACE_RESULT_sortDriverRaceResults(RaceResult *self);

#endif //SEMESTER2PROJECT_RACERESULT_H
