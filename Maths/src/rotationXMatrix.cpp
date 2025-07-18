#include "Maths/matrix4x4.h"

RotationXMatrix::RotationXMatrix(double angle) : Matrix4x4(
	// row 1
	1.0f,
	0.0f, 
	0.0f, 
	0.0f,
	// row 2
	0.0f, 
	cos(angle), 
	-sin(angle), 
	0.0f,
	// row 3
	0.0f, 
	sin(angle), 
	cos(angle), 
	0.0f,
	// row 4
	0.0f, 
	0.0f, 
	0.0f, 
	1.0f) {}
