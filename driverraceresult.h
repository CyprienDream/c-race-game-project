//
// Created by cyprien on 7/4/20.
//

#ifndef SEMESTER2PROJECT_DRIVERRACERESULT_H
#define SEMESTER2PROJECT_DRIVERRACERESULT_H

typedef struct DriverRaceResult DriverRaceResult;

DriverRaceResult *DRIVER_RESULT_initDriverRaceResult();

char *DRIVER_RESULT_getName(DriverRaceResult *self);

int DRIVER_RESULT_getPointsEarned(DriverRaceResult *self);

int DRIVER_RESULT_getPosition(DriverRaceResult *self);

int DRIVER_RESULT_getDriverNumber(DriverRaceResult *self);

float DRIVER_RESULT_getToTalTime(DriverRaceResult *self);

DriverRaceResult *DRIVER_RESULT_setPointsEarned(DriverRaceResult *self, int points_earned);

DriverRaceResult *DRIVER_RESULT_setPosition(DriverRaceResult *self, int position);

DriverRaceResult *DRIVER_RESULT_setDriverNumber(DriverRaceResult *self, int driver_number);

DriverRaceResult *DRIVER_RESULT_setTotalTime(DriverRaceResult *self, float total_time);

DriverRaceResult *DRIVER_RESULT_setName(DriverRaceResult *self, char *name);

#endif //SEMESTER2PROJECT_DRIVERRACERESULT_H
