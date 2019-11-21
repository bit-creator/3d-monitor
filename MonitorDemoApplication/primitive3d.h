#ifndef PRIMITIVE3D_H
#define PRIMITIVE3D_H

#include <QString>
#include <QTextStream>

class Primitive3D
{
public:
    Primitive3D();
    Primitive3D(Primitive3D& primitive3D);
    Primitive3D(Primitive3D&& primitive3D);

    Primitive3D& operator=(const Primitive3D& primitive3D);
    Primitive3D& operator=(const Primitive3D&& primitive3D);

    virtual ~Primitive3D();

    virtual QString get_type() = 0;

    void set_x(double& x);
    void set_y(double& y);
    void set_z(double& z);

    void set_koordinate(double& x, double& y, double& z);

    double get_x() const;
    double get_y() const;
    double get_z() const;

    friend QTextStream& operator>>(QTextStream& in, Primitive3D& primitive3D);
    friend QTextStream& operator<<(QTextStream& out, const Primitive3D& primitive3D);

protected:
    double _x;
    double _y;
    double _z;
    enum class type {VERTEX, VECTOR};
};

#endif // PRIMITIVE3D_H
