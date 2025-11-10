#pragma once
#include "vector.h"
#include "matrix4x4.h"

class Quaternion
{
private:
	double w, x, y, z;

	double len() const;
	void normalize();
	void override(Quaternion q);

public:
	Quaternion(Vector3 rotationAxis, double rotationAngle = 0);
	Quaternion(Vector4 xyzw);
	Quaternion(double x, double y, double z, double w);
	Quaternion() : x(0.0), y(0.0), z(0.0), w(0.0) {}

	double getW() { return w; }
	double getX() { return x; }
	double getY() { return y; }
	double getZ() { return z; }

	Matrix4x4 getRotationMatrix();
	void reset();

	Quaternion& operator*=(const Quaternion& rhs);
	friend Quaternion operator*(Quaternion lhs, const Quaternion& rhs);
};
