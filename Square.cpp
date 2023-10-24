#include "Square.h"
#include <iostream>
#include <stdexcept>

Square::Square() : Rectangle() {
    vs[0] = Point2D(-1.0, 1.0);
    vs[1] = Point2D(1.0, 1.0);
    vs[2] = Point2D(1.0, -1.0);
    vs[3] = Point2D(-1.0, -1.0);

    if (!check(vs)) {
        throw std::invalid_argument("Los vértices no forman un cuadrado válido.");
    }
}

Square::Square(std::string color, Point2D* vertices) : Rectangle(color, vertices) {
    if (!check(vs)) {
        throw std::invalid_argument("Los vértices no forman un cuadrado válido.");
    }
}

void Square::set_vertices(Point2D* vertices) {
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i] = vertices[i];
    }

    if (!check(vs)) {
        throw std::invalid_argument("Los vértices no forman un cuadrado válido.");
    }
}

bool Square::check(Point2D* vertices) {
    double side1 = Point2D::distance(vertices[0], vertices[1]);
    double side2 = Point2D::distance(vertices[1], vertices[2]);
    double side3 = Point2D::distance(vertices[2], vertices[3]);
    double side4 = Point2D::distance(vertices[3], vertices[0]);
    return (side1 == side2) && (side2 == side3) && (side3 == side4);
}

void Square::print() const {
    std::cout << "Cuadrado de color " << color << " con vértices:";
    for (int i = 0; i < N_VERTICES; i++) {
        std::cout << " " << vs[i];
    }
    std::cout << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Square& square) {
    out << "Cuadrado de color " << square.color << " con vértices:";
    for (int i = 0; i < square.N_VERTICES; i++) {
        out << " " << square.vs[i];
    }
    return out;
}