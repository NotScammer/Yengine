#include "PhysicalObject.hpp"

PhysicalObject::PhysicalObject(int startX, int startY, int sizeX, int sizeY, uint32_t startColor)
    : x(startX), y(startY), sizeX(sizeX), sizeY(sizeY), color(startColor) {}

int PhysicalObject::getX() const {
    return x;
}

int PhysicalObject::getY() const {
    return y;
}

int PhysicalObject::getSizeX() const {
    return sizeX;
}

int PhysicalObject::getSizeY() const {
    return sizeY;
}

uint32_t PhysicalObject::getColor() const {
    return color;
}

void PhysicalObject::setX(int newX) {
    x = newX;
}

void PhysicalObject::setY(int newY) {
    y = newY;
}
