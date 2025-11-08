#pragma once

class Matrix
{
public:
	virtual void transpose() = 0;
	virtual void toArray(double* out) = 0;
	virtual void toFloatArray(float* out) = 0;
};
