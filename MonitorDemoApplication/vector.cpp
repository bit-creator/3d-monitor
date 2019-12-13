#include "vector.h"
#include <cmath>

Vector::Vector()
    : Primitive3D()
{

}

Vector::Vector(const Vector& vector)
    : Primitive3D(vector)
{

}

Vector::Vector(const Vector&& vector)
    : Primitive3D(vector)
{

}

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

Vector::primitiveType Vector::getPrimitiveType() const
{
    return primitiveType::GEOMETRIC_VECTOR;
}

void Vector::normalizeNormal(Vector& normal)
{
    float lenght = normal.getLength();

    normal._x /= lenght;
    normal._y /= lenght;
    normal._z /= lenght;
}

float Vector::getLength()
{
    return sqrt(pow((*this).getX(), 2) + pow((*this).getY(), 2) + pow((*this).getZ(), 2));
}

float Vector::getLength(const Vector& vector)
{
    return sqrt(pow(vector.getX(), 2) + pow(vector.getY(), 2) + pow(vector.getZ(), 2));
}

//bool Vector::isComplanarity(Vector& vector_1, Vector& vector_2)
//{

//}

bool Vector::isColinear(Vector &vector_1, Vector &vector_2)
{
    if(is_floatEqual(vector_1.getX() / vector_2.getX(), vector_1.getY() / vector_2.getY())
            && is_floatEqual(vector_1.getY() / vector_2.getY(), vector_1.getZ() / vector_2.getZ())
            && is_floatEqual(vector_1.getX() / vector_2.getX(), vector_1.getZ() / vector_2.getZ()))
        return true;
    return false;
}

Vector& Vector::operator+(const Vector& vector)
{
    _x += vector.getX();
    _y += vector.getY();
    _z += vector.getZ();
    return *this;
}

Vector& Vector::operator-(Vector &vector)
{
    return *this + vector * (-1.);
}

Vector& Vector::operator*(const float lambda)
{
    _x *= lambda;
    _y *= lambda;
    _z *= lambda;
    return *this;
}

float Vector::scalarMultiplication(const Vector& vector_1, const Vector& vector_2)
{
    return vector_1.getX() * vector_2.getX()
            + vector_1.getY() * vector_2.getY()
            + vector_1.getZ() * vector_2.getZ();
}

float Vector::VectorAngle(const Vector& vector)
{
    float cosAngle = 0;
    cosAngle = scalarMultiplication(*this, vector) / (*this).getLength() * getLength(vector);
    return  cosAngle;
}
