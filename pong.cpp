#include <SDL2/SDL.h>
#include <iostream>

void logSDLError(std::ostream &os, const std::string &msg) {
    os << msg << " error: " << SDL_GetError() << std::endl;
}

void cleanup(SDL_Window *window, SDL_Renderer *renderer) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
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

    SDL_Delay(3000);

    cleanup(window, renderer);

    return 0;
};