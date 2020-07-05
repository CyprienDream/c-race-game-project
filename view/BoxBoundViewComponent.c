#include <allegro5/color.h>
#include "BoxBoundViewComponent.h"
#include "stdio.h"
#include "stdlib.h"
#include "ViewComponent.h"
#include "../LS_allegro.h"
#include "allegro5/allegro_primitives.h"

struct BoxBoundViewComponent {
    float centerX;
    float centerY;
    float rotation;
    int num_children;
    int maxChildren;
    struct ViewComponent** children;
    void (*draw)(ViewComponent* self);
    void (*_freeCustom)(ViewComponent *self);
    ALLEGRO_COLOR colour;
    float width;
    float height;
};

void freeCustom(ViewComponent* self) {}

void drawComponent(ViewComponent* self) {
    int i = 0;
    BoxBoundViewComponent* baseSelf = (BoxBoundViewComponent*) self;

    al_draw_filled_rectangle(
            getTopLeftX(baseSelf),
            getTopLeftY(baseSelf),
            getBotRightX(baseSelf),
            getBotRightY(baseSelf),
            baseSelf->colour
    );

    for(; i < baseSelf->num_children; i++) {
        VIEW_COMPONENT_draw(baseSelf->children[i]);
    }
}

float getTopLeftX(struct BoxBoundViewComponent* self) {
    return TL_X(self->width, self->centerX);
}

float getBotRightX(struct BoxBoundViewComponent* self) {
    return BR_X(self->width, self->centerX);
}

float getTopLeftY(struct BoxBoundViewComponent* self) {
    return TL_Y(self->height, self->centerY);
}

float getBotRightY(struct BoxBoundViewComponent* self) {
    return BR_Y(self->height, self->centerY);
}

struct BoxBoundViewComponent* allocateBoxBoundViewComponent() {
    return malloc(sizeof(BoxBoundViewComponent));
}

struct BoxBoundViewComponent* initBoxBoundViewComponent(struct BoxBoundViewComponent* viewComponent) {

    if (NULL == viewComponent) {
        printf("ERROR: Out of memory! Failed to alloc view component");
        return viewComponent;
    }

    viewComponent->centerX = 0;
    viewComponent->centerY = 0;
    viewComponent->rotation = 0;
    viewComponent->num_children = 0;
    viewComponent->maxChildren = MIN_MAX_CHILDREN;
    viewComponent->children = malloc(viewComponent->maxChildren * sizeof(viewComponent->children));
    viewComponent->height = 0;
    viewComponent->width = 0;
    viewComponent->colour = LS_allegro_get_color(BLACK);
    viewComponent->_freeCustom = freeCustom;

    if (NULL == viewComponent->children) {
        printf("ERROR: Out of memory! Failed to malloc view component child array");
        return viewComponent;
    }

    viewComponent->draw = drawComponent;

    return viewComponent;
}

BoxBoundViewComponent* BOX_BOUND_VIEW_COMPONENT_createDefault(float center_x, float center_y, float rotation, int n_colour, float width, float height) {
    struct BoxBoundViewComponent* boxBoundViewComponent = allocateBoxBoundViewComponent();
    boxBoundViewComponent = initBoxBoundViewComponent(boxBoundViewComponent);

    if(NULL == boxBoundViewComponent) {
        printf("ERROR: Could not allocate for view component");
        return boxBoundViewComponent;
    }

    boxBoundViewComponent->centerX = center_x;
    boxBoundViewComponent->centerY = center_y;
    boxBoundViewComponent->rotation = rotation;
    boxBoundViewComponent->colour = LS_allegro_get_color(n_colour);
    boxBoundViewComponent->width = width;
    boxBoundViewComponent->height = height;

    return boxBoundViewComponent;
}

BoxBoundViewComponent* BOX_BOUND_VIEW_COMPONENT_createBlack(float center_x, float center_y, float rotation, float width, float height){
    struct BoxBoundViewComponent* boxBoundViewComponent = allocateBoxBoundViewComponent();
    boxBoundViewComponent = initBoxBoundViewComponent(boxBoundViewComponent);

    if(NULL == boxBoundViewComponent) {
        printf("ERROR: Could not allocate for view component");
        return boxBoundViewComponent;
    }

    boxBoundViewComponent->centerX = center_x;
    boxBoundViewComponent->centerY = center_y;
    boxBoundViewComponent->rotation = rotation;
    boxBoundViewComponent->width = width;
    boxBoundViewComponent->height = height;

    return boxBoundViewComponent;
}
