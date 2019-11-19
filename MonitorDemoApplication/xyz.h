#ifndef XYZ_H
#define XYZ_H

#include <iostream>

using std::ostream;
using std::istream;

class XYZ
{
public:
    XYZ(double X, double Y, double Z) : _X(X), _Y(Y), _Z(Z){}
    XYZ(const XYZ& xyz) : _X(xyz._X), _Y(xyz._Y), _Z(xyz._Z){}
    XYZ(const XYZ&& xyz) : _X(xyz._X), _Y(xyz._Y), _Z(xyz._Z){}

    XYZ& operator=(const XYZ& _XYZ);
    XYZ& operator=(const XYZ&& _XYZ);

    ~XYZ();

    void set_X(double& X);
    void set_Y(double& Y);
    void set_Z(double& Z);

    double get_X() const;
    double get_Y() const;
    double get_Z() const;

    friend ostream& operator<<(ostream& out, const XYZ& xyz);
    friend istream& operator>>(istream& in, XYZ& xyz);

private:
    double _X;
    double _Y;
    double _Z;
};

ostream& operator<<(ostream& out, const XYZ& xyz)
{
    out << xyz.get_X() << " "
        << xyz.get_Y() << " "
        << xyz.get_Z() << '\n';

    return out;
}

istream& operator>>(istream& in, XYZ& xyz)
{
    in >> xyz._X >> xyz._Y >> xyz._Z;

    return in;
}


#endif // XYZ_H
