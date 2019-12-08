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

    void setWeight(double& weight);
    void setNormal(Vector& normal);
    void setNormal(double& x, double& y, double& z);
    void setTextureCoordinate(UVCoordinate& textureCoordinate);
    void setTextureCoordinate(double& U, double& V, double& W);

    double getWeight() const;
    Vector getNormal() const;
    UVCoordinate getTextureCoordinate() const;

    Vector non_init_vector;
    UVCoordinate non_init_UV;

private:
    double _weight;
    Vector _normal;
    UVCoordinate _textureCoordinate;
};

#endif // TRIANGLEVERTEX_H
