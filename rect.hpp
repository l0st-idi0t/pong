#pragma once

#include <SDL2/SDL.h>

class Rect {
    public:
        Rect(int x, int y, int w, int h);
        int x, y, w, h;

        void drawRect(SDL_Renderer *renderer);

};