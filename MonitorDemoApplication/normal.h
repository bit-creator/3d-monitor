#ifndef NORMAL_H
#define NORMAL_H

#include "xyz.h"

class normal
{
public:
    normal(XYZ Normal) : _normal(Normal){}
    normal(normal& Normal) : _normal(Normal._normal){}
    normal(normal&& Normal) : _normal(Normal._normal){}

    normal& operator=(const normal& Normal);
    normal& operator=(const normal&& Normal);

    ~normal();

    void set_normal(XYZ& Normal);

    XYZ get_normal() const;

    void set_normal_as_file(istream in, normal& Normal);     //как альтернатива можно перегружать
    normal& get_normal_as_file(ostream out, normal& Normal); //операцию взятия/помещения в поток

    friend ostream& operator<<(ostream& out, const normal& Normal);
    friend istream& operator>>(istream& in, normal& Normal);

private:
    XYZ _normal;
};

ostream& operator<<(ostream& out, const normal& Normal)
{
    out << Normal;

    return out;
}

istream& operator>>(istream& in, normal& Normal)
{
    in >> Normal;

    return in;
}


#endif // NORMAL_H
