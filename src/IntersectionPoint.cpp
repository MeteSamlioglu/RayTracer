#include"IntersectionPoint.hpp"
#include"Vector.hpp"

IntersectionPoint::IntersectionPoint()
    :point(Vector(0, 0 ,0)), isObjectIntsersected(false)
{

}

IntersectionPoint::IntersectionPoint(Vector point_)
    :point(point_)
{
    isObjectIntsersected = true;

}

void IntersectionPoint::updateIntersectionStatus(bool val, Vector point_)
{
    isObjectIntsersected = val;
    point = point_;
}
bool IntersectionPoint::isIntersected() const
{
    return isObjectIntsersected;
}

Vector IntersectionPoint::getIntersectionPoint() const
{
    return point;
}
