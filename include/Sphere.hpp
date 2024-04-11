#ifndef SPHERE_HPP
#define SPHERE_HPP

#include"Vector.hpp"
#include"Objects.hpp"
#include"RGBColor.hpp"
#include"IntersectionPoint.hpp"
#include"Ray.hpp"
#include<math.h>

class Sphere : public Objects
{
    public:
    
        Sphere(double radius, Vector centerPoint_, RGBColor color_);
        virtual IntersectionPoint checkIntersection(Ray ray);
        RGBColor getColor() const;   
    private:
        Vector centerPoint;
        double radius;
        RGBColor color;
};

#endif