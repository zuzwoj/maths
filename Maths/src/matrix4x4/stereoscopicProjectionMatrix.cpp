#include "Maths/matrix4x4.h"

StereoscopicProjectionMatrix::StereoscopicProjectionMatrix(double fov, double aspect, double near, double far, double I, double C)
{
	double top = near * tan(fov / 2);
	double bottom = -top;
	double shift = I * near / C;
	double right = top * aspect + shift;
	double left = -top * aspect + shift;

	elems[0][0] = 2 * near / (right - left);
	elems[1][0] = 0.0;
	elems[2][0] = 0.0;
	elems[3][0] = 0.0;

	elems[0][1] = 0.0;
	elems[1][1] = 2 * near / (top - bottom);
	elems[2][1] = 0.0;
	elems[3][1] = 0.0;

	elems[0][2] = (right + left) / (right - left);
	elems[1][2] = (top + bottom) / (top - bottom);
	elems[2][2] = (far + near) / (far - near);
	elems[3][2] = 1.0;

	elems[0][3] = 0.0;
	elems[1][3] = 0.0;
	elems[2][3] = -2.0 * far * near / (far - near);
	elems[3][3] = 0.0;
}
