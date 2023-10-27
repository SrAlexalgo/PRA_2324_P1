#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
#include "Point2D.h"

class Rectangle : public Shape {
protected:
    Point2D* vs; 

public:
    static int const N_VERTICES = 4; 

    Rectangle()
        : Shape(), vs(new Point2D[N_VERTICES]);

    Rectangle(std::string color, Point2D* vertices)
        : Shape(color), vs(new Point2D[N_VERTICES]);

    Rectangle(const Rectangle& r)
        : Shape(r.color), vs(new Point2D[N_VERTICES]);

    ~Rectangle();

    Point2D get_vertex(int ind) const;

    Point2D operator[](int ind) const;

    virtual void set_vertices(Point2D* vertices) {
        for (int i = 0; i < N_VERTICES; i++) {
            vs[i] = vertices[i];
        }
        if (!check(vs)) {
            throw std::invalid_argument("Los vértices no forman un rectángulo válido.");
        }
    }

    Rectangle& operator=(const Rectangle& r);

    friend std::ostream& operator<<(std::ostream& out, const Rectangle& r) {
        out << "Rectangle [Vertices: ";
        for (int i = 0; i < N_VERTICES; i++) {
            out << r.vs[i];
            if (i < N_VERTICES - 1) {
                out << ", ";
            }
        }
        out << ", Color: " << r.color << "]";
        return out;
    }

    void print() const override;
    
    double area() const;
    
    double perimeter() const;
    
    void translate(double incX, double incY);

private:
    static bool check(Point2D* vertices);
};

#endif