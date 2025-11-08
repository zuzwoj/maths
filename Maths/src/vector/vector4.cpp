#include "Maths/vector.h"

/****************************************************
* VECTOR INTERFACE FUNCTIONS
****************************************************/
double Vector4::len() const
{
	return sqrt(x * x + y * y + z * z + t * t);
}

void Vector4::normalize()
{
	double l = len();
	if (l != 0)
	{
		x /= l;
		y /= l;
		z /= l;
		t /= l;
	}
}

void Vector4::override(Vector4 v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	t = v.t;
}

/****************************************************
* NEGATION
****************************************************/
Vector4 Vector4::operator-()
{
	return Vector4(-x, -y, -z, -t);
}

/****************************************************
* VECTOR ADDITION
****************************************************/
Vector4& Vector4::operator+=(const Vector4& rhs)
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	t += rhs.t;
	return *this;
}

Vector4& Vector4::operator-=(const Vector4& rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
	t += rhs.t;
	return *this;
}

Vector4 operator+(Vector4 lhs, const Vector4& rhs)
{
	lhs.x += rhs.x;
	lhs.y += rhs.y;
	lhs.z += rhs.z;
	lhs.t += rhs.t;
	return lhs;
}

Vector4 operator-(Vector4 lhs, const Vector4& rhs)
{
	lhs.x -= rhs.x;
	lhs.y -= rhs.y;
	lhs.z -= rhs.z;
	lhs.t -= rhs.t;
	return lhs;
}

/****************************************************
* MANIPULATION BY DOUBLE
****************************************************/
Vector4& Vector4::operator+=(const double& rhs)
{
	x += rhs;
	y += rhs;
	z += rhs;
	t += rhs;
	return *this;
}

Vector4 operator+(Vector4 lhs, const double& rhs)
{
	return Vector4(lhs.x + rhs, lhs.y + rhs, lhs.z + rhs, lhs.t + rhs);
}

Vector4 operator+(double lhs, const Vector4& rhs)
{
	return Vector4(lhs + rhs.x, lhs + rhs.y, lhs + rhs.z, lhs + rhs.t);
}

Vector4& Vector4::operator-=(const double& rhs)
{
	x -= rhs;
	y -= rhs;
	z -= rhs;
	t -= rhs;
	return *this;
}

Vector4 operator-(Vector4 lhs, const double& rhs)
{
	return Vector4(lhs.x - rhs, lhs.y - rhs, lhs.z - rhs, lhs.t - rhs);
}

Vector4 operator-(double lhs, const Vector4& rhs)
{
	return Vector4(lhs - rhs.x, lhs - rhs.y, lhs - rhs.z, lhs - rhs.t);
}

Vector4& Vector4::operator*=(const double& rhs)
{
	x *= rhs;
	y *= rhs;
	z *= rhs;
	t *= rhs;
	return *this;
}

Vector4 operator*(double lhs, const Vector4& rhs)
{
	return Vector4(rhs.x * lhs, rhs.y * lhs, rhs.z * lhs, rhs.t * lhs);
}

Vector4 operator*(Vector4 lhs, const double& rhs)
{
	return Vector4(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs, lhs.t * rhs);
}

Vector4& Vector4::operator/=(const double& rhs)
{
	x /= rhs;
	y /= rhs;
	z /= rhs;
	t /= rhs;
	return *this;
}

Vector4 operator/(Vector4 lhs, const double& rhs)
{
	return Vector4(lhs.x / rhs, lhs.y / rhs, lhs.z / rhs, lhs.t / rhs);
}

/****************************************************
* DOT PRODUCT
****************************************************/
double operator*(Vector4 lhs, const Vector4& rhs)
{
	return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.t * rhs.t;
}
