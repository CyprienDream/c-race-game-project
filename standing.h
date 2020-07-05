//
// Created by cyprien on 7/4/20.
//

#ifndef SEMESTER2PROJECT_STANDING_H
#define SEMESTER2PROJECT_STANDING_H

#define NUM_DRIVERS 8

typedef struct Standing Standing;

Standing **STANDING_initStanding();

int STANDING_getDriverNumber(Standing *self);

int STANDING_getPoints(Standing *self);

char *STANDING_getName(Standing *self);

Standing *STANDING_setDriverNumber(Standing *self, int driver_number);

Standing *STANDING_setPoints(Standing *self, int points);

Standing *STANDING_setName(Standing *self, char *name);

#endif //SEMESTER2PROJECT_STANDING_H
