#ifndef RGBCOLOR_HPP
#define RGBCOLOR_HPP


class RGBColor
{
    public:
        RGBColor();
        RGBColor(double r_, double g_, double b_);
        RGBColor(double r_, double g_, double b_, double filter_);
        double getR() const;
        double getG() const;
        double getB() const;
    private:
        double r;
        double g;
        double b;
        double filter;
};

#endif