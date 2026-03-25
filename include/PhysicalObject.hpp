#pragma once
#include <cstdint>
#include <Color.hpp>

class PhysicalObject {
private:
    float x, y;
    int sizeX, sizeY;
    Color color; //ARGB

public:
    PhysicalObject(int startX, int startY, int sizeX, int sizeY, Color startColor);

    [[nodiscard]] float getX() const;
    [[nodiscard]] float getY() const;
    [[nodiscard]] int getSizeX() const;
    [[nodiscard]] int getSizeY() const;
    [[nodiscard]] Color getColor() const;

    void setX(float newX);
    void setY(float newY);
};
