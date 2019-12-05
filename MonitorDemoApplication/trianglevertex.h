#ifndef TRIANGLEVERTEX_H
#define TRIANGLEVERTEX_H

#include "vertex.h"
#include "vector.h"
#include "uvcoordinate.h"

class TriangleVertex : public Vertex
{
public:
    TriangleVertex();
    TriangleVertex(const TriangleVertex& triangle_vertex);
    TriangleVertex(const TriangleVertex&& triangle_vertex);

    TriangleVertex& operator=(const TriangleVertex& triangle_vertex);
    TriangleVertex& operator=(const TriangleVertex&& triangle_vertex);

    virtual ~TriangleVertex() override;

    vertexType getVertexType() override;

    void setNormal(Vector normal);
    void setNormal(double& x, double& y, double& z);
    void setTextureCoordinate(UVCoordinate textureCoordinate);
    void setTextureCoordinate(double& U, double& V, double& W);

    Vector getNormal() const;
    UVCoordinate getTextureCoordinate() const;

    Vector non_init_vector;
    UVCoordinate non_init_UV;

private:
    Vector _normal;

    UVCoordinate _textureCoordinate;

};

#endif // TRIANGLEVERTEX_H
