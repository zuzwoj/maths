#include "Maths/matrix4x4.h"
#include <cmath>

InvertedProjectionMatrix::InvertedProjectionMatrix(double fov, double aspect, double near, double far) : Matrix4x4(
		// row 1
		aspect* tan(0.5 * fov), 
		0.0, 
		0.0, 
		0.0,
		// row 2
		0.0, 
		tan(0.5 * fov), 
		0.0, 
		0.0,
		// row 3
		0.0, 
		0.0, 
		0.0, 
		1.0,
		// row 4
		0.0, 
		0.0, 
		(near - far) / (2 * far * near), 
		(far + near) / (2 * far * near)) { }
