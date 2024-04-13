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

        Vector origin;
        Vector direction;
};

#endif