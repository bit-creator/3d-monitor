#ifndef VERTEX_H
#define VERTEX_H

#include "primitive3d.h"

class GeometricVertex : public Primitive3D
{
public:
    enum class vertexType
    {
        GEOMETRIC_VERTEX,
        GRAPHICS_VERTEX
    };

    GeometricVertex();
    GeometricVertex(const GeometricVertex& vertex);
    GeometricVertex(const GeometricVertex&& vertex);

    GeometricVertex& operator=(const GeometricVertex& vertex);
    GeometricVertex& operator=(const GeometricVertex&& vertex);

    virtual ~GeometricVertex() override;

    primitiveType getPrimitiveType() const override;

    virtual vertexType getVertexType() const;
};

#endif // VERTEX_H
