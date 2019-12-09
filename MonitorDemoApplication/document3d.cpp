#include "document3d.h"

Document3D::Document3D(QString filename)
    : Document(filename)
    , _gabaritX(0.)
    , _gabaritY(0.)
    , _gabaritZ(0.)
    , _num(0)
    , _data_vertex()
    , _data_triangle()
{

}

Document3D::Document3D(const Document3D& document)
    : Document(document.GetName())
    , _gabaritX(document._gabaritX)
    , _gabaritY(document._gabaritY)
    , _gabaritZ(document._gabaritZ)
    , _num(document._num)
    , _data_vertex(document._data_vertex)
    , _data_triangle(document._data_triangle)
{

}

Document3D::Document3D(const Document3D&& document)
    : Document(document.GetName())
    , _gabaritX(std::move(document._gabaritX))
    , _gabaritY(std::move(document._gabaritY))
    , _gabaritZ(std::move(document._gabaritZ))
    , _num(std::move(document._num))
    , _data_vertex(std::move(document._data_vertex))
    , _data_triangle(std::move(document._data_triangle))
{

}

Document3D& Document3D::operator=(const Document3D& document)
{
    if(this == &document)
        return *this;

    //_filename = (document.GetName());
    _num = document._num;
    _data_vertex = document._data_vertex;
    _data_triangle = document._data_triangle;
    _gabaritX = document._gabaritX;
    _gabaritY = document._gabaritY;
    _gabaritZ = document._gabaritZ;

    return *this;
}

Document3D& Document3D::operator=(const Document3D&& document)
{
    if(this == &document)
        return *this;

   // _filename = document._filename;
    _num = std::move(document._num);
    _data_vertex = std::move(document._data_vertex);
    _data_triangle = std::move(document._data_triangle);
    _gabaritX = std::move(document._gabaritX);
    _gabaritY = std::move(document._gabaritY);
    _gabaritZ = std::move(document._gabaritZ);

    return *this;
}

Document3D::~Document3D(){ }

Document3D::DocumentType Document3D::GetDocumentType() const
{
    return DocumentType::MESH_DOCUMENT;
}



void Document3D::setGabsritX(float& x)
{
    _gabaritX = x;
}

void Document3D::setGabsritY(float& y)
{
    _gabaritY = y;
}

void Document3D::setGabsritZ(float& z)
{
    _gabaritZ = z;
}

void Document3D::calculateGabrit()
{
    //auto minMaxX = std::minmax_element(_data_vertex.begin(), _data_vertex.end(), Primitive3D::compareX);
    //_gabaritX = *(minMaxX.first)

    //auto minMaxY = std::minmax_element(_data_vertex.begin(), _data_vertex.end(), Primitive3D::compareY);
    //_gabaritY = minMaxY.second->getY() - minMaxY.first->getY();

    //auto minMaxZ = std::minmax_element(_data_vertex.begin(), _data_vertex.end(), Primitive3D::compareZ);
    //_gabaritZ = *(minMaxZ.second)->getZ() - minMaxZ.first->getZ();
}

void Document3D::calculateNum()
{
    _num = static_cast<uint32_t>(_data_triangle.size());
}

float Document3D::getGabaritX() const
{
    return _gabaritX;
}

float Document3D::getGabaritY() const
{
    return _gabaritY;
}

float Document3D::getGabaritZ() const
{
    return _gabaritZ;
}
