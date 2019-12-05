#ifndef VERTEX_H
#define VERTEX_H

#include "primitive3d.h"

class Vertex : public Primitive3D
{
public:
    Vertex();
    Vertex(const Vertex& vertex);
    Vertex(const Vertex&& vertex);

    Vertex& operator=(const Vertex& vertex);
    Vertex& operator=(const Vertex&& vertex);

    virtual ~Vertex() override;

    primitiveType getType() override;

    enum class vertexType
    {
        GEOMETRY_VERTEX,
        GRAPHICS_VERTEX
    };

    virtual vertexType getVertexType();
};

#endif // VERTEX_H
