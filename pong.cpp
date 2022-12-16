#include <SDL2/SDL.h>
#include <iostream>
#include "rect.hpp"

//global variables
bool running = true;
int playerSpeedY = 5;


void logSDLError(std::ostream &os, const std::string &msg) {
    os << msg << " error: " << SDL_GetError() << std::endl;
}

void cleanup(SDL_Window *window, SDL_Renderer *renderer) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void input(Rect &player) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                running = false;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        running = false;
                        break;
                    case SDLK_UP:
                        player.setY(player.getY() - playerSpeedY);
                        break;
                    case SDLK_DOWN:
                        player.setY(player.getY() + playerSpeedY);
                        break;
                }
                break;
        }
    }
}

void render(Rect rect, SDL_Renderer *renderer) {
    rect.drawRect(renderer);
    SDL_RenderPresent(renderer);
}

int main(int argc, char *argv[]) {
    //window to render to
    SDL_Window *window;
    //surface contained by window
    SDL_Renderer *renderer;

    //Initialize SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        logSDLError(std::cout, "SDL_Init");
    }

    if (SDL_CreateWindowAndRenderer(640, 480, 0, &window, &renderer) != 0) {
        logSDLError(std::cout, "SDL_CreateWindowAndRenderer");
    }

    SDL_SetWindowTitle(window, "Pong");

    Rect square(100, 100, 100, 100);

    while (running) {
        input(square);
        render(square, renderer);
    }

    cleanup(window, renderer);

    return 0;
};