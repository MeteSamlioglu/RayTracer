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
           origin+=(direction /1000); /* To prevent intersecting with itself we forward it a little bit forward*/
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