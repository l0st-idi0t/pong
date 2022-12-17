#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include "rect.hpp"

//global variables
bool running = true;
int playerSpeedY = 15;
int WIDTH = 640;
int HEIGHT = 480;
int paddleWidth = 10;
int paddleHeight = 100;

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

void render(std::vector<Rect> rects, SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    for (Rect rect : rects) {
        rect.drawRect(renderer);
    }
    
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

    if (SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer) != 0) {
        logSDLError(std::cout, "SDL_CreateWindowAndRenderer");
    }

    SDL_SetWindowTitle(window, "Pong");

    Rect l_paddle(0, HEIGHT/2, paddleWidth, paddleHeight);
    Rect r_paddle(WIDTH - paddleWidth, HEIGHT/2, paddleWidth, paddleHeight);

    while (running) {
        input(l_paddle);
        render({l_paddle, r_paddle}, renderer);
    }

    cleanup(window, renderer);

    return 0;
};