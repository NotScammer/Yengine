#pragma once
#include <SDL3/SDL.h>
#include <vector>
#include <cstdint>
#include "../include/PhysicalObject.hpp"

class Renderer {
public:
    Renderer();
    ~Renderer();

    // Initializes SDL, Window, and Texture
    bool Initialize(int width, int height, const char* title);
    
    // Resets the frame buffer to black
    void Clear();
    
    // Writes the object's pixels to the frame buffer
    void DrawObject(const PhysicalObject& obj);
    
    // Pushes the frame buffer to the texture and presents it
    void Present();
    
    // Cleans up SDL resources
    void Shutdown();

private:
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
    SDL_Texture* m_texture;
    std::vector<uint32_t> m_frameBuffer;
    
    int m_width;
    int m_height;
};