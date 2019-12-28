#include "modelstl.h"
#include <QFile>
#include <fstream>

constexpr float KRITIC_COS = 0.9659258;

ModelSTL::ModelSTL(QString filename)
    : Document3D(filename)
{

}

ModelSTL::ModelSTL(const ModelSTL& model)
    : Document3D(model.GetName())
    , _model_title(model._model_title)
{

}

ModelSTL::ModelSTL(const ModelSTL&& model)
    : Document3D(model.GetName())
    , _model_title(model._model_title)
{

}

ModelSTL& ModelSTL::operator=(const ModelSTL& model)
{
    if(this == &model)
        return *this;

    _model_title = model._model_title;
    _num = model._num;
    _data_vertex = model._data_vertex;
    _data_triangle = model._data_triangle;

    return *this;
}


ModelSTL& ModelSTL::operator=(const ModelSTL&& model)
{
    if(this == &model)
        return *this;

    _model_title = model._model_title;
    _num = model._num;
    _data_vertex = model._data_vertex;
    _data_triangle = model._data_triangle;

    return *this;
}

ModelSTL::~ModelSTL(){}

std::ifstream& operator>>(std::ifstream& in, ModelSTL& model)
{
    char header[80] = "";//Here should be the text of our header! 2 Here should be the text of our header!";
    uint32_t num = 0;

    in.read(header, 80);
    in.read((char*)&num, 4);

    model._model_title = header;
    model._num = num;


//    Triangle triangle;
//    Vector triangleNormal;
//    GraphicVertex vertex_1;
//    GraphicVertex vertex_2;
//    GraphicVertex vertex_3;

//    triangleNormal.setX(1.);
//    triangleNormal.setY(2.);
//    triangleNormal.setZ(3.);

//    vertex_1.setNormal(triangleNormal);
//    vertex_2.setNormal(triangleNormal);
//    vertex_3.setNormal(triangleNormal);

//    vertex_1.setKoordinate(11., 12., 13.);
//    vertex_2.setKoordinate(21., 22., 23.);
//    vertex_3.setKoordinate(31., 32., 33.);

//    triangle.setTriangleVector(triangleNormal);

//    if(!model._data_vertex.empty())
//    {
//        for(auto it = model._data_vertex.begin(); it != model._data_vertex.end(); ++it)
//        {
//            if(**it == vertex_1)
//            {
//                triangle.setVertex_1(*it);
//            }
//            else if (**it == vertex_2)
//            {
//                triangle.setVertex_2(*it);
//            }
//            else if (**it == vertex_3)
//            {
//                triangle.setVertex_3(*it);
//            }
//        }
//        if (triangle.getVertex_1() == nullptr)
//        {
//            model._data_vertex.push_back(std::make_shared<GraphicVertex>(vertex_1));
//            triangle.setVertex_1(*--model._data_vertex.end());
//        }
//        if (triangle.getVertex_2() == nullptr)
//        {
//            model._data_vertex.push_back(std::make_shared<GraphicVertex>(vertex_2));
//            triangle.setVertex_2(*--model._data_vertex.end());
//        }
//        if (triangle.getVertex_3() == nullptr)
//        {
//            model._data_vertex.push_back(std::make_shared<GraphicVertex>(vertex_3));
//            triangle.setVertex_3(*--model._data_vertex.end());
//        }
//    }
//    else
//    {
//        model._data_vertex.push_back(std::make_shared<GraphicVertex>(vertex_1));
//        model._data_vertex.push_back(std::make_shared<GraphicVertex>(vertex_2));
//        model._data_vertex.push_back(std::make_shared<GraphicVertex>(vertex_3));

//        triangle.setVertex_1(*model._data_vertex.begin());
//        triangle.setVertex_2(*++model._data_vertex.begin());
//        triangle.setVertex_3(*--model._data_vertex.end());
//    }
//    model._data_triangle.push_back(std::make_shared<Triangle>(triangle));

    ModelSTL::STL_poligon poligon;


    for(uint32_t i = 0; i < model._num; ++i)
    {
        in.read((char*)&poligon, 50);

        Triangle triangle;
        Vector triangleNormal;
        GraphicVertex vertex_1;
        GraphicVertex vertex_2;
        GraphicVertex vertex_3;

        triangleNormal.setX(poligon.normalX);
        triangleNormal.setY(poligon.normalY);
        triangleNormal.setZ(poligon.normalZ);

        vertex_1.setNormal(triangleNormal);
        vertex_2.setNormal(triangleNormal);
        vertex_3.setNormal(triangleNormal);

        vertex_1.setKoordinate(poligon.point_1X, poligon.point_1Y, poligon.point_1Z);
        vertex_2.setKoordinate(poligon.point_2X, poligon.point_2Y, poligon.point_2Z);
        vertex_3.setKoordinate(poligon.point_3X, poligon.point_3Y, poligon.point_3Z);

        triangle.setTriangleVector(triangleNormal);

        if(!model._data_vertex.empty())
        {
            for(auto it = model._data_vertex.begin(); it != model._data_vertex.end(); ++it)
            {
                if(**it == vertex_1)
                {
                    triangle.setVertex_1(*it);
                }
                else if (**it == vertex_2)
                {
                    triangle.setVertex_2(*it);
                }
                else if (**it == vertex_3)
                {
                    triangle.setVertex_3(*it);
                }
            }
            if (triangle.getVertex_1() == nullptr)
            {
                model._data_vertex.push_back(std::make_shared<GraphicVertex>(vertex_1));
                triangle.setVertex_1(*--model._data_vertex.end());
            }
            if (triangle.getVertex_2() == nullptr)
            {
                model._data_vertex.push_back(std::make_shared<GraphicVertex>(vertex_2));
                triangle.setVertex_2(*--model._data_vertex.end());
            }
            if (triangle.getVertex_3() == nullptr)
            {
                model._data_vertex.push_back(std::make_shared<GraphicVertex>(vertex_3));
                triangle.setVertex_3(*--model._data_vertex.end());
            }
        }
        else
        {
            model._data_vertex.push_back(std::make_shared<GraphicVertex>(vertex_1));
            model._data_vertex.push_back(std::make_shared<GraphicVertex>(vertex_2));
            model._data_vertex.push_back(std::make_shared<GraphicVertex>(vertex_3));

            triangle.setVertex_1(*model._data_vertex.begin());
            triangle.setVertex_2(*++model._data_vertex.begin());
            triangle.setVertex_3(*--model._data_vertex.end());
        }
        model._data_triangle.push_back(std::make_shared<Triangle>(triangle));
    }

    return in;
}

std::ofstream& operator<<(std::ofstream& out, const ModelSTL& model)
{
    std::string str_header = model._model_title.toStdString();
    const char* header = str_header.c_str();
    //const char* num = std::to_string(model._num).c_str();

    out.write(header, 80);
    out.write((char*)&model._num, 4);

    ModelSTL::STL_poligon poligon;

    for(auto it = model._data_triangle.begin(); it != model._data_triangle.end(); ++it)
    {
        if(*it == nullptr)
            return out;

        poligon.normalX = (*it)->getTriangleVector().getX();
        poligon.normalY = (*it)->getTriangleVector().getY();
        poligon.normalZ = (*it)->getTriangleVector().getZ();
        poligon.point_1X = (*it)->getVertex_1()->getX();
        poligon.point_1Y = (*it)->getVertex_1()->getY();
        poligon.point_1Z = (*it)->getVertex_1()->getZ();
        poligon.point_2X = (*it)->getVertex_2()->getX();
        poligon.point_2Y = (*it)->getVertex_2()->getY();
        poligon.point_2Z = (*it)->getVertex_2()->getZ();
        poligon.point_3X = (*it)->getVertex_3()->getX();
        poligon.point_3Y = (*it)->getVertex_3()->getY();
        poligon.point_3Z = (*it)->getVertex_3()->getZ();

        out.write((char*)&poligon, 50);
    }
    return out;
}

ModelSTL::MeshType ModelSTL::GetMeshType() const
{
    return MeshType::STL;
}

bool ModelSTL::Open()
{
    bool result = false;

    QFile model(GetName());
    if(model.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        QString error = model.errorString();
        std::string filename = GetName().toStdString();
        std::ifstream in(filename, std::ios::binary);
        in >> *this;
        model.close();
        result = true;
    }

    return result;
}

bool ModelSTL::Save()
{
    bool result = false;

    QFile model(GetName());
    if(model.open(QIODevice::WriteOnly))
    {
        std::string filename = GetName().toStdString();
        std::ofstream out(filename, std::ios::binary);
        out << *this;
        model.close();
        result = true;
    }

    return result;
}


void ModelSTL::normalColision()
{
    numOfTriangleNormalColision = 0;

    for(auto iter = (*this)._data_triangle.begin(); iter != (*this)._data_triangle.end(); ++iter)
    {
        if((*iter)->getTriangleVector() != (*iter)->calculateTriangleNormal())
        {
            ++ numOfTriangleNormalColision;
        }
    }
}

void ModelSTL::fixNormal()
{
    if(numOfTriangleNormalColision > 0)
    {
        for(auto iter = (*this)._data_triangle.begin(); iter != (*this)._data_triangle.end(); ++iter)
        {
            (*iter)->setTriangleVector((*iter)->calculateTriangleNormal());
        }
    }
    else
    {
        return;
    }
}

void ModelSTL::makeVertexNormal()
{
    for(auto vertex_iter = (*this)._data_vertex.begin(); vertex_iter != (*this)._data_vertex.end(); ++vertex_iter)
    {
        for(auto triangle_iter = (*this)._data_triangle.begin(); triangle_iter != (*this)._data_triangle.end(); ++triangle_iter)
        {
            if((*triangle_iter)->getVertex_1() == *vertex_iter)
            {
                if((*vertex_iter)->getNormal().VectorAngle((*triangle_iter)->getVertex_1()->getNormal()) <= KRITIC_COS)
                {
                    (*vertex_iter)->setNormal((*vertex_iter)->getNormal() + (*triangle_iter)->getTriangleVector());
                }
                else
                {
                    (*vertex_iter)->setNormal((*triangle_iter)->getTriangleVector());
                }
            }
        }
    }
}
