#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include"Objects.hpp"
#include"RGBColor.hpp"

class Triangle : public Objects
{
    public:
        Triangle(Vector v0_, Vector v1_, Vector v2_);

        virtual IntersectionPoint checkIntersection(Ray ray);

    private:
        Vector v0, v1 ,v2;
        RGBColor color;
};

#endif