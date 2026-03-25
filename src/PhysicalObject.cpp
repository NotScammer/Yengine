#include "PhysicalObject.hpp"

PhysicalObject::PhysicalObject(int startX, int startY, int sizeX, int sizeY, Color startColor)
    : x(startX), y(startY), sizeX(sizeX), sizeY(sizeY), color(startColor) {}

float PhysicalObject::getX() const {
    return x;
}

float PhysicalObject::getY() const {
    return y;
}

int PhysicalObject::getSizeX() const {
    return sizeX;
}

int PhysicalObject::getSizeY() const {
    return sizeY;
}

Color PhysicalObject::getColor() const {
    return color;
}

void PhysicalObject::setX(float newX) {
    x = newX;
}

void PhysicalObject::setY(float newY) {
    y = newY;
}
