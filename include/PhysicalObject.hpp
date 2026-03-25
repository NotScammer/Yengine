#pragma once
#include <cstdint>

class PhysicalObject {
private:
    float x, y;
    int sizeX, sizeY;
    uint32_t color; // 32-bit integer for ARGB color

public:
    PhysicalObject(int startX, int startY, int sizeX, int sizeY, uint32_t startColor);

    [[nodiscard]] float getX() const;
    [[nodiscard]] float getY() const;
    [[nodiscard]] int getSizeX() const;
    [[nodiscard]] int getSizeY() const;
    [[nodiscard]] uint32_t getColor() const;

    void setX(float newX);
    void setY(float newY);
};
