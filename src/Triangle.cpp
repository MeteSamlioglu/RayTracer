#include"Triangle.hpp"
#include<math.h>

Triangle::Triangle(Vector v0_, Vector v1_, Vector v2_)
    :v0(v0_), v1(v1_), v2(v2_)
{}

IntersectionPoint Triangle::checkIntersection(Ray ray) {
  Vector e1, e2, h, s, q, normal;
  float a, f, u, v, distance;

  e1 = Vector(v1.getX() - v0.getX(), v1.getY() - v0.getY(), v1.getZ() - v0.getZ());
  e2 = Vector(v2.getX() - v0.getX(), v2.getY() - v0.getY(), v2.getZ() - v0.getZ());

  normal = ((v1 - v0).crossProduct(v2 - v0)).normalize();

  h = ray.direction.crossProduct(e2);
  a = e1.dotProduct(h);

  if (a > -0.00001 && a < 0.00001)
    return IntersectionPoint();

  f = 1 / a;
  s = Vector(ray.origin.getX() - v0.getX(),ray.origin.getY() - v0.getY(), ray.origin.getZ() - v0.getZ());

  u = f * s.dotProduct(h);

  if (u < 0.0 || u > 1.0)
    return IntersectionPoint();

  q = s.crossProduct(e1);
  v = f * ray.direction.dotProduct(q);

  if (v < 0.0 || u + v > 1.0)
    return IntersectionPoint();

  distance = f * e2.dotProduct(q);

  // Ray Intersection
  if (distance > 0.00001) {
    Vector point = ray.origin + Vector(distance) * ray.direction;
    //return IntersectionPoint(ray, point, distance, normal, ray.material, material, this);
    return IntersectionPoint(this, point, normal, RGBColor(1.0, 0.0, 0.0),distance);
  }

  //Line Intersection, Not Ray
  else
     return IntersectionPoint();
}