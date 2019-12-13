#include "primitive3d.h"
#include <cmath>

constexpr double tolerance = 0.00001;

Primitive3D::Primitive3D()
    : _x(0.),
      _y(0.),
      _z(0.)
{

}

Primitive3D::Primitive3D(const Primitive3D& primitive3D)
    : _x(primitive3D._x),
      _y(primitive3D._y),
      _z(primitive3D._z)
{

}

Primitive3D::Primitive3D(const Primitive3D&& primitive3D)
    : _x(primitive3D._x),
      _y(primitive3D._y),
      _z(primitive3D._z)
{

}

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

void Primitive3D::setX(float& x)
{
    _x = x;
}

void Primitive3D::setY(float& y)
{
    _y = y;
}

void Primitive3D::setZ(float& z)
{
    _z = z;
}

void Primitive3D::setKoordinate(float& x, float& y, float& z)
{
    _x = x;
    _y = y;
    _z = z;
}

float Primitive3D::getX() const
{
    return _x;
}

float Primitive3D::getY() const
{
    return _y;
}

float Primitive3D::getZ() const
{
    return _z;
}

std::ifstream& operator>>(std::ifstream& in, Primitive3D& primitive3D)
{
    in >> primitive3D._x
       >> primitive3D._y
       >> primitive3D._z;

    return in;
}

std::ofstream& operator<<(std::ofstream& out, const Primitive3D& primitive3D)
{
    out << primitive3D._x << " "
        << primitive3D._y << " "
        << primitive3D._z << " ";

    return out;
}

bool Primitive3D::compareX(const std::shared_ptr<Primitive3D> primitive3D_1, const std::shared_ptr<Primitive3D> primitive3D_2)
{
    if(primitive3D_1->_x > primitive3D_2->_x)
        return true;
    return false;
}


bool Primitive3D::compareY(const std::shared_ptr<Primitive3D> primitive3D_1, const std::shared_ptr<Primitive3D> primitive3D_2)
{
    if(primitive3D_1->_y > primitive3D_2->_y)
        return true;
    return false;
}


bool Primitive3D::compareZ(const std::shared_ptr<Primitive3D> primitive3D_1, const std::shared_ptr<Primitive3D> primitive3D_2)
{
    if(primitive3D_1->_z > primitive3D_2->_z)
        return true;
    return false;
}

bool is_floatEqual(const float& expr_1, const float& expr_2)
{
    if(abs(expr_1 - expr_2) < tolerance)
        return true;
    return false;
}

bool operator==(const Primitive3D& primitive3D_1, const Primitive3D& primitive3D_2)
{
    if(is_floatEqual(primitive3D_1._x, primitive3D_2._x)
            && is_floatEqual(primitive3D_1._y, primitive3D_2._y)
            && is_floatEqual(primitive3D_1._z, primitive3D_2._z))
        return true;
    return false;
}

bool operator!=(const Primitive3D& primitive3D_1, const Primitive3D& primitive3D_2)
{
    return !(primitive3D_1 == primitive3D_2);
}


