#include "modelobj.h"
#include <QFile>

ModelOBJ::ModelOBJ(QString filename)
    : Document(filename)
{

}

ModelOBJ::ModelOBJ(const ModelOBJ& model)
    : Document(model.GetName())
{

}

ModelOBJ::ModelOBJ(const ModelOBJ&& model)
    : Document(model.GetName())
{

}

ModelOBJ& ModelOBJ::operator=(const ModelOBJ& model)
{
    if(this == &model)
        return *this;

    _num = model._num;
    _data_vertex = model._data_vertex;
    _data_triangle = model._data_triangle;



    return *this;
}


ModelOBJ& ModelOBJ::operator=(const ModelOBJ&& model)
{
    if(this == &model)
        return *this;



    return *this;
}

ModelOBJ::~ModelOBJ(){}

ModelOBJ::DocumentType ModelOBJ::GetType() const
{
    return DocumentType::OBJ;
}

bool ModelOBJ::Open()
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

bool ModelOBJ::Save()
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

std::ifstream& operator>>(std::ifstream& in, ModelOBJ model)
{
    std::string str;
    char control_symbol;
    while(!in.end)
    {
        in.get(control_symbol);
        if(control_symbol == '#')
        {
            in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if(control_symbol == 'v')
        {

        }

    }
    return in;
}

std::ofstream& operator<<(std::ofstream& out, const ModelOBJ& model)
{

    return out;
}
