//
// Created by cyprien on 7/4/20.
//
#include "carconfiguration.h"


struct CarConfiguration{
    Part *tires;
    Part *front;
    Part *middle;
    Part *back;
    Part *gas;
    Part *motor;
};

CarConf *CAR_constructer(){
    CarConf *car = (CarConf*)malloc(sizeof(CarConf));

}

Part *CAR_getTire(CarConf *self){
    return self->tires;
}

Part *CAR_getFront(CarConf *self){
    return self->front;
}

Part *CAR_getMiddle(CarConf *self){
    return self->middle;
}

Part *CAR_getBack(CarConf *self){
    return self->back;
}

Part *CAR_getMotor(CarConf *self){
    return self->motor;
}

Part *CAR_getGas(CarConf *self){
    return self->gas;
}

CarConf *CAR_setTire(CarConf *self, Part *tires){
    self->tires = tires;
    return self;
}

CarConf *CAR_setFront(CarConf *self, Part *front){
    self->front = front;
    return self;
}

CarConf *CAR_setBack(CarConf *self, Part *back){
    self->back = back;
    return self;
}

CarConf *CAR_setMiddle(CarConf *self, Part *middle){
    self->middle = middle;
    return self;
}

CarConf *CAR_setMotoe(CarConf *self, Part *motor){
    self->motor = motor;
    return self;
}

CarConf *CAR_setMGas(CarConf *self, Part *gas){
    self->gas = gas;
    return self;
}

