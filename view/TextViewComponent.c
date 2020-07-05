#include <stdlib.h>
#include "TextViewComponent.h"
#include "ViewComponent.h"
#include "stdio.h"
#include "allegro_ttf.h"
#include "allegro.h"
#include "../LS_allegro.h"

struct TextViewComponent {
    float centerX;
    float centerY;
    float rotation;
    int num_children;
    int maxChildren;
    struct ViewComponent** children;
    void (*draw)(ViewComponent* self);
    void (*_freeCustom)(ViewComponent *self);
    ALLEGRO_COLOR text_color;
    ALLEGRO_FONT* font;
    const char* text;
};

void freeTextView(ViewComponent* _self) {
    TextViewComponent* self = (TextViewComponent*) _self;
    int i = 0;
    self->draw = NULL;
    self->_freeCustom = NULL;

    for(; i < self->num_children; i++) {
        VIEW_COMPONENT_free(self->children[i]);
    }

    free(self->children);
    free(self->font);
}

void drawTextView(ViewComponent* _self) {
    TextViewComponent* self = (TextViewComponent*) _self;
    al_draw_text(
            self->font,
            self->text_color,
            TL_X((float) al_get_text_width(self->font, self->text), self->centerX),
            TL_Y((float) al_get_font_line_height(self->font), self->centerY),
            0,
            self->text
    );
}

TextViewComponent* TEXT_VIEW_COMPONENT_constructor(float center_x, float center_y, int color, const char* text, int font_size) {
    TextViewComponent* textViewComponent = malloc(sizeof(*textViewComponent));
    textViewComponent = (TextViewComponent *) VIEW_COMPONENT_INIT((ViewComponent*) textViewComponent);

    textViewComponent->text = text;
    textViewComponent->text_color = LS_allegro_get_color(color);
    textViewComponent->font = LS_allegro_get_font(font_size);
    textViewComponent->centerX = center_x;
    textViewComponent->centerY = center_y;
    textViewComponent->_freeCustom = freeTextView;
    textViewComponent->draw = drawTextView;

    return textViewComponent;
}