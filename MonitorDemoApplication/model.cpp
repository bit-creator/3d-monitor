#include "model.h"

Model::Model(){}

Model::~Model(){}

QTextStream& operator>>(QTextStream& in, Model model)
{
    unsigned short int attribute_byte_count;

    const Vertex non_initialize;

    in >> model.model_title;
    in >> model.num;

    for(size_t i = 0; i < model.num; ++i)
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
                model.data_vertex.emplace_back(vertex_1);
                triangle.set_vertex_1(model.data_vertex.end());
            }
            if (triangle.get_vertex_2() == non_initialize)
            {
                model.data_vertex.emplace_back(vertex_2);
                triangle.set_vertex_2(model.data_vertex.end());
            }
            if (triangle.get_vertex_3() == non_initialize)
            {
                model.data_vertex.emplace_back(vertex_3);
                triangle.set_vertex_3(model.data_vertex.end());
            }
        }
        else
        {
            model.data_vertex.emplace_back(vertex_1);
            model.data_vertex.emplace_back(vertex_2);
            model.data_vertex.emplace_back(vertex_3);
            triangle.set_vertex_1(model.data_vertex.begin());
            triangle.set_vertex_2(++model.data_vertex.begin());
            triangle.set_vertex_3(model.data_vertex.end());
        }
        model.data_triangle.emplace_back(triangle);
    }
    return in;
}

QTextStream& operator<<(QTextStream& out, Model model)
{
    out << model.model_title
        << model.num;

    for(iter_t it = model.data_triangle.begin(); it != model.data_triangle.end(); ++it)
    {
        out << it->get_vector()
            << it->get_vertex_1()
            << it->get_vertex_2()
            << it->get_vertex_3()
            << '0' << ' ' << '0';
    }
    return out;
}
