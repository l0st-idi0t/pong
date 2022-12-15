#include <SDL2/SDL.h>
#include <iostream>

SDL_Renderer *renderer;
SDL_Window *window;
SDL_Color color;
bool running = true;
int frameCount, timerFPS, lastFrame, lastTime, fps;

void input() {}
void update() {}

void render() {
    frameCount++;
    timerFPS = SDL_GetTicks() - lastFrame;
    if (timerFPS < (1000 / 60)) {
        SDL_Delay((1000 / 60) - timerFPS);
    }
}

void cleanup() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int main(int argc, char* argv[]) {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
    }

    if(SDL_CreateWindowAndRenderer(640, 480, 0, &window, &renderer) < 0) {
        std::cout << "SDL_CreateWindowAndRenderer Error: " << SDL_GetError() << std::endl;
    }

    lastTime = 0;

    while (running) {
        lastFrame = SDL_GetTicks();

        if (lastFrame >= (lastTime + 1000)) {
            timerFPS = lastFrame;
            fps = frameCount;
            frameCount = 0;
        }

        update();
        input();
        render();
    }

    cleanup();
};