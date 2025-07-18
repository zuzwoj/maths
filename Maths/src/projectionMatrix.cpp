#include "Maths/matrix4x4.h"
#include <cmath>

ProjectionMatrix::ProjectionMatrix(double fov, double aspect, double near, double far) : Matrix4x4(
	// row 1
	1 / (aspect * tan(fov / 2)), 
	0.0f, 
	0.0f, 
	0.0f, 
	// row 2
	0.0f, 
	1 / (tan(fov / 2)), 
	0.0f, 
	0.0f, 
	// row 3
	0.0f, 
	0.0f, 
	(far + near) / (far - near), 
	-2 * far * near / (far - near), 
	// row 4
	0.0f, 
	0.0f, 
	1.0f, 
	0.0f) { }
