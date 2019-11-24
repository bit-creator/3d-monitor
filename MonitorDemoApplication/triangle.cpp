#include "triangle.h"

Triangle::Triangle() :
    _normal(Vector()),
    _vertex_1(nullptr),
    _vertex_2(nullptr),
    _vertex_3(nullptr){ }

Triangle::Triangle(Triangle& triangle) :
    _normal(triangle._normal),
    _vertex_1(triangle._vertex_1),
    _vertex_2(triangle._vertex_2),
    _vertex_3(triangle._vertex_3)
{
//    _normal = triangle._normal;
                                                    // нужно ли глубокое копирование если учесть
//    Vertex new_vertex_1 = *triangle._vertex_1;    что там итераторы?  И как его сделать. ьлже самое в model
}

Triangle::Triangle(Triangle&& triangle) :
    _normal(triangle._normal),
    _vertex_1(triangle._vertex_1),
    _vertex_2(triangle._vertex_2),
    _vertex_3(triangle._vertex_3){ }

Triangle& Triangle::operator=(Triangle &triangle)
{
    if(this == &triangle)
        return *this;

    _normal = triangle._normal;
    _vertex_1 = triangle._vertex_1;
    _vertex_2 = triangle._vertex_2;
    _vertex_3 = triangle._vertex_3;

    return *this;
}

Triangle& Triangle::operator=(Triangle&& triangle)
{
    if(this == &triangle)
        return *this;

    _normal = triangle._normal;
    _vertex_1 = triangle._vertex_1;
    _vertex_2 = triangle._vertex_2;
    _vertex_3 = triangle._vertex_3;

    return *this;
}

Triangle::~Triangle(){ }

void Triangle::set_vector(Vector vector)
{
    _normal = vector;
}

void Triangle::set_vertex_1(iter vertex_1)
{
    _vertex_1 = vertex_1;
}

void Triangle::set_vertex_2(iter vertex_2)
{
    _vertex_2 = vertex_2;
}

void Triangle::set_vertex_3(iter vertex_3)
{
    _vertex_3 = vertex_3;
}

const Vector& Triangle::get_vector() const
{
    return _normal;
}

Vertex& Triangle::get_vertex_1() const
{
    return *_vertex_1;
}

Vertex& Triangle::get_vertex_2() const
{
    return *_vertex_2;
}

Vertex& Triangle::get_vertex_3() const
{
    return *_vertex_3;
}

bool operator==(const Triangle& triangle, const Triangle& triangle_)
{
    if(triangle._normal == triangle_._normal
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
