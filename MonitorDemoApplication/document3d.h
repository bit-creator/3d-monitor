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

    DocumentType GetDocumentType() const override;
    virtual MeshType GetMeshType() const = 0;

    virtual bool Open() override = 0;
    virtual bool Save() override = 0;

    void setGabsritX(float& x);
    void setGabsritY(float& y);
    void setGabsritZ(float& z);

    void calculateGabrit();
    void calculateNum();

    float getGabaritX() const;
    float getGabaritY() const;
    float getGabaritZ() const;

private:
    float _gabaritX;
    float _gabaritY;
    float _gabaritZ;

protected:
    uint32_t _num;
    std::list<std::shared_ptr<GraphicVertex>> _data_vertex;
    std::list<std::shared_ptr<Triangle>> _data_triangle;
};

#endif // DOCUMENT3D_H
