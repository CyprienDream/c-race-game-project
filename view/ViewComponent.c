#include "ViewComponent.h"
#include "stdlib.h"
#include "stdio.h"

#define CHILD_ARRAY_STEP_COUNT 5;

struct ViewComponent {
    float centerX;
    float centerY;
    float rotation;
    int num_children;
    int maxChildren;
    struct ViewComponent** children;
    void (*draw)(ViewComponent* self);
    void (*_freeCustom)(ViewComponent *self);
};

void freeInternalViewComponent(ViewComponent* self) {
    int i = 0;
    self->draw = NULL;
    self->_freeCustom = NULL;

    for(; i < self->num_children; i++) {
        self->children[i]->_freeCustom(self->children[i]);
        free(self->children[i]);
    }

    free(self->children);
}

struct ViewComponent* allocViewComponent() {
    return malloc(sizeof(ViewComponent));
}

struct ViewComponent* initialiseViewComponent(struct ViewComponent* viewComponent) {
    if(NULL == viewComponent) {
        printf("ERROR: Out of memory! Failed to alloc view component");
        return viewComponent;
    }

    viewComponent->centerX = 0;
    viewComponent->centerY = 0;
    viewComponent->rotation = 0;
    viewComponent->num_children = 0;
    viewComponent->maxChildren = MIN_MAX_CHILDREN;
    viewComponent->children = malloc(viewComponent->maxChildren * sizeof(viewComponent->children));
    viewComponent->_freeCustom = freeInternalViewComponent;

    if(NULL == viewComponent->children) {
        printf("ERROR: Out of memory! Failed to malloc view component child array");
        return viewComponent;
    }

    viewComponent->draw = NULL;

    return viewComponent;
}

struct ViewComponent* allocAndInitialiseViewComponent() {
    struct ViewComponent* viewComponent = allocViewComponent();
    viewComponent = initialiseViewComponent(viewComponent);

    return viewComponent;
}

ViewComponent* VIEW_COMPONENT_createDefault(float center_x, float center_y, float rotation) {
    struct ViewComponent* self = allocAndInitialiseViewComponent();

    self->centerX = center_x;
    self->centerY = center_y;
    self->rotation = rotation;

    return self;
}

ViewComponent* VIEW_COMPONENT_createWithChildren(float center_x, float center_y, float rotation, ViewComponent** children) {
    struct ViewComponent* self = allocAndInitialiseViewComponent();

    self->centerX = center_x;
    self->centerY = center_y;
    self->rotation = rotation;
    self->children = children;

    return self;
}

int getNewSize(struct ViewComponent* self) {
    return self->num_children + CHILD_ARRAY_STEP_COUNT;
}

void growChildArray(struct ViewComponent* self) {
    self->maxChildren = getNewSize(self);
    self->children = realloc(self->children, self->maxChildren * sizeof((*self)));

    if(NULL == self->children) {
        printf("ERROR: Out of memory! Failed to realloc");
        return;
    }
}

void VIEW_COMPONENT_addChild(ViewComponent* self, ViewComponent* child) {
    if(self->num_children == self->maxChildren) {
        growChildArray(self);
    }

    self->children[self->num_children] = child;
    self->num_children++;
}

void VIEW_COMPONENT_addChildBatch(ViewComponent* self, ViewComponent** children, int num_children) {
    int i = 0;

    for(; i < num_children; i++) {
        VIEW_COMPONENT_addChild(self, children[i]);
    }
}

void VIEW_COMPONENT_draw(ViewComponent* self) {
    self->draw(self);
}

void VIEW_COMPONENT_free(ViewComponent* self) {
    self->_freeCustom(self);
}

void VIEW_COMPONENT_setCenterX(ViewComponent* self, float x) {
    self->centerX = x;
}

void VIEW_COMPONENT_setCenterY(ViewComponent* self, float y) {
    self->centerY = y;
}

float VIEW_COMPONENT_getCenterX(ViewComponent* self) {
    return self->centerX;
}

float VIEW_COMPONENT_getCenterY(ViewComponent* self) {
    return self->centerY;
}
