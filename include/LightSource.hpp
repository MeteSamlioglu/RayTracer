#ifndef LIGHTSOURCE_HPP
#define LIGHTSOURCE_HPP
#include"Vector.hpp"

class LightSource
{
    public:
        LightSource(Vector pos, double intensity_);
        Vector getPosition() const;
        double getIntensity() const;
    private:   
        Vector position; 
        double intensity;
};

#endif