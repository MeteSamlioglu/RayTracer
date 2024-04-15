#ifndef RGBCOLOR_HPP
#define RGBCOLOR_HPP


#define NTZ(X) (isnan((X)) ? 0.0 : (X))
#include <math.h>


class RGBColor
{
    public:
        RGBColor();
        RGBColor(double r_, double g_, double b_);
        RGBColor(double r_, double g_, double b_, double filter_);
        double getR() const;
        double getG() const;
        double getB() const;

        void setR(double r_);
        void setG(double g_);
        void setB(double b_);

        RGBColor operator + (RGBColor const& p) const;
        RGBColor operator * (double amount) const;

    private:
        double r;
        double g;
        double b;
        double filter;
};

#endif