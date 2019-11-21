#include "vector.h"

#include "vertex.h"

//Vector::Vector() :
//    _x(0.),
//    _y(0.),
//    _z(0.){ }

//Vector::Vector(Vector& vector) :
//    _x(vector._x),
//    _y(vector._y),
//    _z(vector._z){ }

//Vector::Vector(Vector&& vector) :
//    _x(vector._x),
//    _y(vector._y),
//    _z(vector._z){ }

Vector& Vector::operator=(const Vector &vector)
{
    if(this == &vector)
        return *this;

    _x = vector._x;
    _y = vector._y;
    _z = vector._z;

    return *this;
}

Vector& Vector::operator=(const Vector &&vector)
{
    if(this == &vector)
        return *this;

    _x = vector._x;
    _y = vector._y;
    _z = vector._z;

    return *this;
}

Vector::~Vector(){ }

QString Vector::get_type()
{
    return "Vector";
}
