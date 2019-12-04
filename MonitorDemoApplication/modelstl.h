#ifndef MODEL_H
#define MODEL_H

#include "document.h"
#include "triangle.h"

class ModelSTL : public Document
{
public:
    ModelSTL(QString filename);
    ModelSTL(const ModelSTL& model);
    ModelSTL(const ModelSTL&& model);

    ModelSTL& operator=(const ModelSTL& model);
    ModelSTL& operator=(const ModelSTL&& model);

    virtual ~ModelSTL() override;

    virtual DocumentType GetType() const override;
    virtual bool Open() override;
    virtual bool Save() override;

    friend std::ifstream& operator>>(std::ifstream& in, ModelSTL model);
    friend std::ofstream& operator<<(std::ofstream& out, const ModelSTL& model);

private:
    QString _model_title;
    uint32_t _num;
    std::list<Vertex> _data_vertex;
    std::list<Triangle> _data_triangle;
};

#endif // MODEL_H
