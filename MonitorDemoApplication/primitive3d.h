#ifndef PRIMITIVE3D_H
#define PRIMITIVE3D_H

#include <QString>
#include <fstream>
#include <memory>

class Primitive3D
{
public:
    enum class primitiveType
    {
        GEOMETRIC_VERTEX,
        GEOMETRIC_VECTOR
    };

    Primitive3D();
    Primitive3D(const Primitive3D& primitive3D);
    Primitive3D(const Primitive3D&& primitive3D);

    Primitive3D& operator=(const Primitive3D& primitive3D);
    Primitive3D& operator=(const Primitive3D&& primitive3D);

    virtual ~Primitive3D();

    virtual primitiveType getPrimitiveType() const = 0;

    void setX(float& x);
    void setY(float& y);
    void setZ(float& z);

    void setKoordinate(float& x, float& y, float& z);

    float getX() const;
    float getY() const;
    float getZ() const;

    friend bool operator==(const Primitive3D& primitive3D_1, const Primitive3D& primitive3D_2);
    friend bool operator!=(const Primitive3D& primitive3D_1, const Primitive3D& primitive3D_2);

    static bool compareX(const std::shared_ptr<Primitive3D> primitive3D_1, const std::shared_ptr<Primitive3D> primitive3D_2);
    static bool compareY(const std::shared_ptr<Primitive3D> primitive3D_1, const std::shared_ptr<Primitive3D> primitive3D_2);
    static bool compareZ(const std::shared_ptr<Primitive3D> primitive3D_1, const std::shared_ptr<Primitive3D> primitive3D_2);

    friend std::ifstream& operator>>(std::ifstream& in, Primitive3D& primitive3D);
    friend std::ofstream& operator<<(std::ofstream& out, const Primitive3D& primitive3D);

protected:
    float _x;
    float _y;
    float _z;
};

bool is_floatEqual(const float& epr_1, const float& expr_2);

#endif // PRIMITIVE3D_H
