#ifndef MOVING_OBJECT_HPP
#define MOVING_OBJECT_HPP

#include "PhysicalObject.hpp"

class MovingObject : public PhysicalObject {
public:
    MovingObject(int startX, int startY, int sizeX, int sizeY, Color startColor, float vx = 0.0f, float vy = 0.0f);

    void Update(float dt);

    void setVelocity(float vx, float vy);
    float getVelocityX() const { return m_vx; }
    float getVelocityY() const { return m_vy; }

private:
    float m_vx; // Velocity X
    float m_vy; // Velocity Y
};

#endif