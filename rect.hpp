#pragma once

#include <SDL2/SDL.h>

class Rect {
    public:
        Rect(int x, int y, int w, int h);
        ~Rect() = default;

        void drawRect(SDL_Renderer *renderer);
        SDL_Rect getRect();

        void setY(int y);
        void setX(int x);
        
        int getY();
        int getX();

    private:
        SDL_Rect rect;
};