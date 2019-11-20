#include "triangle.h"

triangle::~triangle(){}

triangle& triangle::operator=(const triangle& triangle)
{
    if(this == &triangle)
        return *this;

    _normal = triangle._normal;
    _point_1 = triangle._point_1;
    _point_2 = triangle._point_2;
    _point_3 = triangle._point_3;

    return *this;
}

triangle& triangle::operator=(const triangle&& triangle)
{
    if(this == &triangle)
        return *this;

    _normal = triangle._normal;
    _point_1 = triangle._point_1;
    _point_2 = triangle._point_2;
    _point_3 = triangle._point_3;

    return *this;
}

XYZ triangle::get_normal() const
{
    return _normal;
}

XYZ triangle::get_point_1() const
{
    return _point_1;
}

XYZ triangle::get_point_2() const
{
    return _point_2;
}

XYZ triangle::get_point_3() const
{
    return _point_3;
}

QTextStream& operator>>(QTextStream in, triangle& triangle)
{
    double normal_x,
           normal_y,
           normal_z,

           point_1_x,
           point_1_y,
           point_1_z,

           point_2_x,
           point_2_y,
           point_2_z,

           point_3_x,
           point_3_y,
           point_3_z;

    in >> normal_x
       >> normal_y
       >> normal_z

       >> point_1_x
       >> point_1_y
       >> point_1_z

       >> point_2_x
       >> point_2_y
       >> point_2_z

       >> point_3_x
       >> point_3_y
       >> point_3_z;

    triangle._normal.set_X(normal_x);
    triangle._normal.set_Y(normal_y);
    triangle._normal.set_Z(normal_z);

    triangle._point_1.set_X(point_1_x);
    triangle._point_1.set_Y(point_1_y);
    triangle._point_1.set_Z(point_1_z);

    triangle._point_2.set_X(point_2_x);
    triangle._point_2.set_Y(point_2_y);
    triangle._point_2.set_Z(point_2_z);

    triangle._point_3.set_X(point_3_x);
    triangle._point_3.set_Y(point_3_y);
    triangle._point_3.set_Z(point_3_z);

    return in;
}

QTextStream& operator<<(QTextStream out, const triangle& triangle)
{
    out << triangle.get_normal().get_X() << " "
        << triangle.get_normal().get_Y() << " "
        << triangle.get_normal().get_Z() << "/n"

        << triangle.get_point_1().get_X() << " "
        << triangle.get_point_1().get_Y() << " "
        << triangle.get_point_1().get_Z() << "/n"

        << triangle.get_point_2().get_X() << " "
        << triangle.get_point_2().get_Y() << " "
        << triangle.get_point_2().get_Z() << "/n"

        << triangle.get_point_3().get_X() << " "
        << triangle.get_point_3().get_Y() << " "
        << triangle.get_point_3().get_X() << "/n";

    return out;
}
