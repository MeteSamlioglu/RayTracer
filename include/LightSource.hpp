#ifndef LIGHTSOURCE_HPP
#define LIGHTSOURCE_HPP
#include"Vector.hpp"

class LightSource
{
    public:
        LightSource(Vector pos);
        Vector getPosition() const;
    private:   
        Vector position; 
};

#endif