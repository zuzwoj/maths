#include "Maths/vector.h"

Vector2::Vector2(double x, double y)
{
	this->x = x;
	this->y = y;
}

Vector2::Vector2()
{
	this->x = 0;
	this->y = 0;
}

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

Vector2 Vector2::operator-()
{
	return Vector2(-x, -y);
}

Vector2& Vector2::operator+=(const Vector2& rhs)
{
	this->x += rhs.x;
	this->y += rhs.y;
	return *this;
}

Vector2& Vector2::operator-=(const Vector2& rhs)
{
	this->x -= rhs.x;
	this->y -= rhs.y;
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

Vector2 operator*(double lhs, const Vector2& rhs)
{
	return Vector2(rhs.x * lhs, rhs.y * lhs);
}

Vector2 operator*(Vector2 lhs, const double& rhs)
{
	return Vector2(lhs.x * rhs, lhs.y * rhs);
}

Vector2 operator/(Vector2 lhs, const double& rhs)
{
	return Vector2(lhs.x / rhs, lhs.y / rhs);
}

double operator*(Vector2 lhs, const Vector2& rhs)
{
	return lhs.x * rhs.x + lhs.y * rhs.y;
}
