#ifndef RAY_HPP
#define RAY_HPP

#include"Vector.hpp"

class Ray
{
    public:
        Ray(Vector o, Vector d)
            :origin(o)
        {
           direction = d.normalize();  
        }
        Ray() :origin(Vector()), direction(Vector())
        {}

        // Vector getOrigin();
        // Vector getDirection();
        
        Vector origin;
        Vector direction;
};

#endif