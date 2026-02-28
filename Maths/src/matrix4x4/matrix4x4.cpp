#include "Maths/matrix4x4.h"
#include <cmath>
#include <stdexcept>
#include <string>

Matrix4x4::Matrix4x4(
	double a00, double a01, double a02, double a03,
	double a10, double a11, double a12, double a13,
	double a20, double a21, double a22, double a23,
	double a30, double a31, double a32, double a33)
{
	elems[0][0] = a00;
	elems[1][0] = a10;
	elems[2][0] = a20;
	elems[3][0] = a30;

	elems[0][1] = a01;
	elems[1][1] = a11;
	elems[2][1] = a21;
	elems[3][1] = a31;

	elems[0][2] = a02;
	elems[1][2] = a12;
	elems[2][2] = a22;
	elems[3][2] = a32;

	elems[0][3] = a03;
	elems[1][3] = a13;
	elems[2][3] = a23;
	elems[3][3] = a33;
}

Matrix4x4::Matrix4x4() : Matrix4x4(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0) {}

void Matrix4x4::transpose()
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			std::swap(elems[i][j], elems[j][i]);
		}
	}
}

Matrix4x4 Matrix4x4::getTransposed()
{
	return Matrix4x4(
		elems[0][0], elems[1][0], elems[2][0], elems[3][0],
		elems[0][1], elems[1][1], elems[2][1], elems[3][1],
		elems[0][2], elems[1][2], elems[2][2], elems[3][2],
		elems[0][3], elems[1][3], elems[2][3], elems[3][3]
	);
}

void Matrix4x4::toArray(double* out)
{
	for (int i = 0; i < 4; ++i) 
	{
		for (int j = 0; j < 4; ++j)
		{
			out[i * 4 + j] = elems[i][j];
		}
	}
}

void Matrix4x4::toFloatArray(float* out)
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			out[i * 4 + j] = (float)elems[i][j];
		}
	}
}

void Matrix4x4::override(Matrix4x4 source)
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			elems[i][j] = source.elems[i][j];
		}
	}
}

double Matrix4x4::at(unsigned int row, unsigned int column)
{
	if (row >= 4 || column >= 4)
	{
		throw std::invalid_argument("trying to obtain a value of index (" + std::to_string(row) + ", " + std::to_string(column) + ") from Matrix4x4");
	}
	return elems[row][column];
}

Matrix4x4 operator*(Matrix4x4 lhs, const Matrix4x4& rhs)
{
	Matrix4x4 result = Matrix4x4();
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			result.elems[i][j] = 
				lhs.elems[i][0] * rhs.elems[0][j] + 
				lhs.elems[i][1] * rhs.elems[1][j] + 
				lhs.elems[i][2] * rhs.elems[2][j] + 
				lhs.elems[i][3] * rhs.elems[3][j];
		}
	}
	return result;
}

Matrix4x4 operator*(Matrix4x4 lhs, const double& rhs)
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			lhs.elems[i][j] *= rhs;
		}
	}
	return lhs;
}

Matrix4x4 operator*(double lhs, const Matrix4x4& rhs)
{
	Matrix4x4 result;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			result.elems[i][j] = rhs.elems[i][j] * lhs;
		}
	}
	return result;
}

Vector4 operator*(Matrix4x4 lhs, const Vector4& rhs)
{
	return Vector4(
		lhs.elems[0][0] * rhs.x + lhs.elems[0][1] * rhs.y + lhs.elems[0][2] * rhs.z + lhs.elems[0][3] * rhs.t,
		lhs.elems[1][0] * rhs.x + lhs.elems[1][1] * rhs.y + lhs.elems[1][2] * rhs.z + lhs.elems[1][3] * rhs.t,
		lhs.elems[2][0] * rhs.x + lhs.elems[2][1] * rhs.y + lhs.elems[2][2] * rhs.z + lhs.elems[2][3] * rhs.t,
		lhs.elems[3][0] * rhs.x + lhs.elems[3][1] * rhs.y + lhs.elems[3][2] * rhs.z + lhs.elems[3][3] * rhs.t
	);
}
