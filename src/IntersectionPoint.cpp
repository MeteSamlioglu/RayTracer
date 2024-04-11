#include"IntersectionPoint.hpp"
#include"Vector.hpp"
#include"Objects.hpp"

IntersectionPoint::IntersectionPoint()
    :point(Vector(0, 0 ,0)), isObjectIntsersected(false)
{
    intersectedObject = nullptr;
    normal = Vector();
    color = RGBColor();
}

IntersectionPoint::IntersectionPoint(Objects* object, Vector point, Vector normal_, RGBColor color_)
    : point(point), intersectedObject(object), normal(normal_), color(color_) {
    isObjectIntsersected = true;
}

void IntersectionPoint::updateIntersectionStatus(bool val, Vector point_)
{
    isObjectIntsersected = val;
    point = point_;
    intersectedObject  = nullptr;
}
bool IntersectionPoint::isIntersected() const
{
    return isObjectIntsersected;
}

Vector IntersectionPoint::getIntersectionPoint() const
{
    return point;
}

Objects* IntersectionPoint::getIntersectedObject() const
{
    return intersectedObject;
}

Vector IntersectionPoint::getNormalVector() const
{
    return normal;
}

RGBColor IntersectionPoint::getColor() const
{
    return color;
}
