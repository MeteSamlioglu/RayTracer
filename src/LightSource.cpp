// Scene Code
#include"LightSource.hpp"
#include<iostream>

LightSource::LightSource(Vector pos)
    :position(pos)
{
    //std::cout<<"LightSource is initialized"<<std::endl;
}

Vector LightSource::getPosition() const
{
    return position;
}
