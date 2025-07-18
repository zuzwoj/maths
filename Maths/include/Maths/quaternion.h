#pragma once
#include "vector.h"
#include "matrix4x4.h"

class Quaternion
{
private:
	double x, y, z, t;

	double len() const;
	void normalize();

public:
	Quaternion(Vector3 rotationAxis, float rotationAngle);
	Quaternion(Vector4 xyzt);

	Matrix4x4 getRotationMatrix();
	void reset();

	Quaternion& operator*=(const Quaternion& rhs);
	friend Quaternion operator*(Quaternion lhs, const Quaternion& rhs);
};
