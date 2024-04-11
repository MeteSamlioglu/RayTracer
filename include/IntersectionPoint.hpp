#ifndef INTERSECTIONPOINT_HPP
#define INTERSECTIONPOINT_HPP

#include"Vector.hpp"

class IntersectionPoint
{
    public:
        IntersectionPoint();
        IntersectionPoint(Vector point);
        
        void updateIntersectionStatus(bool val, Vector point_);
        bool isIntersected() const;
        Vector getIntersectionPoint() const;

    private:
        bool isObjectIntsersected;
        Vector point;

};

#endif