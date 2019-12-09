#include "modelobj.h"
#include <QFile>
#include<string>
#include<iterator>

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
    std::string str;
    char control_symbol[2];
    while(!in.end)                                                  //what???
    {
        bool have_texture = true;

        std::list<std::shared_ptr<GeometricVertex>> vertex_data;
        std::list<std::shared_ptr<UVCoordinate>> texture_data;
        std::list<std::shared_ptr<Vector>> normal_data;
        std::list<float> weight_data;

        in >> control_symbol;

        if(control_symbol[0] == '#')
        {
            in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        else if(control_symbol[0] == 'v'
                && control_symbol[1] == ' ')
        {
            GeometricVertex vertex;
            float x = 0.,
                  y = 0.,
                  z = 0.,
                  w = 1.;
            in >> x >> y >> z;

            vertex.setKoordinate(x, y, z);

            vertex_data.push_back(std::make_shared<GeometricVertex>(vertex));

            char syb;

            in >> syb;

            if(syb != '\n')
            {
                in >> w;
                weight_data.push_back(w);
            }
        }

        else if(control_symbol[0] == 'v'
                && control_symbol[1] == 't')
        {
            UVCoordinate textureCor;

            float U, V, W = 0;

            in >> U >> V;

            textureCor.setKoordinate(U, V, W);

            char syb;

            in >> syb;

            if(syb != '\n')
            {
                in >> W;
                textureCor.setW(W);
            }

            texture_data.push_back(std::make_shared<UVCoordinate>(textureCor));
        }

        else if(control_symbol[0] == 'v'
                && control_symbol[1] == 'n')
        {
            Vector normal;

            float x, y, z;

            in >> x >> y >> z;

            normal.setKoordinate(x, y, z);

            normal_data.push_back(std::make_shared<Vector>(normal));
        }

        else if(control_symbol[0] == 'f')
        {
            GraphicVertex vertex_1, vertex_2, vertex_3;

            unsigned int vertex_ind = 0, texture_ind = 0, normal_ind = 0;
            std::string ind;

            getline(in, ind, '/');
            vertex_ind = static_cast<unsigned int>(*ind.c_str());

            if(have_texture)
            {
                getline(in, ind, '/');
                if(!ind.empty())
                {
                    texture_ind = static_cast<unsigned int>(*ind.c_str());
                }
                else
                {
                    have_texture = false;
                }
            }

            getline(in, ind, ' ');
            normal_ind = static_cast<unsigned int>(*ind.c_str());

            auto vertex_iter = vertex_data.begin();
            std::advance(vertex_iter, vertex_ind);

            vertex_1.setGeometricVertex(**vertex_iter);

            auto normal_iter = normal_data.begin();
            std::advance(normal_iter, normal_ind);

            vertex_1.setNormal(**normal_iter);

            if(have_texture)
            {
                auto texture_iter = texture_data.begin();
                std::advance(texture_iter, texture_ind);

                vertex_1.setTextureCoordinate(**texture_iter);
            }
                ////

                getline(in, ind, '/');
                vertex_ind = static_cast<unsigned int>(*ind.c_str());

                if(have_texture)
                {
                    getline(in, ind, '/');
                    if(!ind.empty())
                    {
                        texture_ind = static_cast<unsigned int>(*ind.c_str());
                    }
                    else
                    {
                        have_texture = false;
                    }
                }

                getline(in, ind, ' ');
                normal_ind = static_cast<unsigned int>(*ind.c_str());

                vertex_iter = vertex_data.begin();
                std::advance(vertex_iter, vertex_ind);

                vertex_2.setGeometricVertex(**vertex_iter);

                normal_iter = normal_data.begin();
                std::advance(normal_iter, normal_ind);

                vertex_2.setNormal(**normal_iter);

                if(have_texture)
                {
                    auto texture_iter = texture_data.begin();
                    std::advance(texture_iter, texture_ind);

                    vertex_2.setTextureCoordinate(**texture_iter);
                }

                ////

                getline(in, ind, '/');
                vertex_ind = static_cast<unsigned int>(*ind.c_str());

                if(have_texture)
                {
                    getline(in, ind, '/');
                    if(!ind.empty())
                    {
                        texture_ind = static_cast<unsigned int>(*ind.c_str());
                    }
                    else
                    {
                        have_texture = false;
                    }
                }

                getline(in, ind, ' ');
                normal_ind = static_cast<unsigned int>(*ind.c_str());

                vertex_iter = vertex_data.begin();
                std::advance(vertex_iter, vertex_ind);

                vertex_3.setGeometricVertex(**vertex_iter);

                normal_iter = normal_data.begin();
                std::advance(normal_iter, normal_ind);

                vertex_3.setNormal(**normal_iter);

                if(have_texture)
                {
                    auto texture_iter = texture_data.begin();
                    std::advance(texture_iter, texture_ind);

                    vertex_3.setTextureCoordinate(**texture_iter);
                }

                Triangle triangle;

                model._data_vertex.push_back(std::make_shared<GraphicVertex>(vertex_1));
                triangle.setVertex_1(*(--model._data_vertex.end()));

                model._data_vertex.push_back(std::make_shared<GraphicVertex>(vertex_2));
                triangle.setVertex_2(*(--model._data_vertex.end()));

                model._data_vertex.push_back(std::make_shared<GraphicVertex>(vertex_3));
                triangle.setVertex_3(*(--model._data_vertex.end()));

                triangle.calculateTriangleNormal();

                model._data_triangle.push_back(std::make_shared<Triangle>(triangle));
        }
    }
    return in;
}

std::ofstream& operator<<(std::ofstream& out, const ModelOBJ& model)
{
    for(auto iter = model._data_vertex.begin(); iter != model._data_vertex.end(); ++iter)
    {
        out << 'v' << (*iter)->getX() << ' ' << (*iter)->getY() << ' ' << (*iter)->getZ() << (*iter)->getWeight() << '\n';
    }

    for(auto iter = model._data_vertex.begin(); iter != model._data_vertex.end(); ++iter)
    {
        out << "vt" << (*iter)->getTextureCoordinate().getU() << ' '
            << (*iter)->getTextureCoordinate().getV() << ' '
            << (*iter)->getTextureCoordinate().getW() << '\n';
    }

    for(auto iter = model._data_vertex.begin(); iter != model._data_vertex.end(); ++iter)
    {
        out << "vn" << (*iter)->getNormal().getX() << ' '
            << (*iter)->getNormal().getY() << ' '
            << (*iter)->getNormal().getZ() << '\n';
    }

    for(auto iter = model._data_triangle.begin(); iter != model._data_triangle.end(); ++iter)
    {
        auto vert_iter = model._data_vertex.begin();
        size_t ind = 1;

        while((*iter)->getVertex_1() != **vert_iter) {++ind; ++vert_iter;}
        out << ind << '/' << ind << '/' << ind << ' ';

        vert_iter = model._data_vertex.begin();
        ind = 1;

        while((*iter)->getVertex_2() != **vert_iter) {++ind; ++vert_iter;}
        out << ind << '/' << ind << '/' << ind << ' ';

        vert_iter = model._data_vertex.begin();
        ind = 1;

        while((*iter)->getVertex_3() != **vert_iter) {++ind; ++vert_iter;}
        out << ind << '/' << ind << '/' << ind << '\n';
    }

    return out;
}
