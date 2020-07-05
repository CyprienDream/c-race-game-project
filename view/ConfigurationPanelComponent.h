#ifndef SEMESTER2PROJECT_CONFIGURATIONPANELCOMPONENT_H
#define SEMESTER2PROJECT_CONFIGURATIONPANELCOMPONENT_H

#include "../carconfiguration.h"
#include "../category.h"
#include "../part.h"

typedef struct CarConfigurationComponent CarConfigurationComponent;

CarConfigurationComponent* CAR_CONFIGURATION_COMPONENT_constructorDefault(const CarConf* carConfiguration, const Category* current_cat, const Part* current_part);

void CAR_CONFIGURATION_COMPONENT_setCurrentPart(CarConfigurationComponent* self, const Part* new_current_part);

void CAR_CONFIGURATION_COMPONENT_setCurrentCategory(CarConfigurationComponent* self, const Category* new_current_cat);
#endif