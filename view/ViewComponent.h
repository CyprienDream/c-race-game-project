#ifndef SEMESTER2PROJECT_VIEWCOMPONENT_H
#define SEMESTER2PROJECT_VIEWCOMPONENT_H

#define MIN_MAX_CHILDREN 10

typedef struct ViewComponent ViewComponent;

ViewComponent* VIEW_COMPONENT_createDefault(float center_x, float center_y, float rotation);

ViewComponent* VIEW_COMPONENT_createWithChildren(float center_x, float center_y, float rotation, ViewComponent** children);

//for sub-types
struct ViewComponent* VIEW_COMPONENT_INIT(struct ViewComponent* viewComponent);

void VIEW_COMPONENT_addChild(ViewComponent* self, ViewComponent* child);

void VIEW_COMPONENT_addChildBatch(ViewComponent* self, ViewComponent** children, int num_children);

void VIEW_COMPONENT_draw(ViewComponent* self);

void VIEW_COMPONENT_free(ViewComponent* self);

void VIEW_COMPONENT_setCenterX(ViewComponent* self, float x);

void VIEW_COMPONENT_setCenterY(ViewComponent* self, float y);

float VIEW_COMPONENT_getCenterX(ViewComponent* self);

float VIEW_COMPONENT_getCenterY(ViewComponent* self);

#endif //SEMESTER2PROJECT_VIEWCOMPONENT_H
