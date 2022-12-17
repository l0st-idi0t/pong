#include "rect.hpp"

Rect::Rect(int x, int y, int w, int h) {
    this->rect = {x, y, w, h};
}

void Rect::drawRect(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &this->rect);
}

SDL_Rect Rect::getRect() {
    return this->rect;
}

void Rect::setY(int y) {
    this->rect.y = y;
}

void Rect::setX(int x) {
    this->rect.x = x;
}

int Rect::getY() {
    return this->rect.y;
}

int Rect::getX() {
    return this->rect.x;
}



