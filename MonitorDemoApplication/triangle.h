#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "xyz.h"

class triangle
{
public:
    triangle();
    triangle(XYZ& normal, XYZ& point_1, XYZ& point_2, XYZ& point_3)
        : _normal(normal),
          _point_1(point_1),
          _point_2(point_2),
          _point_3(point_3){ }
    triangle(triangle& triangle)
        : _normal(triangle._normal),
          _point_1(triangle._point_1),
          _point_2(triangle._point_2),
          _point_3(triangle._point_3){ }
    triangle(triangle&& triangle)
        : _normal(triangle._normal),
          _point_1(triangle._point_1),
          _point_2(triangle._point_2),
          _point_3(triangle._point_3){ }

    triangle& operator=(const triangle& triangle);
    triangle& operator=(const triangle&& triangle);

    ~triangle();

    XYZ get_normal() const;
    XYZ get_point_1() const;
    XYZ get_point_2() const;
    XYZ get_point_3() const;

    friend QTextStream& operator>>(QTextStream in, triangle& triangle);
    friend QTextStream& operator<<(QTextStream out, const triangle& triangle);

private:
    XYZ _normal;
    XYZ _point_1;
    XYZ _point_2;
    XYZ _point_3;
};

#endif // TRIANGLE_H
