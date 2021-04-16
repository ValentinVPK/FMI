#pragma once
// Add all other required methods and fields of the class.

class Vector4D 
{
private:
    double a;
    double b;
    double c;
    double d;
public:
    Vector4D(double a, double b, double c, double d);
    double& operator[](int index);
    friend Vector4D operator+(const Vector4D& v1, const Vector4D& v2);
    Vector4D& operator+=(const Vector4D& rhs); 
    friend Vector4D operator-(const Vector4D& v1, const Vector4D& v2);
    Vector4D& operator-=(const Vector4D& rhs);
    friend Vector4D operator*(const Vector4D& v1, const Vector4D& v2);
    Vector4D& operator*=(const Vector4D& rhs);  
    friend Vector4D operator*(const Vector4D& v1, double number);
    Vector4D& operator*=(double number);
    friend Vector4D operator/(const Vector4D& v1, const Vector4D& v2);
    Vector4D& operator/=(const Vector4D& rhs);

    friend bool operator==(const Vector4D& lhs, const Vector4D& rhs);
    friend bool operator!=(const Vector4D& lhs, const Vector4D& rhs);
    friend bool operator<(const Vector4D& lhs, const Vector4D& rhs);
    friend bool operator>(const Vector4D& lhs, const Vector4D& rhs);
    friend bool operator<=(const Vector4D& lhs, const Vector4D& rhs);
    friend bool operator>=(const Vector4D& lhs, const Vector4D& rhs);

    bool operator!() const;
    Vector4D operator-() const;
};