#include "normal.h"

normal::~normal()
{

}

normal& normal::operator=(const normal& Normal)
{
    if(this == &Normal)
        return *this;

    _normal = Normal._normal;

    return *this;
}

normal& normal::operator=(const normal&& Normal)
{
    if(this == &Normal)
        return *this;

    _normal = Normal._normal;

    return *this;
}

void normal::set_normal(XYZ &Normal)
{
    _normal = Normal;
}

XYZ normal::get_normal() const
{
    return _normal;
}

void normal::set_normal_as_file(istream in, normal& Normal)
{
    in >> Normal;
}

normal& normal::get_normal_as_file(ostream out, normal& Normal)
{
    out << Normal;
    return Normal;
}
