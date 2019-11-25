#include "primitive3d.h"
#include <cmath>

constexpr auto tolerance = 0.0000001;

Primitive3D::Primitive3D() :
    _x(0.),
    _y(0.),
    _z(0.){ }

Primitive3D::Primitive3D(const Primitive3D& primitive3D) :
    _x(primitive3D._x),
    _y(primitive3D._y),
    _z(primitive3D._z){ }

Primitive3D::Primitive3D(const Primitive3D&& primitive3D) :
    _x(primitive3D._x),
    _y(primitive3D._y),
    _z(primitive3D._z){ }

Primitive3D& Primitive3D::operator=(const Primitive3D& primitive3D)
{
    if(this == &primitive3D)
        return *this;

    _x = primitive3D._x;
    _y = primitive3D._y;
    _z = primitive3D._z;

    return *this;
}

Primitive3D& Primitive3D::operator=(const Primitive3D&& primitive3D)
{
    if(this == &primitive3D)
        return *this;

    _x = primitive3D._x;
    _y = primitive3D._y;
    _z = primitive3D._z;

    return *this;
}

Primitive3D::~Primitive3D(){ }

void Primitive3D::set_x(double& x)
{
    _x = x;
}

void Primitive3D::set_y(double& y)
{
    _y = y;
}

void Primitive3D::set_z(double& z)
{
    _z = z;
}

void Primitive3D::set_koordinate(double& x, double& y, double& z)
{
    _x = x;
    _y = y;
    _z = z;
}

double Primitive3D::get_x() const
{
    return _x;
}

double Primitive3D::get_y() const
{
    return _y;
}

double Primitive3D::get_z() const
{
    return _z;
}

QTextStream& operator>>(QTextStream& in, Primitive3D& primitive3D)
{
    in >> primitive3D._x
       >> primitive3D._y
       >> primitive3D._z;

    return in;
}

QTextStream& operator<<(QTextStream& out, const Primitive3D& primitive3D)
{
    out << primitive3D._x << " "
        << primitive3D._y << " "
        << primitive3D._z << " ";

    return out;
}

bool operator==(const Primitive3D& primitive3D_1, const Primitive3D& primitive3D_2)
{
    if(abs(primitive3D_1._x - primitive3D_2._x) < tolerance                // tolerance = 0.000001
            && abs(primitive3D_1._y - primitive3D_2._y) < tolerance
            && abs(primitive3D_1._z - primitive3D_2._z) < tolerance)
        return true;
    return false;
}

bool operator!=(const Primitive3D& primitive3D_1, const Primitive3D& primitive3D_2)
{
    return !(primitive3D_1==primitive3D_2);
}

