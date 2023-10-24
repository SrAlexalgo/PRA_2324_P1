#include "Drawing.h"
#include "ListArray.h" 
#include <iostream>
#include <typeinfo>

Drawing::Drawing() {
    shapes = new ListArray<Shape*>;
}

Drawing::~Drawing() {
    delete shapes;
}

void Drawing::add_front(Shape* shape) {
    shapes->prepend(shape);
}

void Drawing::add_back(Shape* shape) {
    shapes->append(shape);
}

void Drawing::print_all() const {
    int count = shapes->size();
    for (int i = 0; i < count; i++) {
        std::cout << i + 1 << ": ";
        shapes->at(i)->print();
    }
}

double Drawing::get_area_all_circles() const {
    double totalArea = 0.0;
    int count = shapes->size();
    for (int i = 0; i < count; i++) {
        Circle* circle = dynamic_cast<Circle*>(shapes->at(i));
        if (circle != nullptr) {
            totalArea += circle->area();
        }
    }
    return totalArea;
}

void Drawing::move_squares(double incX, double incY) {
    int count = shapes->size();
    for (int i = 0; i < count; i++) {
        Square* square = dynamic_cast<Square*>(shapes->at(i));
        if (square != nullptr) {
            Point2D vertices[4];
            for (int j = 0; j < Rectangle::N_VERTICES; j++) {
                vertices[j] = square->get_vertex(j);
                vertices[j].translate(incX, incY);
            }
            square->set_vertices(vertices);
        }
    }
}