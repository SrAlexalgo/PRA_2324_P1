#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape {
private:
    Point2D center; 
    double radius;  

public:
    Circle()
        : Shape(), center(Point2D()), radius(1.0) {}

    Circle(std::string color, const Point2D& c, double r)
        : Shape(color), center(c), radius(r) {}

    Point2D get_center() const {
        return center;
    }

    void set_center(const Point2D& p) {
        center = p;
    }

    double get_radius() const {
        return radius;
    }

    void set_radius(double r) {
        radius = r;
    }

    friend std::ostream& operator<<(std::ostream& out, const Circle& c) {
        out << "Circle [Center: " << c.center << ", Radius: " << c.radius << ", Color: " << c.color << "]";
        return out;
    }

    void print() const override {
        std::cout << *this;
    }

    double area() const override;

    double perimeter() const override;

    void translate(double incX, double incY) override;
};

#endif