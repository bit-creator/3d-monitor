#ifndef VECTOR_H
#define VECTOR_H

#include "primitive3d.h"

class Vector : public Primitive3D
{
public:
    Vector();
    Vector(const Vector& vector);
    Vector(const Vector&& vector);

    Vector& operator=(const Vector& vector);
    Vector& operator=(const Vector&& vector);

    virtual ~Vector() override;

    primitiveType getPrimitiveType() const override;

    void normalizeNormal(Vector& normal);
    float getLength();
    float getLength(const Vector& vector);

//    bool isComplanarity(Vector& vector_1, Vector& vector_2, Vector& vector_3);
    bool isColinear(Vector& vector_1, Vector& vector_2);

    Vector& operator+(const Vector& vector);
    Vector& operator-(Vector& vector);
    Vector& operator*(const float lambda);
    float scalarMultiplication(const Vector& vector_1, const Vector& vector_2);

    float VectorAngle(const Vector& vector);
};

#endif // VECTOR_H
