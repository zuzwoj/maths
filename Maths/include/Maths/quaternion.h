#pragma once
#include "vector.h"
#include "matrix4x4.h"

class Quaternion
{
private:
	double w, x, y, z;

	double len() const;
	void normalize();

public:
	Quaternion(Vector3 rotationAxis, float rotationAngle);
	Quaternion(Vector4 wxyz);

	double getW() { return w; }
	double getX() { return x; }
	double getY() { return y; }
	double getZ() { return z; }

	Matrix4x4 getRotationMatrix();
	void reset();


	Quaternion& operator*=(const Quaternion& rhs);
	friend Quaternion operator*(Quaternion lhs, const Quaternion& rhs);
};
