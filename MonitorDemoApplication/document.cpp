#include "document.h"
#include "documentmanager.h"
#include <algorithm>

Document::Document(QString filename)
    : _filename(filename)
    , _gabaritX(0.)
    , _gabaritY(0.)
    , _gabaritZ(0.)
    , _num(0)
    , _data_vertex()
    , _data_triangle()
{

}

Document::Document(const Document& document)
    : _filename(document._filename)
    , _gabaritX(document._gabaritX)
    , _gabaritY(document._gabaritY)
    , _gabaritZ(document._gabaritZ)
    , _num(document._num)
    , _data_vertex(document._data_vertex)
    , _data_triangle(document._data_triangle)
{

}

Document::Document(const Document&& document)
    : _filename(document._filename)
    , _gabaritX(document._gabaritX)
    , _gabaritY(document._gabaritY)
    , _gabaritZ(document._gabaritZ)
    , _num(document._num)
    , _data_vertex(document._data_vertex)
    , _data_triangle(document._data_triangle)
{

}

Document& Document::operator=(const Document& document)
{
    if(this == &document)
        return *this;

    _filename = document._filename;
    _num = document._num;
    _data_vertex = document._data_vertex;
    _data_triangle = document._data_triangle;
    _gabaritX = document._gabaritX;
    _gabaritY = document._gabaritY;
    _gabaritZ = document._gabaritZ;

    return *this;
}

Document& Document::operator=(const Document&& document)
{
    if(this == &document)
        return *this;

    _filename = document._filename;
    _num = document._num;
    _data_vertex = document._data_vertex;
    _data_triangle = document._data_triangle;
    _gabaritX = document._gabaritX;
    _gabaritY = document._gabaritY;
    _gabaritZ = document._gabaritZ;

    return *this;
}

Document::~Document(){ }


bool Document::SaveAs(QString filename)
{
    bool result = false;

    _filename = filename;
    if(Save())
    {
        //result = DocumentManager::GetInstance().RenameDocument(this, filename);
    }

    return result;
}

QString Document::GetName() const
{
    return _filename;
}

void Document::setGabsritX(double& x)
{
    _gabaritX = x;
}

void Document::setGabsritY(double& y)
{
    _gabaritY = y;
}

void Document::setGabsritZ(double& z)
{
    _gabaritZ = z;
}

void Document::calculateGabrit()
{
    auto minMaxX = std::minmax_element(_data_vertex.begin(), _data_vertex.end(), Primitive3D::compareX);
    _gabaritX = minMaxX.second->getX() - minMaxX.first->getX();

    auto minMaxY = std::minmax_element(_data_vertex.begin(), _data_vertex.end(), Primitive3D::compareY);
    _gabaritY = minMaxY.second->getY() - minMaxY.first->getY();

    auto minMaxZ = std::minmax_element(_data_vertex.begin(), _data_vertex.end(), Primitive3D::compareZ);
    _gabaritZ = minMaxZ.second->getZ() - minMaxZ.first->getZ();


}
void Document::calculateNum()
{
    _num = static_cast<uint32_t>(_data_triangle.size());
}

double Document::getGabaritX() const
{
    return _gabaritX;
}

double Document::getGabaritY() const
{
    return _gabaritY;
}

double Document::getGabaritZ() const
{
    return _gabaritZ;
}
