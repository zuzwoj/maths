#include "Maths/matrix3x3.h"

Matrix3x3::Matrix3x3(double a00, double a01, double a02,
	double a10, double a11, double a12,
	double a20, double a21, double a22)
{
	elems[0][0] = a00;
	elems[1][0] = a10;
	elems[2][0] = a20;

	elems[0][1] = a01;
	elems[1][1] = a11;
	elems[2][1] = a21;

	elems[0][2] = a02;
	elems[1][2] = a12;
	elems[2][2] = a22;
}

Matrix3x3::Matrix3x3() : Matrix3x3(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0) {}

void Matrix3x3::transpose()
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			std::swap(elems[i][j], elems[j][i]);
		}
	}
}

Matrix3x3 Matrix3x3::getTransposed()
{
	return Matrix3x3(
		elems[0][0], elems[1][0], elems[2][0],
		elems[0][1], elems[1][1], elems[2][1],
		elems[0][2], elems[1][2], elems[2][2]
	);
}

void Matrix3x3::toArray(double* out)
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			out[i * 3 + j] = elems[i][j];
		}
	}
}

void Matrix3x3::toFloatArray(float* out)
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			out[i * 3 + j] = (float)elems[i][j];
		}
	}
}

void Matrix3x3::override(Matrix3x3 source)
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			elems[i][j] = source.elems[i][j];
		}
	}
}

Matrix3x3 operator*(Matrix3x3 lhs, const Matrix3x3& rhs)
{
	Matrix3x3 result = Matrix3x3();
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			result.elems[i][j] =
				lhs.elems[i][0] * rhs.elems[0][j] +
				lhs.elems[i][1] * rhs.elems[1][j] +
				lhs.elems[i][2] * rhs.elems[2][j];
		}
	}
	return result;
}

Matrix3x3 operator*(Matrix3x3 lhs, const double& rhs)
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			lhs.elems[i][j] *= rhs;
		}
	}
	return lhs;
}

Matrix3x3 operator*(double lhs, const Matrix3x3& rhs)
{
	Matrix3x3 result;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			result.elems[i][j] = rhs.elems[i][j] * lhs;
		}
	}
	return result;
}

Vector3 operator*(Matrix3x3 lhs, const Vector3& rhs)
{
	return Vector3(
		lhs.elems[0][0] * rhs.x + lhs.elems[0][1] * rhs.y + lhs.elems[0][2] * rhs.z,
		lhs.elems[1][0] * rhs.x + lhs.elems[1][1] * rhs.y + lhs.elems[1][2] * rhs.z,
		lhs.elems[2][0] * rhs.x + lhs.elems[2][1] * rhs.y + lhs.elems[2][2] * rhs.z
	);
}
