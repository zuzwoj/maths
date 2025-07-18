#include "Maths/quaternion.h"

double Quaternion::len() const
{
	return sqrt(x * x + y * y + z * z + t * t);
}

void Quaternion::normalize()
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

Quaternion::Quaternion(Vector3 rotationAxis, float rotationAngle)
{
	this->x = rotationAxis.x * sin(rotationAngle / 2);
	this->y = rotationAxis.y * sin(rotationAngle / 2);
	this->z = rotationAxis.z * sin(rotationAngle / 2);
	this->t = cos(rotationAngle / 2);
}

Quaternion::Quaternion(Vector4 xyzt)
{
	this->x = xyzt.x;
	this->y = xyzt.y;
	this->z = xyzt.z;
	this->t = xyzt.t;
}

Matrix4x4 Quaternion::getRotationMatrix()
{
	return Matrix4x4(
		1.0f - 2.0f * (y * y + z * z), 2.0f * (x * y - z * t), 2.0f * (x * z + y * t), 0.0f,
		2.0f * (x * y + z * t), 1.0f - 2.0f * (x * x + z * z), 2.0f * (y * z - x * t), 0.0f,
		2.0f * (x * z - y * t), 2.0f * (y * z + x * t), 1.0f - 2.0f * (x * x + y * y), 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
}

void Quaternion::reset()
{
	this->x = 0.0f;
	this->y = 0.0f;
	this->z = 0.0f;
	this->t = 1.0f;
}

Quaternion& Quaternion::operator*=(const Quaternion& rhs)
{
	*this = *this * rhs;
	return *this;
}

Quaternion operator*(Quaternion lhs, const Quaternion& rhs)
{
	Quaternion result = Quaternion(Vector4(
		lhs.t * rhs.x + lhs.x * rhs.t + lhs.y * rhs.z - lhs.z * rhs.y,
		lhs.t * rhs.y - lhs.x * rhs.z + lhs.y * rhs.t + lhs.z * rhs.x,
		lhs.t * rhs.z + lhs.x * rhs.y - lhs.y * rhs.x + lhs.z * rhs.t,
		lhs.t * rhs.t - lhs.x * rhs.x - lhs.y * rhs.y - lhs.z * rhs.z
	));
	result.normalize();
	return result;
}
