#include "Circle.h"
#include <cmath>

double Circle::area() const {
    return 3.141592 * pow(radius, 2);
}

double Circle::perimeter() const {
    return 2 * 3.141592 * radius;
}

void Circle::translate(double incX, double incY) {
    center.x += incX;
    center.y += incY;
}