#include "rect.hpp"

Rect::Rect(int x, int y, int w, int h) {
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
}

void Rect::drawRect(SDL_Renderer *renderer) {
    SDL_Rect rect = {this->x, this->y, this->w, this->h};
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &rect);
}

