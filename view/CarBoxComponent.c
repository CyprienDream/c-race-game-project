#include "CarBoxComponent.h"
#include "BitMapViewComponent.h"

#define CAR_BOX_SCALE_X 0.6f
#define CAR_BOX_CENTER_X(sw) (sw * CAR_BOX_SCALE_X / 2)

ViewComponent* CAR_BOX_COMPONENT_constructor(const char* file_name, const float screen_w, const float screen_h) {
    return (ViewComponent *) BIT_MAP_VIEW_COMPONENT_createDefault(
            file_name,
            CAR_BOX_CENTER_X(screen_w),
            screen_h / 2,
            screen_h,
            screen_w * CAR_BOX_SCALE_X);
}
