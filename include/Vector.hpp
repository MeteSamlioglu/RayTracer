#ifndef VECTOR_HPP
#define VECTOR_HPP

class Vector
{
    Vector();
    Vector(double val);
    Vector(double x, double y, double z);
    
    Vector crossProduct(const Vector& v) const;
    double Vector::getVectorLength() const;
    float Vector::dotProduct(Vector const& v) const;
    
    Vector operator + (Vector const & v) const;
    Vector& operator +=(Vector const &v);
    Vector operator *(Vector const& v) const;
    Vector& operator *=(Vector const &v);
    Vector operator -(Vector const &v) const;
    Vector& operator -=(Vector const &v);
    Vector operator / (Vector const &v) const;
    Vector& operator /= (Vector const &v);

    Vector operator /(double s) const;
    Vector& operator /= (double val);
    Vector operator *(double s) const;
    Vector& operator *=(double s);
    

    private:
        double x, y, z;
};

#endif