#include"triangle.h"
#include"noninitvariable.h"
#include<cmath>

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

void Triangle::calculateTriangleNormal()
{
    float normalizing_coefficient;
    Vector V1, V2;

    float v_1_x = _vertex_1->getX() - _vertex_2->getX();
    float v_1_y = _vertex_1->getY() - _vertex_2->getY();
    float v_1_z = _vertex_1->getZ() - _vertex_2->getZ();

    V1.setKoordinate(v_1_x, v_1_y, v_1_z);

    float v_2_x = _vertex_2->getX() - _vertex_3->getX();
    float v_2_y = _vertex_2->getY() - _vertex_3->getY();
    float v_2_z = _vertex_2->getZ() - _vertex_3->getZ();

    V2.setKoordinate(v_2_x, v_2_y, v_2_z);

    normalizing_coefficient = sqrt(pow(V1.getY() * V2.getZ() - V2.getY() * V1.getZ(), 2)
                                   + pow(V1.getX() * V2.getZ() - V2.getX() * V1.getZ(), 2)
                                   + pow(V1.getX() * V2.getY() - V2.getX() * V1.getY(), 2));

    float normalX, normalY, normalZ;

    normalX = (V1.getY() * V2.getZ() - V2.getY() * V1.getZ()) / normalizing_coefficient;
    normalY = (V1.getX() * V2.getZ() - V2.getX() * V1.getZ()) / normalizing_coefficient;
    normalZ = (V1.getX() * V2.getY() - V2.getX() * V1.getY()) / normalizing_coefficient;

    _TriangleNormal.setKoordinate(normalX, normalY, normalZ);
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
