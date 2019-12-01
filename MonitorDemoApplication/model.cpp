#include "model.h"
#include <QFile>
#include <fstream>


ModelSTL::ModelSTL(QString filename)
    : Document(filename)
{

}

ModelSTL::ModelSTL(const ModelSTL& model)
    : Document(model.GetName())
    , _model_title(model._model_title)
    , _num(model._num)
    , _data_vertex(model._data_vertex)
    , _data_triangle(model._data_triangle)
{

}

ModelSTL::ModelSTL(const ModelSTL&& model)
    : Document(model.GetName())
    , _model_title(model._model_title)
    , _num(model._num)
    , _data_vertex(model._data_vertex)
    , _data_triangle(model._data_triangle)
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
    const Vertex non_initialize;

    unsigned short int attribute_byte_count;

    char str[80];
    in.read(str, 80);
    model._model_title = str;

    in >> model._num;

    for(size_t i = 0; in.end; ++i)
    {
        Vector vector;
        Vertex vertex_1,
               vertex_2,
               vertex_3;

        in >> vector
           >> vertex_1
           >> vertex_2
           >> vertex_3
           >> attribute_byte_count
           >> attribute_byte_count;

        Triangle triangle;

        triangle.setVector(vector);

        if(!model._data_vertex.empty())
        {
            for(iter it = model._data_vertex.begin(); it != model._data_vertex.end(); ++it)
            {
                if(*it == vertex_1)
                {
                    triangle.setVertex_1(it);
                }
                else if (*it == vertex_2)
                {
                    triangle.setVertex_2(it);
                }
                else if (*it == vertex_3)
                {
                    triangle.setVertex_3(it);
                }
            }
            if (triangle.getVertex_1() == non_initialize)
            {
                model._data_vertex.push_back(vertex_1);
                triangle.setVertex_1(model._data_vertex.end());
            }
            if (triangle.getVertex_2() == non_initialize)
            {
                model._data_vertex.push_back(vertex_2);
                triangle.setVertex_2(model._data_vertex.end());
            }
            if (triangle.getVertex_3() == non_initialize)
            {
                model._data_vertex.push_back(vertex_3);
                triangle.setVertex_3(model._data_vertex.end());
            }
        }
        else
        {
            model._data_vertex.push_back(vertex_1);
            model._data_vertex.push_back(vertex_2);
            model._data_vertex.push_back(vertex_3);
            triangle.setVertex_1(model._data_vertex.begin());
            triangle.setVertex_2(++model._data_vertex.begin());
            triangle.setVertex_3(model._data_vertex.end());
        }
        model._data_triangle.push_back(triangle);
    }
    return in;
}

std::ofstream& operator<<(std::ofstream& out,const ModelSTL& model)
{
    out << model._model_title
        << model._num;

    for(auto it = model._data_triangle.begin(); it != model._data_triangle.end(); ++it)
    {
        out << it->getVector()
            << it->getVertex_1()
            << it->getVertex_2()
            << it->getVertex_3()
            << '0' << ' ' << '0';
    }
    return out;
}

ModelSTL::DocumentType ModelSTL::GetType() const
{
    return DocumentType::STL;
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
