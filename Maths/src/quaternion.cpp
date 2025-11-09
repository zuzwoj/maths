#include "Maths/quaternion.h"

Quaternion::Quaternion(Vector3 rotationAxis, double rotationAngle)
{
	this->w = cos(rotationAngle / 2);
	this->x = rotationAxis.x * sin(rotationAngle / 2);
	this->y = rotationAxis.y * sin(rotationAngle / 2);
	this->z = rotationAxis.z * sin(rotationAngle / 2);
}

Quaternion::Quaternion(Vector4 xyzw) : Quaternion(xyzw.x, xyzw.y, xyzw.z, xyzw.t) {}

Quaternion::Quaternion(double x, double y, double z, double w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

double Quaternion::len() const
{
	return sqrt(x * x + y * y + z * z + w * w);
}

void Quaternion::normalize()
{
	double l = len();
	if (l != 0)
	{
		w /= l;
		x /= l;
		y /= l;
		z /= l;
	}
}
void Quaternion::override(Quaternion q)
{
	x = q.x;
	y = q.y;
	z = q.z;
	w = q.w;
}

Matrix4x4 Quaternion::getRotationMatrix()
{
	return Matrix4x4(
		1.0f - 2.0f * (y * y + z * z), 2.0f * (x * y - z * w), 2.0f * (x * z + y * w), 0.0f,
		2.0f * (x * y + z * w), 1.0f - 2.0f * (x * x + z * z), 2.0f * (y * z - x * w), 0.0f,
		2.0f * (x * z - y * w), 2.0f * (y * z + x * w), 1.0f - 2.0f * (x * x + y * y), 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
}

void Quaternion::reset()
{
	this->w = 1.0;
	this->x = 0.0;
	this->y = 0.0;
	this->z = 0.0;
}

Quaternion& Quaternion::operator*=(const Quaternion& rhs)
{
	*this = *this * rhs;
	return *this;
}

Quaternion operator*(Quaternion lhs, const Quaternion& rhs)
{
	Quaternion result = Quaternion(Vector4(
		lhs.w * rhs.x + lhs.x * rhs.w + lhs.y * rhs.z - lhs.z * rhs.y,
		lhs.w * rhs.y - lhs.x * rhs.z + lhs.y * rhs.w + lhs.z * rhs.x,
		lhs.w * rhs.z + lhs.x * rhs.y - lhs.y * rhs.x + lhs.z * rhs.w,
		lhs.w * rhs.w - lhs.x * rhs.x - lhs.y * rhs.y - lhs.z * rhs.z
	));
	result.normalize();
	return result;
}
