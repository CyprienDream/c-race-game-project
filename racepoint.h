//
// Created by cyprien on 7/4/20.
//

#ifndef SEMESTER2PROJECT_RACEPOINT_H
#define SEMESTER2PROJECT_RACEPOINT_H



typedef struct RacePoint Racepoint;

int RACE_POINTS_getPosition(Racepoint *self);

int RACE_POINTS_getPoints(Racepoint *self);

Racepoint *RACE_POINTS_setPosition(Racepoint *self, int position);

Racepoint *RACE_POINTS_setPoints(Racepoint *self, int points);

#endif //SEMESTER2PROJECT_RACEPOINT_H
