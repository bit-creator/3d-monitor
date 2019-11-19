#include "xyz.h"

XYZ::~XYZ()
{

}

XYZ& XYZ::operator=(const XYZ& xyz)
{
    if(this == &xyz)
        return *this;

    _X = xyz._X;
    _Y = xyz._Y;
    _Z = xyz._Z;

    return *this;
}

XYZ& XYZ::operator=(const XYZ&& xyz)
{
    if(this == &xyz)
        return *this;

    _X = xyz._X;
    _Y = xyz._Y;
    _Z = xyz._Z;

    return *this;
}

void XYZ::set_X(double& X)
{
    _X = X;
}

void XYZ::set_Y(double& Y)
{
    _Y = Y;
}

void XYZ::set_Z(double& Z)
{
    _Z = Z;
}

double XYZ::get_X() const
{
    return _X;
}

double XYZ::get_Y() const
{
    return _Y;
}

double XYZ::get_Z() const
{
    return _Z;
}
