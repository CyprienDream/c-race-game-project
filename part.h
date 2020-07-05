//
// Created by cyprien on 7/4/20.
//

#ifndef SEMESTER2PROJECT_PART_H
#define SEMESTER2PROJECT_PART_H

typedef struct Part Part;

Part *PART_allocateMemoryForPart();

char *PART_getName (Part *self);

int PART_getSpeed (Part *self);

int PART_getConsumption (Part *self);

int PART_getReliability (Part *self);

int PART_getAcceleration (Part *self);

#endif //SEMESTER2PROJECT_PART_H
