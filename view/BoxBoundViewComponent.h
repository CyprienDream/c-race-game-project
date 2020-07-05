#ifndef SEMESTER2PROJECT_BOXBOUNDVIEWCOMPONENT_H
#define SEMESTER2PROJECT_BOXBOUNDVIEWCOMPONENT_H


typedef struct BoxBoundViewComponent BoxBoundViewComponent;

BoxBoundViewComponent* BOX_BOUND_VIEW_COMPONENT_createDefault(float center_x, float center_y, float rotation, int n_colour, float width, float height);

BoxBoundViewComponent* BOX_BOUND_VIEW_COMPONENT_createBlack(float center_x, float center_y, float rotation, float width, float height);

float getTopLeftX(struct BoxBoundViewComponent* self);

float getBotRightX(struct BoxBoundViewComponent* self);

float getTopLeftY(struct BoxBoundViewComponent* self);

float getBotRightY(struct BoxBoundViewComponent* self);


#endif //SEMESTER2PROJECT_BOXBOUNDVIEWCOMPONENT_H
