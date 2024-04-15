//src vector
#include"Vector.hpp"
#include<iostream>
#include<math.h>

Vector::Vector()
    :x(0), y(0), z(0)
{}
Vector::Vector(double val)
    :x(0), y(0), z(0)
{}

Vector::Vector(double xVal, double yVal, double zVal)
    :x(xVal), y(yVal), z(zVal)
{}

Vector Vector::crossProduct(Vector const &v) const
{
    Vector crossProduct_ = Vector(y*v.z - v.y*z, v.x*z - x*v.z, x*v.y - v.x*y);
                                
    return crossProduct_;
}

double Vector::getVectorLength() const
{
    double length = sqrtf(x*x + y*y + z*z); // x^2 + y^2 + z^2

    return length;
}

double Vector::dotProduct(Vector const &v) const
{
    return x*v.x + y*v.y + z*v.z; //x^2 + y^2 + z^2
}

double Vector::getX() const
{
    return x;
}
double Vector::getY() const
{
    return y;
}
double Vector::getZ() const
{
    return z;
}

Vector Vector::operator +(Vector const &v) const
{
    return Vector(x+v.x, y+v.y, z+v.z);
}

Vector& Vector::operator +=(Vector const &v)
{
    x+= v.x;
    y+= v.y;
    z+= v.z;
    return *this;
}

Vector Vector::operator *(Vector const& v) const
{
    return Vector(x*v.x, y*v.y, z*v.z);
}

Vector& Vector::operator *=(Vector const &v)
{
    x*= v.x;
    y*= v.y;
    z*= v.z;

    return *this;
}

Vector Vector::operator -(Vector const &v) const
{
    return Vector(x - v.x, y - v.y, z - v.z);
}

Vector& Vector::operator -=(Vector const &v)
{
    x-=v.x;
    y-=v.y;
    z-=v.z;
    
    return *this;
}

Vector Vector::operator / (Vector const &v) const
{
    return Vector(x/v.x, y/v.y, z/v.z);   
}

Vector& Vector::operator /=(Vector const &v)
{
    x /= v.x;
    y /= v.y;
    z /= v.z;

    return *this;
}

Vector Vector::operator *(double const val) const
{    
    return Vector(x*val, y*val, z*val);
}

Vector& Vector::operator *=(double val)
{
    x*=val;
    y*=val;
    z*=val;
    
    return *this;
}

Vector Vector::operator /(double val) const
{
    Vector divisonRes = Vector(x/val, y/val, z/val);
    
    return divisonRes;
}

Vector& Vector::operator /=(double const val)
{
    x /= val;
    y /= val;
    z /= val;

    return *this;
}

Vector Vector::normalize()
{
    return (*this) /= this->getVectorLength();
}





