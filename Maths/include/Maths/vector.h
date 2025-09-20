#pragma once
#include <cmath>

class Vector3;
class Vector4;

class Vector
{
public:
	virtual double len() const = 0;
	virtual void normalize() = 0;
};

class Vector2 : public Vector
{
public:
	double x;
	double y;

	constexpr Vector2(double x, double y);
	constexpr Vector2(Vector3 v);
	constexpr Vector2();

	double len() const override;
	void normalize() override;
	void override(Vector2 v);

	// negation
	Vector2 operator-();

	// vector addition
	Vector2& operator+=(const Vector2& rhs);
	Vector2& operator-=(const Vector2& rhs);
	friend Vector2 operator+(Vector2 lhs, const Vector2& rhs);
	friend Vector2 operator-(Vector2 lhs, const Vector2& rhs);

	// manipulation by double
	// addition
	Vector2& operator+=(const double& rhs);
	friend Vector2 operator+(Vector2 lhs, const double& rhs);
	friend Vector2 operator+(double lhs, const Vector2& rhs);
	// subtraction
	Vector2& operator-=(const double& rhs);
	friend Vector2 operator-(Vector2 lhs, const double& rhs);
	friend Vector2 operator-(double lhs, const Vector2& rhs);
	// multiplication
	Vector2& operator*=(const double& rhs);
	friend Vector2 operator*(double lhs, const Vector2& rhs);
	friend Vector2 operator*(Vector2 lhs, const double& rhs);
	// division
	Vector2& operator/=(const double& rhs);
	friend Vector2 operator/(Vector2 lhs, const double& rhs);
	
	// dot product
	friend double operator*(Vector2 lhs, const Vector2& rhs);
};

class Vector3 : public Vector
{
public:
	double x;
	double y;
	double z;

	constexpr Vector3(double x, double y, double z);
	constexpr Vector3(Vector2 v);
	constexpr Vector3(Vector4 v);
	constexpr Vector3();

	double len() const override;
	void normalize() override;
	void override(Vector3 v);
	Vector3 crossProduct(Vector3 rhs);

	// negation
	Vector3 operator-();

	//vector addition
	Vector3& operator+=(const Vector3& rhs);
	Vector3& operator-=(const Vector3& rhs);
	friend Vector3 operator+(Vector3 lhs, const Vector3& rhs);
	friend Vector3 operator-(Vector3 lhs, const Vector3& rhs);

	// manipulation by double
	// addition
	Vector3& operator+=(const double& rhs);
	friend Vector3 operator+(Vector3 lhs, const double& rhs);
	friend Vector3 operator+(double lhs, const Vector3& rhs);
	// subtraction
	Vector3& operator-=(const double& rhs);
	friend Vector3 operator-(Vector3 lhs, const double& rhs);
	friend Vector3 operator-(double lhs, const Vector3& rhs);
	// multuplication
	Vector3& operator*=(const double& rhs);
	friend Vector3 operator*(double lhs, const Vector3& rhs);
	friend Vector3 operator*(Vector3 lhs, const double& rhs);
	// division
	Vector3& operator/=(const double& rhs);
	friend Vector3 operator/(Vector3 lhs, const double& rhs);

	// dot product
	friend double operator*(Vector3 lhs, const Vector3& rhs);
};

class Vector4 : public Vector
{
public:
	double x;
	double y;
	double z;
	double t;

	constexpr Vector4(double x, double y, double z, double t);
	constexpr Vector4(Vector3 v);
	constexpr Vector4();

	double len() const override;
	void normalize() override;
	void override(Vector4 v);

	// negation
	Vector4 operator-();

	// vector addition
	Vector4& operator+=(const Vector4& rhs);
	Vector4& operator-=(const Vector4& rhs);
	friend Vector4 operator+(Vector4 lhs, const Vector4& rhs);
	friend Vector4 operator-(Vector4 lhs, const Vector4& rhs);

	// manipulation by double
	// addition
	Vector4& operator+=(const double& rhs);
	friend Vector4 operator+(Vector4 lhs, const double& rhs);
	friend Vector4 operator+(double lhs, const Vector4& rhs);
	// subtraction
	Vector4& operator-=(const double& rhs);
	friend Vector4 operator-(Vector4 lhs, const double& rhs);
	friend Vector4 operator-(double lhs, const Vector4& rhs);
	// multuplication
	Vector4& operator*=(const double& rhs);
	friend Vector4 operator*(double lhs, const Vector4& rhs);
	friend Vector4 operator*(Vector4 lhs, const double& rhs);
	// division
	Vector4& operator/=(const double& rhs);
	friend Vector4 operator/(Vector4 lhs, const double& rhs);

	// dot product
	friend double operator*(Vector4 lhs, const Vector4& rhs);
};

constexpr Vector2::Vector2(double x, double y) : x(x), y(y) {}
constexpr Vector2::Vector2(Vector3 v) : x(v.x), y(v.y) {}
constexpr Vector2::Vector2() : x(0.0f), y(0.0f) {}

constexpr Vector3::Vector3(double x, double y, double z) : x(x), y(y), z(z) {}
constexpr Vector3::Vector3(Vector2 v) : x(v.x), y(v.y), z(0.0f) {}
constexpr Vector3::Vector3(Vector4 v) : x(v.x), y(v.y), z(v.z) {}
constexpr Vector3::Vector3() : x(0.0f), y(0.0f), z(0.0f) {}

constexpr Vector4::Vector4(double x, double y, double z, double t) : x(x), y(y), z(z), t(t) {}
constexpr Vector4::Vector4(Vector3 v) : x(v.x), y(v.y), z(v.z), t(1.0f) {}
constexpr Vector4::Vector4() : x(0.0f), y(0.0f), z(0.0f), t(0.0f) {}
