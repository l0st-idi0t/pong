#include "rect.hpp"

Rect::Rect(int x, int y, int w, int h, SDL_Renderer *renderer) {
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
    this->renderer = renderer;
}

void Rect::drawRect() {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &rect);
}

