#include "modelstl.h"
#include <QFile>
#include <fstream>
#include"noninitvariable.h"

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

std::ifstream& operator>>(std::ifstream& in, ModelSTL model)
{
    char header[80] = "";
    char num[4] = "";

    in.read(header, 80);
    in.read(num, 4);

    model._model_title = header;
    model._num = static_cast<uint32_t>(*num);

    for(size_t i = 0; i < model._num; ++i)
    {
        ModelSTL::STL_poligon poligon;
        in.read((char*)&poligon, 50);

        Triangle triangle;
        Vector triangleNormal;
        GraphicVertex vertex_1;
        GraphicVertex vertex_2;
        GraphicVertex vertex_3;

        double normalX = static_cast<double>(poligon.normalX);
        double normalY = static_cast<double>(poligon.normalY);
        double normalZ = static_cast<double>(poligon.normalZ);
        double point_1X = static_cast<double>(poligon.point_1X);
        double point_1Y = static_cast<double>(poligon.point_1Y);
        double point_1Z = static_cast<double>(poligon.point_1Z);
        double point_2X = static_cast<double>(poligon.point_2X);
        double point_2Y = static_cast<double>(poligon.point_2Y);
        double point_2Z = static_cast<double>(poligon.point_2Z);
        double point_3X = static_cast<double>(poligon.point_3X);
        double point_3Y = static_cast<double>(poligon.point_3Y);
        double point_3Z = static_cast<double>(poligon.point_3Z);

        triangleNormal.setX(normalX);
        triangleNormal.setX(normalY);
        triangleNormal.setX(normalZ);

        vertex_1.setNormal(triangleNormal);
        vertex_2.setNormal(triangleNormal);
        vertex_3.setNormal(triangleNormal);

        vertex_1.setKoordinate(point_1X, point_1Y, point_1Z);
        vertex_2.setKoordinate(point_2X, point_2Y, point_2Z);
        vertex_3.setKoordinate(point_3X, point_3Y, point_3Z);

        triangle.setTriangleVector(triangleNormal);

        if(!model._data_vertex.empty())
        {
            for(auto it = model._data_vertex.begin(); it != model._data_vertex.end(); ++it)
            {
                if(*it == vertex_1)
                {
                    triangle.setVertex_1(std::make_shared<GraphicVertex>(*it));
                }
                else if (*it == vertex_2)
                {
                    triangle.setVertex_2(std::make_shared<GraphicVertex>(*it));
                }
                else if (*it == vertex_3)
                {
                    triangle.setVertex_3(std::make_shared<GraphicVertex>(*it));
                }
            }
            if (triangle.getVertex_1() == NonInit::graphicVertex)
            {
                model._data_vertex.push_back(vertex_1);
                triangle.setVertex_1(std::make_shared<GraphicVertex>(--model._data_vertex.end()));
            }
            if (triangle.getVertex_2() == NonInit::graphicVertex)
            {
                model._data_vertex.push_back(vertex_2);
                triangle.setVertex_2(std::make_shared<GraphicVertex>(--model._data_vertex.end()));
            }
            if (triangle.getVertex_3() == NonInit::graphicVertex)
            {
                model._data_vertex.push_back(vertex_3);
                triangle.setVertex_3(std::make_shared<GraphicVertex>(--model._data_vertex.end()));
            }
        }
        else
        {
            model._data_vertex.push_back(vertex_1);
            model._data_vertex.push_back(vertex_2);
            model._data_vertex.push_back(vertex_3);

            triangle.setVertex_1(std::make_shared<GraphicVertex>(vertex_1));
            triangle.setVertex_2(std::make_shared<GraphicVertex>(vertex_2));
            triangle.setVertex_3(std::make_shared<GraphicVertex>(vertex_3));
        }
        model._data_triangle.push_back(triangle);
    }
    return in;
}

std::ofstream& operator<<(std::ofstream& out, const ModelSTL& model)
{
    //char header[80] = model._model_title.toStdString().c_str();
    //char num[4] = static_cast<char>(model._num);

//    out << model._model_title.toStdString().c_str()
//        << static_cast<char>(model._num);

//    ModelSTL::STL_poligon poligon;


//    for(auto it = model._data_triangle.begin(); it != model._data_triangle.end(); ++it)
//    {
//        out << it->getTriangleVector()
//            << it->getVertex_1()
//            << it->getVertex_2()
//            << it->getVertex_3()
//            << '0' << ' ' << '0';
//    }
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
        in.close();
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

        result = true;
    }

    return result;
}
