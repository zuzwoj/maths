#pragma once
#include "vector.h"
#include "matrix4x4.h"
#include "matrix3x3.h"

class Quaternion
{
private:
	double w, x, y, z;

	double len() const;
	void override(Quaternion q);

public:
	Quaternion(Vector3 rotationAxis, double rotationAngle = 0);
	Quaternion(Vector4 wxyz);
	Quaternion(double w, double x, double y, double z);
	Quaternion() : w(0.0), x(0.0), y(0.0), z(0.0) {}

	double getW() { return w; }
	double getX() { return x; }
	double getY() { return y; }
	double getZ() { return z; }

	Matrix4x4 getRotationMatrix();
	Matrix3x3 getRotationMatrix3x3();
	Vector4 toVector() { return Vector4(w, x, y, z); }
	void reset();
	void normalize();

	Quaternion& operator*=(const Quaternion& rhs);
	friend Quaternion operator*(Quaternion lhs, const Quaternion& rhs);
};
