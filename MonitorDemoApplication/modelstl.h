#ifndef MODEL_H
#define MODEL_H

#include "document3d.h"

class ModelSTL : public Document3D
{
public:
    struct STL_poligon
    {
        float normalX;
        float normalY;
        float normalZ;
        float point_1X;
        float point_1Y;
        float point_1Z;
        float point_2X;
        float point_2Y;
        float point_2Z;
        float point_3X;
        float point_3Y;
        float point_3Z;
        char bytecount1 = 0;
        char bytecount2 = 0;
    };

    ModelSTL(QString filename);
    ModelSTL(const ModelSTL& model);
    ModelSTL(const ModelSTL&& model);

    ModelSTL& operator=(const ModelSTL& model);
    ModelSTL& operator=(const ModelSTL&& model);

    virtual ~ModelSTL() override;

    virtual MeshType GetMeshType() const override;

    virtual bool Open() override;
    virtual bool Save() override;

    friend std::ifstream& operator>>(std::ifstream& in, ModelSTL model);
    friend std::ofstream& operator<<(std::ofstream& out, const ModelSTL& model);

private:
    QString _model_title;
};

#endif // MODEL_H
