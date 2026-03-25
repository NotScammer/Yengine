#include "../include/Game.hpp"
#include <iostream>

Game::Game()
    : m_player(WINDOW_W / 2, WINDOW_H / 2, 50, 50, Color::RED),
      m_isRunning(false),
      m_speed(450.) // Speed is now 300 pixels per second
      //Should probably add the objects<PhysicalObject> Vector containing the objects on the scene (will add unity-like scene system later)
{}

Game::~Game() {
    Shutdown();
}

bool Game::Initialize() {
    // Initialize rendering system
    if (!m_renderer.Initialize(WINDOW_W, WINDOW_H, "A Yengine Game")) {
        std::cerr << "Failed to initialize engine components!\n";
        return false;
    }

    m_isRunning = true;

    // Timer for delta time calculations
    m_lastFrameTime = std::chrono::high_resolution_clock::now();

    return true;
}

void Game::Run() {
    while (m_isRunning) {
        auto currentFrameTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> elapsed = currentFrameTime - m_lastFrameTime;
        float dt = elapsed.count(); // Time passed in seconds
        m_lastFrameTime = currentFrameTime;

        ProcessInput(dt);
        Update(dt);
        Render();
    }
}

void Game::ProcessInput(float dt) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) {
            m_isRunning = false;
        }
    }

    const bool* keys = SDL_GetKeyboardState(nullptr);

    // Calculate how many pixels to move this exact frame
    float velocity = m_speed * dt;

    if (keys[SDL_SCANCODE_W] || keys[SDL_SCANCODE_UP]) {
        m_player.setY(m_player.getY() - velocity);
    }
    if (keys[SDL_SCANCODE_S] || keys[SDL_SCANCODE_DOWN]) {
        m_player.setY(m_player.getY() + velocity);
    }
    if (keys[SDL_SCANCODE_A] || keys[SDL_SCANCODE_LEFT]) {
        m_player.setX(m_player.getX() - velocity);
    }
    if (keys[SDL_SCANCODE_D] || keys[SDL_SCANCODE_RIGHT]) {
        m_player.setX(m_player.getX() + velocity);
    }
}

void Game::Update(float dt) {
    //Update loop (collision stuff)
}

void Game::Render() {
    m_renderer.Clear();
    m_renderer.DrawObject(m_player); //Should iterate each object that is close to the screen center later
    m_renderer.Present(); //Push buffer
}

void Game::Shutdown() {
    m_renderer.Shutdown();
}
