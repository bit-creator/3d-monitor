#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "vertex.h"
#include "vector.h"
#include <list>

using iter = std::list<Vertex>::iterator;

class Triangle
{
public:
    Triangle();
    Triangle(Triangle& triangle);
    Triangle(Triangle&& triangle);

    Triangle& operator=(Triangle& triangle);
    Triangle& operator=(Triangle&& triangle);

    void set_vector(Vector vector);
    void set_vertex_1(iter vertex_1);
    void set_vertex_2(iter vertex_2);
    void set_vertex_3(iter vertex_3);

    const Vector& get_vector() const;
    Vertex& get_vertex_1() const;
    Vertex& get_vertex_2() const;
    Vertex& get_vertex_3() const;

    friend bool operator==(const Triangle& triangle, const Triangle& triangle_);
    friend bool operator!=(const Triangle& triangle, const Triangle& triangle_);

    ~Triangle();

private:
    Vector _normal;
    iter _vertex_1;
    iter _vertex_2;
    iter _vertex_3;
};

#endif // TRIANGLE_H
