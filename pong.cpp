#include <SDL2/SDL.h>
#include <iostream>

int main(int argc, char *argv[]) {
    //window to render to
    SDL_Window *window;

    //surface contained by window
    SDL_Renderer *renderer;

    //Initialize SDL
    if (SDL_CreateWindowAndRenderer(640, 480, 0, &window, &renderer) != 0) {
        std::cout << "SDL_CreateWindowAndRenderer Error: " << SDL_GetError() << std::endl;
    }

    SDL_SetWindowTitle(window, "Pong");

    return 0;
};