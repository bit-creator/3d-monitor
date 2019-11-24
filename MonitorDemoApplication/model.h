#ifndef MODEL_H
#define MODEL_H

#include "triangle.h"

using iter_t = std::list<Triangle>::iterator;

class Model
{
public:
    Model();
    Model(Model& model);
    Model(Model&& model);

    Model& operator=(const Model& model);
    Model& operator=(const Model&& model);

    ~Model();

    friend QTextStream& operator>>(QTextStream& in, Model model);
    friend QTextStream& operator<<(QTextStream& out, Model& model);

    friend Model& operator+(const Model& model, const Model& model_);

private:
    QString model_title;
    unsigned int num;
    std::list<Vertex> data_vertex;
    std::list<Triangle> data_triangle;
};

#endif // MODEL_H
