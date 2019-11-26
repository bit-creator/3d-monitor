#include "model.h"

Model::Model(){ }

Model::Model(const Model& model) :
    model_title(model.model_title),
    num(model.num),
    data_vertex(model.data_vertex),
    data_triangle(model.data_triangle) { }

Model::Model(const Model&& model) :
    model_title(model.model_title),
    num(model.num),
    data_vertex(model.data_vertex),
    data_triangle(model.data_triangle) { }

Model& Model::operator=(const Model& model)
{
    if(this == &model)
        return *this;

    model_title = model.model_title;
    num = model.num;
    data_vertex = model.data_vertex;
    data_triangle = model.data_triangle;

    return *this;
}


Model& Model::operator=(const Model&& model)
{
    if(this == &model)
        return *this;

    model_title = model.model_title;
    num = model.num;
    data_vertex = model.data_vertex;
    data_triangle = model.data_triangle;

    return *this;
}

Model::~Model(){}

QTextStream& operator>>(QTextStream& in, Model model)
{
    char title[80];

    const Vertex non_initialize;

    unsigned short int attribute_byte_count;

    in >> title;

    model.model_title = title;

    in >> model.num;

    for(size_t i = 0; in.atEnd(); ++i)
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

        triangle.set_vector(vector);

        if(!model.data_vertex.empty())
        {
            for(iter it = model.data_vertex.begin(); it != model.data_vertex.end(); ++it)
            {
                if(*it == vertex_1)
                {
                    triangle.set_vertex_1(it);
                }
                else if (*it == vertex_2)
                {
                    triangle.set_vertex_2(it);
                }
                else if (*it == vertex_3)
                {
                    triangle.set_vertex_3(it);
                }
            }
            if (triangle.get_vertex_1() == non_initialize)
            {
                model.data_vertex.push_back(vertex_1);
                triangle.set_vertex_1(model.data_vertex.end());
            }
            if (triangle.get_vertex_2() == non_initialize)
            {
                model.data_vertex.push_back(vertex_2);
                triangle.set_vertex_2(model.data_vertex.end());
            }
            if (triangle.get_vertex_3() == non_initialize)
            {
                model.data_vertex.push_back(vertex_3);
                triangle.set_vertex_3(model.data_vertex.end());
            }
        }
        else
        {
            model.data_vertex.push_back(vertex_1);
            model.data_vertex.push_back(vertex_2);
            model.data_vertex.push_back(vertex_3);
            triangle.set_vertex_1(model.data_vertex.begin());
            triangle.set_vertex_2(++model.data_vertex.begin());
            triangle.set_vertex_3(model.data_vertex.end());
        }
        model.data_triangle.push_back(triangle);
    }
    return in;
}

QTextStream& operator<<(QTextStream& out,const Model& model)
{
    out << model.model_title
        << model.num;

    for(auto it = model.data_triangle.begin(); it != model.data_triangle.end(); ++it)
    {
        out << it->get_vector()
            << it->get_vertex_1()
            << it->get_vertex_2()
            << it->get_vertex_3()
            << '0' << ' ' << '0';
    }
    return out;
}

//Model& operator+(const Model& model, const Model& model_)
//{
//    for(auto it = model_.data_triangle.begin(); it != model_.data_triangle.end(); ++it)
//    {
////        if()
//    }
//}

Model::Document_Type Model::get_document_type()
{
    return Document_Type::STL;
}
