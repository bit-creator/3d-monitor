#ifndef UVCOORDINATE_H
#define UVCOORDINATE_H


class UVCoordinate
{
public:
    UVCoordinate();
    UVCoordinate(const UVCoordinate& UV);
    UVCoordinate(const UVCoordinate&& UV);

    UVCoordinate& operator=(const UVCoordinate& UV);
    UVCoordinate& operator=(const UVCoordinate&& UV);

    ~UVCoordinate();

    void setU(double& U);
    void setV(double& V);
    void setW(double& W);

    void setKoordinate(double& U, double& V, double& z);

    double getX() const;
    double getY() const;
    double getZ() const;


private:
    double _U;
    double _V;
    double _W;
};

#endif // UVCOORDINATE_H
