#ifndef OBJECTS_HPP
#define OBJECTS_HPP

#include"IntersectionPoint.hpp"
#include"Ray.hpp"


class Objects
{
    public:        
        virtual IntersectionPoint checkIntersection(Ray) = 0;

};

#endif