#ifndef DOCUMENT3D_H
#define DOCUMENT3D_H

#include"document.h"
#include<list>
#include"triangle.h"
#include"graphicvertex.h"

class Document3D : public Document
{
public:
    enum class MeshType
    {
        STL,
        OBJ
    };

    Document3D(QString filename);
    Document3D(const Document3D& document);
    Document3D(const Document3D&& document);

    Document3D& operator=(const Document3D& document);
    Document3D& operator=(const Document3D&& document);

    virtual ~Document3D() override;

    virtual DocumentType GetDocumentType() const override;
    virtual MeshType GetMeshType() const = 0;

    virtual bool Open() override = 0;
    virtual bool Save() override = 0;

    void setGabsritX(double& x);
    void setGabsritY(double& y);
    void setGabsritZ(double& z);

    void calculateGabrit();
    void calculateNum();

    double getGabaritX() const;
    double getGabaritY() const;
    double getGabaritZ() const;

private:
    double _gabaritX;
    double _gabaritY;
    double _gabaritZ;

protected:
    uint32_t _num;
    std::list<GraphicVertex> _data_vertex;
    std::list<Triangle> _data_triangle;
};

#endif // DOCUMENT3D_H
