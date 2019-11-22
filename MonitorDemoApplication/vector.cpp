#include "vector.h"

Vector::Vector() : Primitive3D(){ }

Vector::Vector(Vector& vector) : Primitive3D(vector){ }

Vector::Vector(Vector&& vector) : Primitive3D(vector){ }

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
