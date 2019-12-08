#ifndef NONINITVARIABLE_H
#define NONINITVARIABLE_H

#include"vector.h"
#include"geometricvertex.h"
#include"graphicvertex.h"
#include"triangle.h"

class NonInit
{
public:
    static const Vector vector;
    static const GeometricVertex geometricVertex;
    static const GraphicVertex graphicVertex;
    static const Triangle triangle;
};

#endif // NONINITVARIABLE_H
