#ifndef PRIMITIVE3D_H
#define PRIMITIVE3D_H

#include <QString>
#include <fstream>

class Primitive3D
{
public:
    Primitive3D();
    Primitive3D(const Primitive3D& primitive3D);
    Primitive3D(const Primitive3D&& primitive3D);

    Primitive3D& operator=(const Primitive3D& primitive3D);
    Primitive3D& operator=(const Primitive3D&& primitive3D);

    virtual ~Primitive3D();

    enum class primitiveType
    {
        VERTEX,
        VECTOR
    };

    virtual primitiveType getType() = 0;

    void setX(double& x);
    void setY(double& y);
    void setZ(double& z);

    void setKoordinate(double& x, double& y, double& z);

    double getX() const;
    double getY() const;
    double getZ() const;

    friend bool operator==(const Primitive3D& primitive3D_1, const Primitive3D& primitive3D_2);
    friend bool operator!=(const Primitive3D& primitive3D_1, const Primitive3D& primitive3D_2);

    static bool compareX(const Primitive3D& primitive3D_1, const Primitive3D& primitive3D_2);
    static bool compareY(const Primitive3D& primitive3D_1, const Primitive3D& primitive3D_2);
    static bool compareZ(const Primitive3D& primitive3D_1, const Primitive3D& primitive3D_2);

    friend std::ifstream& operator>>(std::ifstream& in, Primitive3D& primitive3D);
    friend std::ofstream& operator<<(std::ofstream& out, const Primitive3D& primitive3D);


protected:
    double _x;
    double _y;
    double _z;
};

#endif // PRIMITIVE3D_H
