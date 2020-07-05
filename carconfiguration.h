//
// Created by cyprien on 7/4/20.
//

#ifndef SEMESTER2PROJECT_CARCONFIGURATION_H
#define SEMESTER2PROJECT_CARCONFIGURATION_H

#include "part.h"
#include "stdlib.h"

typedef struct CarConfiguration CarConf;

Part *CAR_getTire(CarConf *self);

Part *CAR_getFront(CarConf *self);

Part *CAR_getMiddle(CarConf *self);

Part *CAR_getBack(CarConf *self);

Part *CAR_getMotor(CarConf *self);

Part *CAR_getGas(CarConf *self);

CarConf *CAR_setTire(CarConf *self, Part *tires);

CarConf *CAR_setFront(CarConf *self, Part *front);

CarConf *CAR_setBack(CarConf *self, Part *back);

CarConf *CAR_setMiddle(CarConf *self, Part *middle);

CarConf *CAR_setMotoe(CarConf *self, Part *motor);

CarConf *CAR_setMGas(CarConf *self, Part *gas);

#endif //SEMESTER2PROJECT_CARCONFIGURATION_H
