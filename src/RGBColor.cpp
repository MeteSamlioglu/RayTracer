//RGB COLOR code
#include"RGBColor.hpp"

RGBColor::RGBColor()
    :r(0.0), g(0.0), b(0.0), filter(1.0)
{}

RGBColor::RGBColor(double r_, double g_, double b_)
    :r(r_), g(g_), b(b_), filter(1.0)
{}

RGBColor::RGBColor(double r_, double g_, double b_, double filter_)
    :r(r_), g(g_), b(b_), filter(filter_)
{}

double RGBColor::getR() const
{
    return r;
}
double RGBColor::getG() const
{
    return g;
}
//RGB
double RGBColor::getB() const
{
    return b;
}

RGBColor RGBColor::operator +(RGBColor const &p) const
{
    RGBColor sum;

    sum.r = p.r + r;
    sum.g = p.g + g;
    sum.b = p.b + b;

    return sum;
}

RGBColor RGBColor::operator* (double amount) const
{
    RGBColor outColor;
    
    outColor.r = r*amount;
    outColor.g = g*amount;
    outColor.b = b*amount;

    return outColor;
}