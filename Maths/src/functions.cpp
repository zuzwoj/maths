#include "Maths/functions.h"

namespace maths
{
	double abs(double arg)
	{
		return arg > 0 ? arg : -arg;
	}

	double sgn(double arg) 
	{
		return arg ? arg / abs(arg) : 0.0;
	}
}
