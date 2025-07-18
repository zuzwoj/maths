#include "Maths/matrix4x4.h"

RotationZMatrix::RotationZMatrix(double angle) : Matrix4x4(
	// row 1
	cos(angle), 
	-sin(angle), 
	0.0f, 
	0.0f,
	// row 2
	sin(angle), 
	cos(angle), 
	0.0f, 
	0.0f,
	// row 3
	0.0f, 
	0.0f, 
	1.0f, 
	0.0f,
	// row 4
	0.0f, 
	0.0f, 
	0.0f, 
	1.0f) { }
