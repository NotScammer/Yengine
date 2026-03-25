#include "../include/Renderer.hpp"
#include <iostream>

Renderer::Renderer()
    : m_window(nullptr), m_renderer(nullptr), m_texture(nullptr), m_width(0), m_height(0) {}

Renderer::~Renderer() {
    Shutdown();
}

bool Renderer::Initialize(int width, int height, const char* title) {
    m_width = width;
    m_height = height;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Error initializing SDL: " << SDL_GetError() << "\n";
        return false;
    }

    m_window = SDL_CreateWindow(title, width, height, 0);
    if (!m_window) return false;

    m_renderer = SDL_CreateRenderer(m_window, nullptr);
    if (!m_renderer) return false;

    m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, width, height);
    if (!m_texture) return false;

    m_frameBuffer.resize(width * height, 0xFF000000); //Black
    return true;
}

void Renderer::Clear() {
    std::fill(m_frameBuffer.begin(), m_frameBuffer.end(), 0xFF000000); //Black
}

void Renderer::DrawObject(const PhysicalObject& obj) {
    int startX = static_cast<int>(obj.getX());
    int startY = static_cast<int>(obj.getY());

    for (int y = 0; y < obj.getSizeY(); ++y) {
        for (int x = 0; x < obj.getSizeX(); ++x) {
            int drawX = startX + x;
            int drawY = startY + y;

            if (drawX >= 0 && drawX < m_width && drawY >= 0 && drawY < m_height) { //Window bounds
                m_frameBuffer[drawY * m_width + drawX] = obj.getColor();
            }
        }
    }
}

void Renderer::Present() {
    SDL_UpdateTexture(m_texture, nullptr, m_frameBuffer.data(), m_width * sizeof(uint32_t));
    SDL_RenderClear(m_renderer);
    SDL_RenderTexture(m_renderer, m_texture, nullptr, nullptr);
    SDL_RenderPresent(m_renderer);
}

void Renderer::Shutdown() {
    if (m_texture) { SDL_DestroyTexture(m_texture); m_texture = nullptr; }
    if (m_renderer) { SDL_DestroyRenderer(m_renderer); m_renderer = nullptr; }
    if (m_window) { SDL_DestroyWindow(m_window); m_window = nullptr; }
    SDL_Quit();
}
