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
};

#endif // VECTOR_H
