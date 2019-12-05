#include "uvcoordinate.h"
#include <cmath>

constexpr auto tolerance = 0.0000001;

UVCoordinate::UVCoordinate()
    : _U(0.),
      _V(0.),
      _W(0.)
{

}

UVCoordinate::UVCoordinate(const UVCoordinate& UV)
    : _U(UV._U),
      _V(UV._V),
      _W(UV._W)
{

}

UVCoordinate::UVCoordinate(const UVCoordinate&& UV)
    : _U(UV._U),
      _V(UV._V),
      _W(UV._W)
{

}

UVCoordinate& UVCoordinate::operator=(const UVCoordinate& UV)
{
    if(this == &UV)
        return *this;

    _U = UV._U;
    _V = UV._V;
    _W = UV._W;

    return *this;
}

UVCoordinate& UVCoordinate::operator=(const UVCoordinate&& UV)
{
    if(this == &UV)
        return *this;

    _U = UV._U;
    _V = UV._V;
    _W = UV._W;

    return *this;
}

UVCoordinate::~UVCoordinate(){ }

void UVCoordinate::setU(double& U)
{
    _U = U;
}

void UVCoordinate::setV(double& V)
{
    _V = V;
}

void UVCoordinate::setW(double& W)
{
    _W = W;
}

void UVCoordinate::setKoordinate(double& U, double& V, double& W)
{
    _U = U;
    _V = V;
    _W = W;
}

double UVCoordinate::getU() const
{
    return _U;
}

double UVCoordinate::getV() const
{
    return _V;
}

double UVCoordinate::getW() const
{
    return _W;
}

std::ifstream& operator>>(std::ifstream& in, UVCoordinate& UV)
{
    in >> UV._U
       >> UV._V
       >> UV._W;

    return in;
}

std::ofstream& operator<<(std::ofstream& out, const UVCoordinate& UV)
{
//    out << UV._U << " "
//        << UV._V << " "
//        << UV._W << " ";   // нуждаеться в доработке

    return out;
}

bool operator==(const UVCoordinate& UV_1, const UVCoordinate& UV_2)
{
    if(abs(UV_1._U - UV_2._U) < tolerance
            && abs(UV_1._V - UV_2._V) < tolerance
            && abs(UV_1._W - UV_2._W) < tolerance)
        return true;
    return false;
}

bool operator!=(const UVCoordinate& UV_1, const UVCoordinate& UV_2)
{
    return !(UV_1==UV_2);
}

