#include "Maths/vector.h"

/****************************************************
* CONSTRUCTORS
****************************************************/
Vector2::Vector2(double x, double y)
{
	this->x = x;
	this->y = y;
}

Vector2::Vector2(Vector3 v)
{
	this->x = v.x;
	this->y = v.y;
}

Vector2::Vector2()
{
	this->x = 0.0f;
	this->y = 0.0f;
}

/****************************************************
* VECTOR INTERFACE FUNCTIONS
****************************************************/
double Vector2::len() const
{
	return sqrt(x * x + y * y);
}

void Vector2::normalize()
{
	double l = len();
	if (l != 0)
	{
		x /= l;
		y /= l;
	}
}

/****************************************************
* NEGATION
****************************************************/
Vector2 Vector2::operator-()
{
	return Vector2(-x, -y);
}

/****************************************************
* VECTOR ADDITION
****************************************************/
Vector2& Vector2::operator+=(const Vector2& rhs)
{
	x += rhs.x;
	y += rhs.y;
	return *this;
}

Vector2& Vector2::operator-=(const Vector2& rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	return *this;
}

Vector2 operator+(Vector2 lhs, const Vector2& rhs)
{
	lhs.x = rhs.x + lhs.x;
	lhs.y = rhs.y + lhs.y;
	return lhs;
}

Vector2 operator-(Vector2 lhs, const Vector2& rhs)
{
	lhs.x = rhs.x - lhs.x;
	lhs.y = rhs.y - lhs.y;
	return lhs;
}

/****************************************************
* MANIPULATION BY DOUBLE
****************************************************/
Vector2& Vector2::operator+=(const double& rhs)
{
	x += rhs;
	y += rhs;
	return *this;
}

Vector2 operator+(Vector2 lhs, const double& rhs)
{
	lhs.x += rhs;
	lhs.y += rhs;
	return lhs;
}

Vector2 operator+(double lhs, const Vector2& rhs)
{
	return Vector2(lhs + rhs.x, lhs + rhs.y);
}

Vector2& Vector2::operator-=(const double& rhs)
{
	x -= rhs;
	y -= rhs;
	return *this;
}

Vector2 operator-(Vector2 lhs, const double& rhs)
{
	lhs.x -= rhs;
	lhs.y -= rhs;
	return lhs;
}

Vector2 operator-(double lhs, const Vector2& rhs)
{
	return Vector2(lhs - rhs.x, lhs - rhs.y);
}

Vector2& Vector2::operator*=(const double& rhs)
{
	x *= rhs;
	y *= rhs;
	return *this;
}

Vector2 operator*(double lhs, const Vector2& rhs)
{
	return Vector2(rhs.x * lhs, rhs.y * lhs);
}

Vector2 operator*(Vector2 lhs, const double& rhs)
{
	return Vector2(lhs.x * rhs, lhs.y * rhs);
}

Vector2& Vector2::operator/=(const double& rhs)
{
	x /= rhs;
	y /= rhs;
	return *this;
}

Vector2 operator/(Vector2 lhs, const double& rhs)
{
	return Vector2(lhs.x / rhs, lhs.y / rhs);
}

/****************************************************
* DOT PRODUCT
****************************************************/
double operator*(Vector2 lhs, const Vector2& rhs)
{
	return lhs.x * rhs.x + lhs.y * rhs.y;
}
