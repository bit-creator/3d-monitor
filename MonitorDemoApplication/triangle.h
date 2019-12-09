#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "graphicvertex.h"
#include "vector.h"
#include <list>
#include <memory>

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
    void setVertex_1(std::shared_ptr<GraphicVertex> vertex_1);
    void setVertex_2(std::shared_ptr<GraphicVertex> vertex_2);
    void setVertex_3(std::shared_ptr<GraphicVertex> vertex_3);

    void calculateTriangleNormal();

    const Vector& getTriangleVector() const;
    GraphicVertex& getVertex_1() const;
    GraphicVertex& getVertex_2() const;
    GraphicVertex& getVertex_3() const;

    friend bool operator==(const Triangle& triangle, const Triangle& triangle_);
    friend bool operator!=(const Triangle& triangle, const Triangle& triangle_);

    ~Triangle();

private:
    Vector _TriangleNormal;
    std::shared_ptr<GraphicVertex> _vertex_1;
    std::shared_ptr<GraphicVertex> _vertex_2;
    std::shared_ptr<GraphicVertex> _vertex_3;
};

#endif // TRIANGLE_H
