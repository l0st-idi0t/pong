#pragma once

#include <SDL2/SDL.h>

class Rect {
    public:
        Rect(int x, int y, int w, int h);
        SDL_Rect rect;

        void drawRect();

};