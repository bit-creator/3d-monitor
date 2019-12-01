#include "vertex.h"

Vertex::Vertex()
    : Primitive3D()
{

}

Vertex::Vertex(const Vertex& vertex)
    : Primitive3D(vertex)
{

}

Vertex::Vertex(const Vertex&& vertex)
    : Primitive3D(vertex)
{

}

Vertex& Vertex::operator=(const Vertex &vertex)
{
    if(this == &vertex)
        return *this;

    _x = vertex._x;
    _y = vertex._y;
    _z = vertex._z;

    return *this;
}

Vertex& Vertex::operator=(const Vertex &&vertex)
{
    if(this == &vertex)
        return *this;

    _x = vertex._x;
    _y = vertex._y;
    _z = vertex._z;

    return *this;
}

Vertex::~Vertex(){ }

Vertex::primitive_type Vertex::get_type()
{
    return primitive_type::VERTEX;
}
