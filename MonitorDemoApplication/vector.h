#ifndef VECTOR_H
#define VECTOR_H

#include "primitive3d.h"

class Vector : public Primitive3D
{
public:
    Vector();
    Vector(Vector& vector);
    Vector(Vector&& vector);

    Vector& operator=(const Vector& vector);
    Vector& operator=(const Vector&& vector);

    QString get_type() override;

    virtual ~Vector() override;
};

#endif // VECTOR_H
