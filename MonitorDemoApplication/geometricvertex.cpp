#include "geometricvertex.h"

GeometricVertex::GeometricVertex()
    : Primitive3D()
{

}

GeometricVertex::GeometricVertex(const GeometricVertex& vertex)
    : Primitive3D(vertex)
{

}

GeometricVertex::GeometricVertex(const GeometricVertex&& vertex)
    : Primitive3D(vertex)
{

}

GeometricVertex& GeometricVertex::operator=(const GeometricVertex &vertex)
{
    if(this == &vertex)
        return *this;

    _x = vertex._x;
    _y = vertex._y;
    _z = vertex._z;

    return *this;
}

GeometricVertex& GeometricVertex::operator=(const GeometricVertex &&vertex)
{
    if(this == &vertex)
        return *this;

    _x = vertex._x;
    _y = vertex._y;
    _z = vertex._z;

    return *this;
}

GeometricVertex::~GeometricVertex(){ }

GeometricVertex::primitiveType GeometricVertex::getPrimitiveType() const
{
    return primitiveType::GEOMETRIC_VERTEX;
}

GeometricVertex::vertexType GeometricVertex::getVertexType() const
{
    return vertexType::GEOMETRIC_VERTEX;
}
