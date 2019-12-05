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

    primitiveType getType() override;

    virtual ~Vector() override;
};

#endif // VECTOR_H
