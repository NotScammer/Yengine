#pragma once
#include "Renderer.hpp"
#include "PhysicalObject.hpp"
#include <chrono>

class Game {
public:
    Game();
    ~Game();

    bool Initialize();
    void Run();
    void Shutdown();

private:
    void ProcessInput(float dt);
    void Update(float dt);
    void Render();

    Renderer m_renderer;
    PhysicalObject m_player;
    bool m_isRunning;
    float m_speed;
    
    // Time tracking
    std::chrono::time_point<std::chrono::high_resolution_clock> m_lastFrameTime;

    // Constants
    static constexpr int WINDOW_W = 1600;
    static constexpr int WINDOW_H = 1600;
    static constexpr int TARGET_FPS = 60;
    std::chrono::milliseconds m_frameDelay;
};