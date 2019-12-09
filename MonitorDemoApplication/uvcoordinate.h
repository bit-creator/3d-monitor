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

    void setU(float& U);
    void setV(float& V);
    void setW(float& W);

    void setKoordinate(float& U, float& V, float& W);

    float getU() const;
    float getV() const;
    float getW() const;

    friend std::ifstream& operator>>(std::ifstream& in, UVCoordinate& UV);
    friend std::ofstream& operator<<(std::ofstream& out, const UVCoordinate& UV);

    friend bool operator==(const UVCoordinate& UV_1, const UVCoordinate& UV_2);
    friend bool operator!=(const UVCoordinate& UV_1, const UVCoordinate& UV_2);

private:
    float _U;
    float _V;
    float _W;
};

#endif // UVCOORDINATE_H
