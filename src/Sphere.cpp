/*Sphere.cpp*/
#include<iostream>
#include"Sphere.hpp"
#include"IntersectionPoint.hpp"
#include<math.h>
Sphere::Sphere(double radius_, Vector centerPoint_, RGBColor color_, double shininess_, double reflectivity_)
    : radius(radius_), centerPoint(centerPoint_), color(color_), shininess(shininess_), reflectivity(reflectivity_)
{}
RGBColor Sphere::getColor() const
{
    return color;
}
IntersectionPoint Sphere::checkIntersection(Ray ray) 
{
    IntersectionPoint Point = IntersectionPoint(); //default intersection point 
    double roots, root1, root2, distance = 0.0;
    /* To write the sphere equation in vector form (p - c).(p - c ) - R^2 */
    Vector distanceVector = ray.origin - centerPoint; //(p - c) or (o - c)
    
    double A = ray.direction.dotProduct(ray.direction); // d*d.t^2 coeff
    double B = distanceVector.dotProduct(ray.direction)*2;// 2*(o-c)*d
    double C = distanceVector.dotProduct(distanceVector) - (radius*radius); //(o-c)(o-c) - R^2


    double delta = B * B - 4 * A * C; //B2-4AC
    /* Check Intersection Roots*/
    if(delta < 0)
    {
        return Point; // No intersection
    }
    delta = sqrt(delta);
    //Find roots (-b +/- sqrt)(delta)/2*A
    if(B <  0)
        roots = (-B - delta) * 0.5; 
    else
        roots = (-B + delta) * 0.5;

    root1 = roots / A;
    root2 = C / roots;

    if(root1 > root2)
    {
        double temp = root1;
        root1 = root2;
        root2 = temp;
    }
    distance = root1;
    
    if(distance < 0)
        distance = root2;

    if(distance < 0 ||isnan(distance))
    {
        return Point; // No intersection
    }
    Vector intersection_point = ray.origin + (ray.direction * distance);
    Vector normal = (intersection_point - centerPoint).normalize();

    //Point =  IntersectionPoint(this, intersection_point, normal, RGBColor(fabs(normal.getX()), fabs(normal.getY()), fabs(normal.getZ())), distance); //o * dt
    Point =  IntersectionPoint(this, intersection_point, normal, getColor(), distance, ray); //o * dt
    return Point;
}
 
double Sphere::getShininess() const
{
    return shininess;
}

double Sphere::getReflectivity() const
{
    return reflectivity;
}