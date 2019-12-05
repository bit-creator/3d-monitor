#ifndef MODELOBJ_H
#define MODELOBJ_H

#include "document.h";

class ModelOBJ : public Document
{
public:
    ModelOBJ(QString filename);
    ModelOBJ(const ModelOBJ& model);
    ModelOBJ(const ModelOBJ&& model);

    ModelOBJ& operator=(const ModelOBJ& model);
    ModelOBJ& operator=(const ModelOBJ&& model);

    virtual ~ModelOBJ() override;

    virtual DocumentType GetType() const override;

    virtual bool Open() override;
    virtual bool Save() override;

    friend std::ifstream& operator>>(std::ifstream& in, ModelOBJ model);
    friend std::ofstream& operator<<(std::ofstream& out, const ModelOBJ& model);
};

#endif // MODELOBJ_H
