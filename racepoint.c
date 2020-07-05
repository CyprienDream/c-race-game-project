//
// Created by cyprien on 7/4/20.
//

#include "racepoint.h"

struct RacePoint{
    int position;
    int points;
};

int RACE_POINTS_getPosition(Racepoint *self){
    return self->position;
}

int RACE_POINTS_getPoints(Racepoint *self){
    return self->points;
}

Racepoint *RACE_POINTS_setPosition(Racepoint *self, int position){
    self->position = position;
    return self;
}

Racepoint *RACE_POINTS_setPoints(Racepoint *self, int points){
    self->points = points;
    return self;
}

