#include "ConfigurationPanelComponent.h"
#include "ViewComponent.h"

struct CarConfigurationComponent {
    float centerX;
    float centerY;
    float rotation;
    int num_children;
    int maxChildren;
    struct ViewComponent** children;
    void (*draw)(ViewComponent* self);
    void (*_freeCustom)(ViewComponent *self);
};

void freeConfigPanelComponent(void* self) {
    CarConfigurationComponent* carConfigurationComponent = (CarConfigurationComponent*) self;
    int i = 0;
    carConfigurationComponent->draw = NULL;
    carConfigurationComponent->_freeCustom = NULL;

    for(; i < carConfigurationComponent->num_children; i++) {
        VIEW_COMPONENT_destructor(carConfigurationComponent->children[i]);
        free(carConfigurationComponent->children[i]);
    }

    free(carConfigurationComponent->children);
    VIEW_COMPONENT_destructor((ViewComponent*)carConfigurationComponent);
}

CarConfigurationComponent* allocCarConfigComponent() {
    return malloc(sizeof(CarConfigurationComponent));
}

CarConfigurationComponent* initCarConfigComponent(CarConfigurationComponent* self) {

}

CarConfigurationComponent* CAR_CONFIGURATION_COMPONENT_constructorDefault(const CarConf* carConfiguration, const Category* current_cat, const Part* current_part) {
    struct CarConfigurationComponent * carConfigurationComponent;

    carConfigurationComponent =(CarConfigurationComponent*) VIEW_COMPONENT_createSuper(CLASS_create(sizeof(*carConfigurationComponent)
                    ,freeConfigPanelComponent)
                    ,carConfigurationComponent->centerX
                    ,carConfigurationComponent->centerY
                    ,carConfigurationComponent->rotation
                    ,carConfigurationComponent->children);

    return carConfigurationComponent;
}

void CAR_CONFIGURATION_COMPONENT_setCurrentPart(CarConfigurationComponent* self, const Part* new_current_part);

void CAR_CONFIGURATION_COMPONENT_setCurrentCategory(CarConfigurationComponent* self, const Category* new_current_cat);