#include "Rectangle.h"
#include <iostream>
#include <cmath>
#include <stdexcept>

Rectangle::Rectangle() : Shape(), vs(new Point2D[N_VERTICES]) {
    vs[0] = Point2D(-1.0, 0.5);
    vs[1] = Point2D(1.0, 0.5);
    vs[2] = Point2D(1.0, -0.5);
    vs[3] = Point2D(-1.0, -0.5);

    if (!check(vs)) {
        delete[] vs;
        throw std::invalid_argument("Los vértices no forman un rectángulo válido.");
    }
}

Rectangle::Rectangle(std::string color, Point2D* vertices) : Shape(color), vs(new Point2D[N_VERTICES]) {
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i] = vertices[i];
    }

    if (!check(vs)) {
        delete[] vs;
        throw std::invalid_argument("Los vértices no forman un rectángulo válido.");
    }
}

Rectangle::Rectangle(const Rectangle &r) : Shape(r.color), vs(new Point2D[N_VERTICES]) {
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i] = r.vs[i];
    }
}

Rectangle::~Rectangle() {
    delete[] vs;
}

Point2D Rectangle::get_vertex(int ind) const {
    if (ind < 0 || ind >= N_VERTICES) {
        throw std::out_of_range("Índice de vértice fuera de rango.");
    }
    return vs[ind];
}

Point2D Rectangle::operator[](int ind) const {
    if (ind < 0 || ind >= N_VERTICES) {
        throw std::out_of_range("Índice de vértice fuera de rango.");
    }
    return vs[ind];
}

Rectangle& Rectangle::operator=(const Rectangle &r) {
    if (this == &r) {
        return *this; 
    }
    delete[] vs;
    color = r.color; 
    vs = new Point2D[N_VERTICES]; 
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i] = r.vs[i];
    }
    return *this;
}

double Rectangle::area() const {
    double width = Point2D::distance(vs[0], vs[1]);
    double height = Point2D::distance(vs[1], vs[2]);
    return width * height;
}

double Rectangle::perimeter() const {
    double width = Point2D::distance(vs[0], vs[1]);
    double height = Point2D::distance(vs[1], vs[2]);
    return 2.0 * (width + height);
}

void Rectangle::translate(double incX, double incY) {
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i].translate(incX, incY);
    }
}

void Rectangle::print() const {
    std::cout << "Rectángulo de color " << color << " con vértices:";
    for (int i = 0; i < N_VERTICES; i++) {
        std::cout << " " << vs[i];
    }
    std::cout << std::endl;
}

bool Rectangle::check(Point2D* vertices) {
    double side1 = Point2D::distance(vertices[0], vertices[1]);
    double side2 = Point2D::distance(vertices[1], vertices[2]);
    double side3 = Point2D::distance(vertices[2], vertices[3]);
    double side4 = Point2D::distance(vertices[3], vertices[0]);
    return (side1 == side3) && (side2 == side4);
}