#ifndef DRAWING_H
#define DRAWING_H

#include "List.h"
#include "Shape.h"

class Drawing {
public:
    Drawing();
    ~Drawing();
    void add_front(Shape* shape);
    void add_back(Shape* shape);
    void print_all() const;
    double get_area_all_circles() const;
    void move_squares(double incX, double incY);

private:
    List<Shape*>* shapes;
};

#endif