#ifndef XYZ_H
#define XYZ_H

#include "QTextStream"

class XYZ
{
public:
    XYZ(double X, double Y, double Z) : _X(X), _Y(Y), _Z(Z){}
    XYZ(const XYZ& xyz) : _X(xyz._X), _Y(xyz._Y), _Z(xyz._Z){}
    XYZ(const XYZ&& xyz) : _X(xyz._X), _Y(xyz._Y), _Z(xyz._Z){}

    XYZ& operator=(const XYZ& xyz);
    XYZ& operator=(const XYZ&& xyz);

    ~XYZ();

    void set_X(double& X);
    void set_Y(double& Y);
    void set_Z(double& Z);

    double get_X() const;
    double get_Y() const;
    double get_Z() const;

private:
    double _X;
    double _Y;
    double _Z;
};

#endif // XYZ_H
