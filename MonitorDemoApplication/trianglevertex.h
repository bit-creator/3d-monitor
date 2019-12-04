#ifndef TRIANGLEVERTEX_H
#define TRIANGLEVERTEX_H

#include "vertex.h"

class TriangleVertex : public Vertex
{
public:
    TriangleVertex();
    TriangleVertex(const TriangleVertex& triangle_vertex);
    TriangleVertex(const TriangleVertex&& triangle_vertex);

    TriangleVertex& operator=(const TriangleVertex& triangle_vertex);
    TriangleVertex& operator=(const TriangleVertex&& triangle_vertex);

    virtual ~TriangleVertex() override;

    enum class vertexType
    {
        GEOMETRY_VERTEX,
        GRAPHICS_VERTEX
    };

    virtual vertexType getVertexType();

};

#endif // TRIANGLEVERTEX_H
