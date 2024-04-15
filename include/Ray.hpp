#ifndef RAY_HPP
#define RAY_HPP

#include"Vector.hpp"

class Ray
{
    public:
        Ray(Vector o, Vector d, int reflections)
            :origin(o), reflectionsRemaining(reflections)
        {
           direction = d.normalize();  
        }
        Ray() :origin(Vector()), direction(Vector()), reflectionsRemaining(-1)
        {}

        // Vector getOrigin();
        // Vector getDirection();
        
        Vector origin;
        Vector direction;
        int reflectionsRemaining;
};

#endif