#pragma once
#include <cstdint>

class PhysicalObject {
private:
    int x, y, sizeX, sizeY;
    uint32_t color; // 32-bit integer for ARGB color

public:
    PhysicalObject(int startX, int startY, int sizeX, int sizeY, uint32_t startColor);

    [[nodiscard]] int getX() const;
    [[nodiscard]] int getY() const;
    [[nodiscard]] int getSizeX() const;
    [[nodiscard]] int getSizeY() const;
    [[nodiscard]] uint32_t getColor() const;

    void setX(int newX);
    void setY(int newY);
};
