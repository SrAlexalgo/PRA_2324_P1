#include "Shape.h"
#include <iostream>

Shape::Shape() : color("red") {}

Shape::Shape(std::string c) {
    if (c != "red" && c != "green" && c != "blue") {
        throw std::invalid_argument("Color no válido");
    }
    color = c;
}

std::string Shape::get_color() const {
    return color;
}

void Shape::set_color(std::string c) {
    if (c != "red" && c != "green" && c != "blue") {
        throw std::invalid_argument("Color no válido");
    }
    color = c;
}

double Shape::area() const {
    return 0.0;
}

double Shape::perimeter() const {
    return 0.0; 
}

void Shape::translate(double incX, double incY) {}

void Shape::print() const {
    std::cout << "Color: " << color << std::endl;
}