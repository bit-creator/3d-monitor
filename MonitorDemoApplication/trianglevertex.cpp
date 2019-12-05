#include "trianglevertex.h"

TriangleVertex::TriangleVertex()
    : Vertex()
    , _normal(non_init_vector)
    , _textureCoordinate(non_init_UV)
{

}

TriangleVertex::TriangleVertex(const TriangleVertex& triangleVertex)
    : Vertex(triangleVertex)
    , _normal(triangleVertex._normal)
    , _textureCoordinate(triangleVertex._textureCoordinate)
{

}

TriangleVertex::TriangleVertex(const TriangleVertex&& triangleVertex)
    : Vertex(triangleVertex)
    , _normal(triangleVertex._normal)
    , _textureCoordinate(triangleVertex._textureCoordinate)
{

}

TriangleVertex& TriangleVertex::operator=(const TriangleVertex& triangle_vertex)
{
    if(this == &triangle_vertex)
        return *this;

    _normal = triangle_vertex._normal;
    _textureCoordinate = triangle_vertex._textureCoordinate;
    _x = triangle_vertex._x;
    _y = triangle_vertex._y;
    _z = triangle_vertex._z;

    return *this;
}

TriangleVertex& TriangleVertex::operator=(const TriangleVertex&& triangle_vertex)
{
    if(this == &triangle_vertex)
        return *this;

    _normal = triangle_vertex._normal;
    _textureCoordinate = triangle_vertex._textureCoordinate;
    _x = triangle_vertex._x;
    _y = triangle_vertex._y;
    _z = triangle_vertex._z;

    return *this;
}

TriangleVertex::~TriangleVertex(){ }

TriangleVertex::vertexType TriangleVertex::getVertexType()
{
    return vertexType::GRAPHICS_VERTEX;
}

void TriangleVertex::setNormal(Vector normal)
{
    _normal = normal;
}

void TriangleVertex::setNormal(double& x, double& y, double& z)
{
    _normal.setX(x);
    _normal.setY(y);
    _normal.setZ(z);
}

void TriangleVertex::setTextureCoordinate(UVCoordinate textureCoordinate)
{
    _textureCoordinate = textureCoordinate;
}

void TriangleVertex::setTextureCoordinate(double& U, double& V, double& W)
{
    _textureCoordinate.setU(U);
    _textureCoordinate.setV(V);
    _textureCoordinate.setW(W);
}

Vector TriangleVertex::getNormal() const
{
    return _normal;
}

UVCoordinate TriangleVertex::getTextureCoordinate() const
{
    return _textureCoordinate;
}
