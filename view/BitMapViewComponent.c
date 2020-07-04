#include "BitMapViewComponent.h"
#include "ViewComponent.h"
#include "stdio.h"
#include "stdlib.h"

#define TL_X(w, cx) (cx - (w / 2))
#define TL_Y(l, cy) (cy - (l / 2))

struct BitMapViewComponent {
    float centerX;
    float centerY;
    float rotation;
    int num_children;
    int maxChildren;
    struct ViewComponent** children;
    void (*draw)(ViewComponent* self);
    void (*_freeCustom)(ViewComponent *self);
    ALLEGRO_BITMAP* bitmap;
    float height;
    float width;
};

void freeInternalBitmapComponent(ViewComponent * self) {
    BitMapViewComponent * realSelf = (BitMapViewComponent*) self;

    int i = 0;
    for(; i < realSelf->num_children; i++) {
        VIEW_COMPONENT_free(realSelf->children[i]);
        free(realSelf->children[i]);
    }

    free(realSelf->bitmap);

    realSelf->draw = NULL;
    realSelf->_freeCustom = NULL;

    free(realSelf->children);
}


struct BitMapViewComponent* allocBitmapComponent() {
    return malloc(sizeof(BitMapViewComponent));
}

void drawBitmapViewComponent(ViewComponent* self) {
    BitMapViewComponent* realSelf = (BitMapViewComponent*) self;

    al_draw_scaled_bitmap(
            realSelf->bitmap,
            0,
            0,
            (float) al_get_bitmap_width(realSelf->bitmap),
            (float) al_get_bitmap_height(realSelf->bitmap),
            TL_X(realSelf->width, realSelf->centerX),
            TL_Y(realSelf->height, realSelf->centerY),
            realSelf->width,
            realSelf->height,
            0
            );
}

struct BitMapViewComponent* initBitmapComponent(struct BitMapViewComponent* viewComponent, const char* file_path) {
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
    viewComponent->_freeCustom = freeInternalBitmapComponent;

    if(NULL == viewComponent->children) {
        printf("ERROR: Out of memory! Failed to malloc view component child array");
        return NULL;
    }

    viewComponent->draw = drawBitmapViewComponent;

    viewComponent->bitmap = al_load_bitmap(file_path);

    if(NULL == viewComponent->bitmap) {
        printf("ERROR: Could not load bitmap ");
        printf("%s", file_path);

        return NULL;
    }

    return viewComponent;
}

struct BitMapViewComponent* allocAndInitBitmapComponent(const char* file_path) {
    struct BitMapViewComponent* viewComponent = allocBitmapComponent();
    viewComponent = initBitmapComponent(viewComponent, file_path);

    return viewComponent;
}

BitMapViewComponent* BIT_MAP_VIEW_COMPONENT_createDefault(const char* file_name, float center_x, float center_y, float height, float width) {
    struct BitMapViewComponent* viewComponent = allocAndInitBitmapComponent(file_name);

    if(NULL != viewComponent) {
        viewComponent->centerX = center_x;
        viewComponent->centerY = center_y;
        viewComponent->height = height;
        viewComponent->width = width;
    }

    return viewComponent;
}
