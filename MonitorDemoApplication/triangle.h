#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "trianglevertex.h"
#include "vector.h"
#include <list>

using iter = std::list<TriangleVertex>::iterator;

class Triangle
{
public:
    Triangle();
    Triangle(const Triangle& triangle);
    Triangle(const Triangle&& triangle);

    Triangle& operator=(const Triangle& triangle);
    Triangle& operator=(const Triangle&& triangle);

    void calculateTriangleVector();
    void setTriangleVector(Vector& vector);
    void setVertex_1(iter vertex_1);
    void setVertex_2(iter vertex_2);
    void setVertex_3(iter vertex_3);


    const Vector& getTriangleVector() const;
    Vertex& getVertex_1() const;
    Vertex& getVertex_2() const;
    Vertex& getVertex_3() const;

    friend bool operator==(const Triangle& triangle, const Triangle& triangle_);
    friend bool operator!=(const Triangle& triangle, const Triangle& triangle_);

    ~Triangle();

    const Vector non_init;

private:
    Vector _TriangleNormal;
    iter _vertex_1;
    iter _vertex_2;
    iter _vertex_3;
};

#endif // TRIANGLE_H
