#include "graphicvertex.h"
#include "NonInitVariable.h"

GraphicVertex::GraphicVertex()
    : GeometricVertex()
    , _weight(1.)
    , _normal(Vector())
    , _textureCoordinate(UVCoordinate())
{

}

GraphicVertex::GraphicVertex(const GraphicVertex& vertex)
    : GeometricVertex(vertex)
    , _weight(vertex._weight)
    , _normal(vertex._normal)
    , _textureCoordinate(vertex._textureCoordinate)
{

}

GraphicVertex::GraphicVertex(const GraphicVertex&& vertex)
    : GeometricVertex(vertex)
    , _weight(vertex._weight)
    , _normal(vertex._normal)
    , _textureCoordinate(vertex._textureCoordinate)
{

}

GraphicVertex& GraphicVertex::operator=(const GraphicVertex& vertex)
{
    if(this == &vertex)
        return *this;

    _weight = vertex._weight;
    _normal = vertex._normal;
    _textureCoordinate = vertex._textureCoordinate;
    _x = vertex._x;
    _y = vertex._y;
    _z = vertex._z;

    return *this;
}

GraphicVertex& GraphicVertex::operator=(const GraphicVertex&& vertex)
{
    if(this == &vertex)
        return *this;

    _weight = vertex._weight;
    _normal = vertex._normal;
    _textureCoordinate = vertex._textureCoordinate;
    _x = vertex._x;
    _y = vertex._y;
    _z = vertex._z;

    return *this;
}

GraphicVertex::~GraphicVertex(){ }

GraphicVertex::vertexType GraphicVertex::getVertexType() const
{
    return vertexType::GRAPHICS_VERTEX;
}

void GraphicVertex::setGeometricVertex(GeometricVertex& vertex)
{
    _x = vertex.getX();
    _y = vertex.getY();
    _z = vertex.getZ();
}

void GraphicVertex::setWeight(float& weight)
{
    _weight = weight;
}

void GraphicVertex::setNormal(Vector& normal)
{
    _normal = normal;
}

void GraphicVertex::setNormal(float& x, float& y, float& z)
{
    _normal.setX(x);
    _normal.setY(y);
    _normal.setZ(z);
}

void GraphicVertex::setTextureCoordinate(UVCoordinate& textureCoordinate)
{
    _textureCoordinate = textureCoordinate;
}

void GraphicVertex::setTextureCoordinate(float& U, float& V, float& W)
{
    _textureCoordinate.setU(U);
    _textureCoordinate.setV(V);
    _textureCoordinate.setW(W);
}

float GraphicVertex::getWeight() const
{
    return _weight;
}

Vector GraphicVertex::getNormal() const
{
    return _normal;
}

UVCoordinate GraphicVertex::getTextureCoordinate() const
{
    return _textureCoordinate;
}

//GeometricVertex GraphicVertex::getGeometricVertex() const
//{
//    GeometricVertex vertex;
//    vertex.setKoordinate(_x, _y, _z);
//    return vertex;
//}
