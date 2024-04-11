#ifndef SPHERE_HPP
#define SPHERE_HPP

#include"Vector.hpp"
#include"IntersectionPoint.hpp"
#include"Ray.hpp"
#include<math.h>

class Sphere
{
    public:
    
        Sphere(double radius, Vector centerPoint_);
        IntersectionPoint checkIntersection(Ray ray) const;
    
    private:
        Vector centerPoint;
        double radius;
};

#endif