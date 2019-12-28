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

    void setU(const float& U);
    void setV(const float& V);
    void setW(const float& W);

    void setKoordinate(const float& U, const float& V, const float& W);

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
