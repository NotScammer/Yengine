#include "MovingObject.hpp"

MovingObject::MovingObject(int startX, int startY, int sizeX, int sizeY, Color startColor, float vx, float vy):
    PhysicalObject(startX, startY, sizeX, sizeY, startColor), m_vx(vx), m_vy(vy) {}

    void MovingObject::Update(float dt){
    //Should probably add collision stuff soon
        setX(getX() + dt*m_vx);
        setY(getY() + dt*m_vy);
    }

    void MovingObject::setVelocity(float vx, float vy){
        m_vx = vx;
        m_vy = vy;
    }


