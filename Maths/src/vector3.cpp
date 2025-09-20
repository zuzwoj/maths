#include "Maths/vector.h"

/****************************************************
* CONSTRUCTORS
****************************************************/
constexpr Vector3::Vector3(double x, double y, double z) : x(x), y(y), z(z) {}
constexpr Vector3::Vector3(Vector2 v) : x(v.x), y(v.y), z(0.0f) {}
constexpr Vector3::Vector3(Vector4 v) : x(v.x), y(v.y), z(v.z) {}
constexpr Vector3::Vector3() : x(0.0f), y(0.0f), z(0.0f) {}

/****************************************************
* VECTOR INTERFACE FUNCTIONS
****************************************************/
double Vector3::len() const
{
	return sqrt(x * x + y * y + z * z);
}

void Vector3::normalize()
{
	double l = len();
	if (l != 0)
	{
		x /= l;
		y /= l;
		z /= l;
	}
}

void Vector3::override(Vector3 v)
{
	x = v.x;
	y = v.y;
	z = v.z;
}

Vector3 Vector3::crossProduct(Vector3 rhs)
{
	return Vector3(y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z, x * rhs.y - y * rhs.x);
}

/****************************************************
* NEGATION
****************************************************/
Vector3 Vector3::operator-()
{
	return Vector3(-x, -y, -z);
}

/****************************************************
* VECTOR ADDITION
****************************************************/
Vector3& Vector3::operator+=(const Vector3& rhs)
{
	this->x += rhs.x;
	this->y += rhs.y;
	this->z += rhs.z;
	return *this;
}

Vector3& Vector3::operator-=(const Vector3& rhs)
{
	this->x -= rhs.x;
	this->y -= rhs.y;
	this->z -= rhs.z;
	return *this;
}

Vector3 operator+(Vector3 lhs, const Vector3& rhs)
{
	lhs.x = rhs.x + lhs.x;
	lhs.y = rhs.y + lhs.y;
	lhs.z = rhs.z + lhs.z;
	return lhs;
}

Vector3 operator-(Vector3 lhs, const Vector3& rhs)
{
	lhs.x = rhs.x - lhs.x;
	lhs.y = rhs.y - lhs.y;
	lhs.z = rhs.z - lhs.z;
	return lhs;
}

/****************************************************
* MANIPULATION BY DOUBLE
****************************************************/
Vector3& Vector3::operator+=(const double& rhs)
{
	x += rhs;
	y += rhs;
	z += rhs;
	return *this;
}

Vector3 operator+(Vector3 lhs, const double& rhs)
{
	return Vector3(lhs.x + rhs, lhs.y + rhs, lhs.z + rhs);
}

Vector3 operator+(double lhs, const Vector3& rhs)
{
	return Vector3(lhs + rhs.x, lhs + rhs.y, lhs + rhs.z);
}

Vector3& Vector3::operator-=(const double& rhs)
{
	x -= rhs;
	y -= rhs;
	z -= rhs;
	return *this;
}

Vector3 operator-(Vector3 lhs, const double& rhs)
{
	return Vector3(lhs.x - rhs, lhs.y - rhs, lhs.z - rhs);
}

Vector3 operator-(double lhs, const Vector3& rhs)
{
	return Vector3(lhs - rhs.x, lhs - rhs.y, lhs - rhs.z);
}

Vector3& Vector3::operator*=(const double& rhs)
{
	x *= rhs;
	y *= rhs;
	z *= rhs;
	return *this;
}

Vector3 operator*(double lhs, const Vector3& rhs)
{
	return Vector3(rhs.x * lhs, rhs.y * lhs, rhs.z * lhs);
}

Vector3 operator*(Vector3 lhs, const double& rhs)
{
	return Vector3(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs);
}

Vector3& Vector3::operator/=(const double& rhs)
{
	x /= rhs;
	y /= rhs;
	z /= rhs;
	return *this;
}

Vector3 operator/(Vector3 lhs, const double& rhs)
{
	return Vector3(lhs.x / rhs, lhs.y / rhs, lhs.z / rhs);
}

/****************************************************
* DOT PRODUCT
****************************************************/
double operator*(Vector3 lhs, const Vector3& rhs)
{
	return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}
