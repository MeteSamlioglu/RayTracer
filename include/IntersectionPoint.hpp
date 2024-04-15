#ifndef INTERSECTIONPOINT_HPP
#define INTERSECTIONPOINT_HPP

#include<stdlib.h>
#include"Vector.hpp"
#include"RGBColor.hpp"
#include"Ray.hpp"
// #include"Objects.hpp"
class Objects;

class IntersectionPoint
{
    public:
        IntersectionPoint();
        IntersectionPoint(Objects* object, Vector point, Vector normal_, RGBColor color_, double distance_, Ray ray_); 
        void updateIntersectionStatus(bool val, Vector point_);
        bool isIntersected() const;
        double getDistance() const;
        void setDistance(double distance_);
        Vector getIntersectionPoint() const;
        Vector getNormalVector() const;
        Objects* getIntersectedObject() const;
        RGBColor getColor() const;
        Ray ray;

    private:
        bool isObjectIntsersected;
        Vector point;
        Vector normal;
        Objects* intersectedObject;
        RGBColor color;
        double distance;

};

#endif