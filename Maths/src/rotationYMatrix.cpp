#include "Maths/matrix4x4.h"

RotationYMatrix::RotationYMatrix(double angle) : Matrix4x4(
	// row 1
	cos(angle), 
	0.0f, 
	sin(angle), 
	0.0f,
	// row 2
	0.0f, 
	1.0f, 
	0.0f, 
	0.0f,
	// row 3
	-sin(angle), 
	0.0f, 
	cos(angle), 
	0.0f,
	// row 4
	0.0f, 
	0.0f, 
	0.0f, 
	1.0f) { }
