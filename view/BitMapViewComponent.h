#ifndef SEMESTER2PROJECT_BITMAPVIEWCOMPONENT_H
#define SEMESTER2PROJECT_BITMAPVIEWCOMPONENT_H

#include "allegro.h"

typedef struct BitMapViewComponent BitMapViewComponent;

BitMapViewComponent* BIT_MAP_VIEW_COMPONENT_createDefault(const char* file_name, float center_x, float center_y, float height, float width);

#endif //SEMESTER2PROJECT_BITMAPVIEWCOMPONENT_H
