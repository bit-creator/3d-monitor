#ifndef DOCUMENT_H
#define DOCUMENT_H

#include<fstream>
#include<QString>
#include<memory>
#include<list>
#include"triangle.h"
#include"trianglevertex.h"

class Document// : std::enable_shared_from_this<Document>
{
public:
    enum class DocumentType
    {
        STL,
        OBJ
    };

    Document(QString filename);
    Document(const Document& document);
    Document(const Document&& document);

    Document& operator=(const Document& document);
    Document& operator=(const Document&& document);

    virtual ~Document();

    virtual DocumentType GetType() const = 0;

    virtual bool Open() = 0;
    virtual bool Save() = 0;

    bool SaveAs(QString filename);
    QString GetName() const;

    void setGabsritX(double& x);
    void setGabsritY(double& y);
    void setGabsritZ(double& z);

    void calculateGabrit();
    void calculateNum();

    double getGabaritX() const;
    double getGabaritY() const;
    double getGabaritZ() const;

    friend std::ifstream& operator>>(std::ifstream& in, Document& document);
    friend std::ofstream& operator<<(std::ofstream& out, Document& document);

private:
    QString _filename;

    double _gabaritX;
    double _gabaritY;
    double _gabaritZ;

protected:
    uint32_t _num;
    std::list<TriangleVertex> _data_vertex;
    std::list<Triangle> _data_triangle;


};

#endif // DOCUMENT_H
