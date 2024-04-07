#ifndef VECTOR_HPP
#define VECTOR_HPP

class Vector
{
    Vector();
    Vector(const Vector& v); //Copy constructor
    Vector(float x, float y, float z);
    
    virtual ~Vector();

    float normalize();
    Vector normalized(); 
    
    Vector& operator =(const Vector& v);
	Vector& operator +=(const Vector& v);
	Vector& operator -=(const Vector& v);
	Vector& operator *=(float f);
	Vector& operator /=(float f);
	Vector operator -() const;
    
    private:
        float x, y, z;
};

#endif