#ifndef TRIANGLEVERTEX_H
#define TRIANGLEVERTEX_H

#include "geometricvertex.h"
#include "vector.h"
#include "uvcoordinate.h"

class GraphicVertex : public GeometricVertex
{
public:
    GraphicVertex();
    GraphicVertex(const GraphicVertex& vertex);
    GraphicVertex(const GraphicVertex&& vertex);

    GraphicVertex& operator=(const GraphicVertex& vertex);
    GraphicVertex& operator=(const GraphicVertex&& vertex);

    virtual ~GraphicVertex() override;

    vertexType getVertexType() const override;

    void setNormal(const Vector& normal);
    void setTextureCoordinate(UVCoordinate& textureCoordinate);
    void setGeometricVertex(GeometricVertex& vertex);

    void setWeight(const float& weight);
    void setNormal(const float& x, const float& y, const float& z);
    void setTextureCoordinate(const float& U, const float& V, const float& W);

    float getWeight() const;
    Vector getNormal() const;
    UVCoordinate getTextureCoordinate() const;
    //GeometricVertex getGeometricVertex() const;

private:
    float _weight;
    Vector _normal;
    UVCoordinate _textureCoordinate;
};

#endif // TRIANGLEVERTEX_H
