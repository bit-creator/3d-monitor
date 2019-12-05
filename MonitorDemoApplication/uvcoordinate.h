#ifndef UVCOORDINATE_H
#define UVCOORDINATE_H

#include <fstream>

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

    void setKoordinate(double& U, double& V, double& W);

    double getU() const;
    double getV() const;
    double getW() const;

    friend std::ifstream& operator>>(std::ifstream& in, UVCoordinate& UV);
    friend std::ofstream& operator<<(std::ofstream& out, const UVCoordinate& UV);

    friend bool operator==(const UVCoordinate& UV_1, const UVCoordinate& UV_2);
    friend bool operator!=(const UVCoordinate& UV_1, const UVCoordinate& UV_2);

private:
    double _U;
    double _V;
    double _W;
};

#endif // UVCOORDINATE_H
