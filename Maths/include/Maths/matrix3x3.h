#pragma once
#include "matrix.h"
#include "vector.h"
#include <algorithm>

class Matrix3x3 : public Matrix
{
protected:
	double elems[3][3];

public:
	Matrix3x3(double a00, double a01, double a02,
		double a10, double a11, double a12,
		double a20, double a21, double a22);
	Matrix3x3();

	void transpose() override;
	void toArray(double* out) override;
	void toFloatArray(float* out) override;
	void override(Matrix3x3 source);

	friend Matrix3x3 operator*(Matrix3x3 lhs, const Matrix3x3& rhs);
	friend Matrix3x3 operator*(Matrix3x3 lhs, const double& rhs);
	friend Matrix3x3 operator*(double lhs, const Matrix3x3& rhs);
	friend Vector3 operator*(Matrix3x3 lhs, const Vector3& rhs);
};
