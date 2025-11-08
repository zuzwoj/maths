#include "Maths/matrix4x4.h"

TranslationMatrix::TranslationMatrix(double tx, double ty, double tz) : Matrix4x4(
	1.0, 0.0, 0.0, tx, 
	0.0, 1.0, 0.0, ty, 
	0.0, 0.0, 1.0, tz, 
	0.0, 0.0, 0.0, 1.0) {}
