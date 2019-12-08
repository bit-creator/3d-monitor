#include"triangle.h"
#include"noninitvariable.h"

Triangle::Triangle()
    : _TriangleNormal(NonInit::vector)
    , _vertex_1(nullptr)
    , _vertex_2(nullptr)
    , _vertex_3(nullptr)
{

}

Triangle::Triangle(const Triangle& triangle)
    : _TriangleNormal(triangle._TriangleNormal)
    , _vertex_1(triangle._vertex_1)
    , _vertex_2(triangle._vertex_2)
    , _vertex_3(triangle._vertex_3)
{

}

Triangle::Triangle(const Triangle&& triangle)
    : _TriangleNormal(triangle._TriangleNormal)
    , _vertex_1(triangle._vertex_1)
    , _vertex_2(triangle._vertex_2)
    , _vertex_3(triangle._vertex_3)
{

}

Triangle& Triangle::operator=(const Triangle &triangle)
{
    if(this == &triangle)
        return *this;

    _TriangleNormal = triangle._TriangleNormal;
    _vertex_1 = triangle._vertex_1;
    _vertex_2 = triangle._vertex_2;
    _vertex_3 = triangle._vertex_3;

    return *this;
}

Triangle& Triangle::operator=(const Triangle&& triangle)
{
    if(this == &triangle)
        return *this;

    _TriangleNormal = triangle._TriangleNormal;
    _vertex_1 = triangle._vertex_1;
    _vertex_2 = triangle._vertex_2;
    _vertex_3 = triangle._vertex_3;

    return *this;
}

Triangle::~Triangle(){ }

void Triangle::calculateTriangleVector()
{
    //_normal = vector;
}

void Triangle::setTriangleVector(Vector& vector)
{
    _TriangleNormal = vector;
}

void Triangle::setVertex_1(std::shared_ptr<GraphicVertex> vertex_1)
{
    _vertex_1 = vertex_1;
}

void Triangle::setVertex_2(std::shared_ptr<GraphicVertex> vertex_2)
{
    _vertex_2 = vertex_2;
}

void Triangle::setVertex_3(std::shared_ptr<GraphicVertex> vertex_3)
{
    _vertex_3 = vertex_3;
}

const Vector& Triangle::getTriangleVector() const
{
    return _TriangleNormal;
}

GraphicVertex& Triangle::getVertex_1() const
{
    return *_vertex_1;
}

GraphicVertex& Triangle::getVertex_2() const
{
    return *_vertex_2;
}

GraphicVertex& Triangle::getVertex_3() const
{
    return *_vertex_3;
}

bool operator==(const Triangle& triangle, const Triangle& triangle_)
{
    if(triangle._TriangleNormal == triangle_._TriangleNormal
            && triangle._vertex_1 == triangle_._vertex_1
            && triangle._vertex_2 == triangle_._vertex_2
            && triangle._vertex_3 == triangle_._vertex_3)
        return true;
    return false;
}

bool operator!=(const Triangle& triangle, const Triangle& triangle_)
{
    return !(triangle == triangle_);
}
