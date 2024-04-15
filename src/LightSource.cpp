// Scene Code
#include"LightSource.hpp"
#include<iostream>

LightSource::LightSource(Vector pos, double intensity_)
    :position(pos), intensity(intensity_)
{
    //std::cout<<"LightSource is initialized"<<std::endl;
}

Vector LightSource::getPosition() const
{
    return position;
}

double LightSource::getIntensity() const
{
    return intensity;
}