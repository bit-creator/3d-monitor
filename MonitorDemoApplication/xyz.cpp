#include "xyz.h"

XYZ::~XYZ()
{

}

XYZ& XYZ::operator=(const XYZ& _XYZ)
{
    if(this == &_XYZ)
        return *this;

    _X = _XYZ._X;
    _Y = _XYZ._Y;
    _Z = _XYZ._Z;

    return *this;
}

XYZ& XYZ::operator=(const XYZ&& _XYZ)
{
    if(this == &_XYZ)
        return *this;

    _X = _XYZ._X;
    _Y = _XYZ._Y;
    _Z = _XYZ._Z;

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
