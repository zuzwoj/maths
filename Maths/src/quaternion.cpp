#include "Maths/quaternion.h"

Quaternion::Quaternion(Vector3 rotationAxis, double rotationAngle)
{
	this->w = cos(rotationAngle / 2);
	this->x = rotationAxis.x * sin(rotationAngle / 2);
	this->y = rotationAxis.y * sin(rotationAngle / 2);
	this->z = rotationAxis.z * sin(rotationAngle / 2);
}

Quaternion::Quaternion(Vector4 wxyz) : Quaternion(wxyz.x, wxyz.y, wxyz.z, wxyz.t) {}

Quaternion::Quaternion(double w, double x, double y, double z)
{
	this->w = w;
	this->x = x;
	this->y = y;
	this->z = z;
}

double Quaternion::len() const
{
	return sqrt(w * w + x * x + y * y + z * z);
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
	w = q.w;
	x = q.x;
	y = q.y;
	z = q.z;
}

Matrix4x4 Quaternion::getRotationMatrix()
{
	return Matrix4x4(
		1.0 - 2.0 * (y * y + z * z), 2.0 * (x * y - z * w),       2.0 * (x * z + y * w),       0.0,
		2.0 * (x * y + z * w),       1.0 - 2.0 * (x * x + z * z), 2.0 * (y * z - x * w),       0.0,
		2.0 * (x * z - y * w),       2.0 * (y * z + x * w),       1.0 - 2.0 * (x * x + y * y), 0.0,
		0.0,                         0.0,                         0.0,                         1.0
	);
}

Matrix3x3 Quaternion::getRotationMatrix3x3()
{
	return Matrix3x3(
		1.0 - 2.0 * (y * y + z * z), 2.0 * (x * y - z * w),       2.0 * (x * z + y * w),
		2.0 * (x * y + z * w),       1.0 - 2.0 * (x * x + z * z), 2.0 * (y * z - x * w),
		2.0 * (x * z - y * w),       2.0 * (y * z + x * w),       1.0 - 2.0 * (x * x + y * y)
	);
}

void Quaternion::reset()
{
	w = 1.0;
	x = 0.0;
	y = 0.0;
	z = 0.0;
}

void Quaternion::invert()
{
	x = -x;
	y = -y;
	z = -z;
}

Quaternion Quaternion::multiplyWithoutNormalization(const Quaternion& lhs, const Quaternion& rhs)
{
	return Quaternion(Vector4(
		lhs.w * rhs.w - lhs.x * rhs.x - lhs.y * rhs.y - lhs.z * rhs.z,
		lhs.w * rhs.x + lhs.x * rhs.w + lhs.y * rhs.z - lhs.z * rhs.y,
		lhs.w * rhs.y - lhs.x * rhs.z + lhs.y * rhs.w + lhs.z * rhs.x,
		lhs.w * rhs.z + lhs.x * rhs.y - lhs.y * rhs.x + lhs.z * rhs.w
	));
}

Quaternion& Quaternion::operator*=(const Quaternion& rhs)
{
	*this = *this * rhs;
	return *this;
}

Quaternion operator*(Quaternion lhs, const Quaternion& rhs)
{
	Quaternion result = Quaternion::multiplyWithoutNormalization(lhs, rhs);
	result.normalize();
	return result;
}

Vector3 operator*(Quaternion lhs, const Vector3& rhs)
{
	lhs.normalize();
	Quaternion vector = Quaternion(0.0, rhs.x, rhs.y, rhs.z);
	vector = Quaternion::multiplyWithoutNormalization(lhs, vector);
	lhs.invert();
	vector = Quaternion::multiplyWithoutNormalization(vector, lhs);
	return Vector3(vector.x, vector.y, vector.z);
}
