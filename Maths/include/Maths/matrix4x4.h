#pragma once
#include "matrix.h"
#include "vector.h"
#include <algorithm>

class Matrix4x4 : public Matrix
{
protected:
	double elems[4][4];

public:
	Matrix4x4(double a00, double a01, double a02, double a03,
		double a10, double a11, double a12, double a13,
		double a20, double a21, double a22, double a23,
		double a30, double a31, double a32, double a33);
	Matrix4x4();

	void transpose() override;
	void toArray(double* out) override;
	void toFloatArray(float* out) override;
	void override(Matrix4x4 source);

	friend Matrix4x4 operator*(Matrix4x4 lhs, const Matrix4x4& rhs);
	friend Matrix4x4 operator*(Matrix4x4 lhs, const double& rhs);
	friend Matrix4x4 operator*(double lhs, const Matrix4x4& rhs);
	friend Vector4 operator*(Matrix4x4 lhs, const Vector4& rhs);
};

class DiagonalMatrix : public Matrix4x4
{
public:
	DiagonalMatrix(double a0, double a1, double a2, double a3);
};

class IdentityMatrix : public DiagonalMatrix
{
public:
	IdentityMatrix();
};

/****************************************************
* ROTATION MATRICES
****************************************************/
class RotationMatrix : public Matrix4x4
{
public:
	RotationMatrix(double ax, double ay, double az);
	RotationMatrix(Vector3 axyz) : RotationMatrix(axyz.x, axyz.y, axyz.z) {}
};

class RotationXMatrix : public RotationMatrix
{
public:
	RotationXMatrix(double angle) : RotationMatrix(angle, 0.0, 0.0) {}
};

class RotationYMatrix : public RotationMatrix
{
public:
	RotationYMatrix(double angle) : RotationMatrix(0.0, angle, 0.0) {}
};

class RotationZMatrix : public RotationMatrix
{
public:
	RotationZMatrix(double angle) : RotationMatrix(0.0, 0.0, angle) {}
};

/****************************************************
* TRANSLATION MATRICES
****************************************************/
class TranslationMatrix : public Matrix4x4
{
public:
	TranslationMatrix(double tx, double ty, double tz);
	TranslationMatrix(Vector3 txyz) : TranslationMatrix(txyz.x, txyz.y, txyz.z) {}
};

class TranslationXMatrix : public TranslationMatrix
{
public:
	TranslationXMatrix(double offset) : TranslationMatrix(offset, 0.0, 0.0) {}
};

class TranslationYMatrix : public TranslationMatrix
{
public:
	TranslationYMatrix(double offset) : TranslationMatrix(0.0, offset, 0.0) {}
};

class TranslationZMatrix : public TranslationMatrix
{
public:
	TranslationZMatrix(double offset) : TranslationMatrix(0.0, 0.0, offset) {}
};

/****************************************************
* SCALE MATRICES
****************************************************/
class ScaleMatrix : public DiagonalMatrix
{
public:
	ScaleMatrix(double sx, double sy, double sz);
	ScaleMatrix(Vector3 sxyz) : ScaleMatrix(sxyz.x, sxyz.y, sxyz.z) {}
};

class ScaleXMatrix : public ScaleMatrix
{
public:
	ScaleXMatrix(double scale) : ScaleMatrix(scale, 1.0, 1.0) {}
};

class ScaleYMatrix : public ScaleMatrix
{
public:
	ScaleYMatrix(double scale) : ScaleMatrix(1.0, scale, 1.0) {}
};

class ScaleZMatrix : public ScaleMatrix
{
public:
	ScaleZMatrix(double scale) : ScaleMatrix(1.0, 1.0, scale) {}
};

/****************************************************
* PROJECTION MATRIX
****************************************************/
class ProjectionMatrix : public Matrix4x4
{
public:
	ProjectionMatrix(double fov, double aspect, double near, double far);
};

class StereoscopicProjectionMatrix : public Matrix4x4
{
public:
	StereoscopicProjectionMatrix(double fov, double aspect, double near, double far, double I, double C);
};

class InvertedProjectionMatrix : public Matrix4x4
{
public:
	InvertedProjectionMatrix(double fov, double aspect, double near, double far);
};
