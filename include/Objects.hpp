#ifndef OBJECTS_HPP
#define OBJECTS_HPP

#include"IntersectionPoint.hpp"
#include"Ray.hpp"

#define NOT_SHINY -1
#define NOT_REFLECTIVE -1

class Objects
{
    public:        
        virtual IntersectionPoint checkIntersection(Ray) = 0;
        virtual double getShininess() const;
        virtual double getReflectivity() const;
};

#endif