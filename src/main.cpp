#include <SDL3/SDL.h>
#include <iostream>
#include <vector>
#include <chrono>
#include "../include/PhysicalObject.hpp"
#include "../include/Game.hpp"

constexpr int WINDOW_W = 1600;
constexpr int WINDOW_H = 1600;
constexpr int TARGET_FPS = 60;
constexpr std::chrono::milliseconds FRAME_DELAY = std::chrono::milliseconds(1000 / TARGET_FPS); //16.66ms for 60fps

int playerX, playerY;

int main()
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cerr << "Error to init SDL";
        return -1;
    }
    //implement Game.cpp things for better abstraction
    SDL_Window* window = SDL_CreateWindow("A Yengine Game", WINDOW_W, WINDOW_H, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);
    SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, WINDOW_W, WINDOW_H);

    std::vector<uint32_t> frameBuffer(WINDOW_W * WINDOW_H, 0xFF000000); //initialize to pitch black hopefully

    PhysicalObject player(WINDOW_W/2, WINDOW_H/2, 50, 50, 0xFFFF0000);
    int speed(5);

    bool isRunning = true;
    SDL_Event event;

    while(isRunning){
        auto frameStart = std::chrono::high_resolution_clock::now();

        while(SDL_PollEvent(&event)){
            if(event.type == SDL_EVENT_QUIT) isRunning = false;
        }

        const bool* keys = SDL_GetKeyboardState(nullptr);

        //Movement input (scancode for language exclusive input)
        if (keys[SDL_SCANCODE_W] || keys[SDL_SCANCODE_UP]) {
            player.setY(player.getY() - speed);
        }
        if (keys[SDL_SCANCODE_S] || keys[SDL_SCANCODE_DOWN]) {
            player.setY(player.getY() + speed);
        }
        if (keys[SDL_SCANCODE_A] || keys[SDL_SCANCODE_LEFT]) {
            player.setX(player.getX() - speed);
        }
        if (keys[SDL_SCANCODE_D] || keys[SDL_SCANCODE_RIGHT]) {
            player.setX(player.getX() + speed);
        }

        std::fill(frameBuffer.begin(), frameBuffer.end(), 0xFF000000);

        int rectX = WINDOW_W / 2 - 25;
        int rectY = WINDOW_H / 2 - 25;
        uint32_t redColor = 0xFFFF0000; // ARGB format

        for (int y = 0; y < player.getSizeY(); ++y) {
            for (int x = 0; x < player.getSizeX(); ++x) {
                int drawX = player.getX() + x;
                int drawY = player.getY() + y;

                if (drawX >= 0 && drawX < WINDOW_W && drawY >= 0 && drawY < WINDOW_H) {
                    frameBuffer[drawY * WINDOW_W + drawX] = player.getColor();
                }
            }
        }

        SDL_UpdateTexture(texture, nullptr, frameBuffer.data(), WINDOW_W * sizeof(uint32_t));

        SDL_RenderClear(renderer);
        SDL_RenderTexture(renderer, texture, nullptr, nullptr);
        SDL_RenderPresent(renderer);

        auto frameEnd = std::chrono::high_resolution_clock::now();
        auto frameDuration = std::chrono::duration_cast<std::chrono::milliseconds>(frameEnd - frameStart);

        if (frameDuration < FRAME_DELAY) {
            SDL_Delay((FRAME_DELAY - frameDuration).count());
        }
    }

    //Cleanup
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;

    }
