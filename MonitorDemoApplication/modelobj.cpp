#include "modelobj.h"
#include <QFile>

ModelOBJ::ModelOBJ(QString filename)
    : Document3D(filename)
{

}

ModelOBJ::ModelOBJ(const ModelOBJ& model)
    : Document3D(model.GetName())
{

}

ModelOBJ::ModelOBJ(const ModelOBJ&& model)
    : Document3D(model.GetName())
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

ModelOBJ::MeshType ModelOBJ::GetMeshType() const
{
    return MeshType::OBJ;
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
//    std::string str;
//    char control_symbol[2];
//    while(!in.end)
//    {
//        std::list<UVCoordinate> texture_data;

//        in >> control_symbol;
//        if(control_symbol[0] == '#')
//        {
//            in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//        }
//        else if(control_symbol[0] == 'v'
//                && control_symbol[1] != 't')
//        {
//            TriangleVertex newVertex;
//            double x = 0.,
//                   y = 0.,
//                   z = 0.,
//                   w = 1.;
//            in >> x >> y >> z;

//            newVertex.setKoordinate(x, y, z);
//            newVertex.setWeight(w);

//            char syb;

//            in >> syb;

//            if(syb != '\n')
//            {
//                in >> w;
//                newVertex.setWeight(w);
//            }
//            model._data_vertex.push_back(newVertex);
//        }
//        else if(control_symbol[0] == 'v'
//                && control_symbol[1] == 't')
//        {
//            UVCoordinate textureCor;

//            double U, V, W;

//            in >> U >> V >> W;

//            textureCor.setKoordinate(U, V, W);

//            texture_data.push_back(textureCor);
//        }
//        else if(control_symbol[0] == 'f')
//        {

//        }

//    }
    return in;
}

std::ofstream& operator<<(std::ofstream& out, const ModelOBJ& model)
{

    return out;
}
