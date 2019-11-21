#include "vertex.h"

//Vertex::Vertex() :
//    _x(0.),
//    _y(0.),
//    _z(0.){ }

//Vertex::Vertex(Vertex& vertex) :
//    _x(vertex._x),
//    _y(vertex._y),
//    _z(vertex._z){ }

//Vertex::Vertex(Vertex&& vertex) :
//    _x(vertex._x),
//    _y(vertex._y),
//    _z(vertex._z){ }

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

QString Vertex::get_type()
{
    return "Vertex";
}
