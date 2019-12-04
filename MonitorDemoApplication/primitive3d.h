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

    enum class primitive_type {VERTEX, VECTOR};

    virtual primitive_type get_type() = 0;

    void setX(double& x);
    void setY(double& y);
    void setZ(double& z);

    void setKoordinate(double& x, double& y, double& z);

    double getX() const;
    double getY() const;
    double getZ() const;

    friend std::ifstream& operator>>(std::ifstream& in, Primitive3D& primitive3D);
    friend std::ofstream& operator<<(std::ofstream& out, const Primitive3D& primitive3D);

    friend bool operator==(const Primitive3D& primitive3D_1, const Primitive3D& primitive3D_2);
    friend bool operator!=(const Primitive3D& primitive3D_1, const Primitive3D& primitive3D_2);

protected:
    double _x;
    double _y;
    double _z;
};

#endif // PRIMITIVE3D_H
