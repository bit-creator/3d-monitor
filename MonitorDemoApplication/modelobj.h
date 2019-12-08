#ifndef MODELOBJ_H
#define MODELOBJ_H

#include "document3d.h"

class ModelOBJ : public Document3D
{
public:
    ModelOBJ(QString filename);
    ModelOBJ(const ModelOBJ& model);
    ModelOBJ(const ModelOBJ&& model);

    ModelOBJ& operator=(const ModelOBJ& model);
    ModelOBJ& operator=(const ModelOBJ&& model);

    virtual ~ModelOBJ() override;

    virtual MeshType GetMeshType() const override;

    virtual bool Open() override;
    virtual bool Save() override;

    friend std::ifstream& operator>>(std::ifstream& in, ModelOBJ model);
    friend std::ofstream& operator<<(std::ofstream& out, const ModelOBJ& model);
};

#endif // MODELOBJ_H
