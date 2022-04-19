#include "GetVolumeSurface.h"
double GetVolumeSurface(double x, double y, double z, double *surface)
{
	double a;
	double b;
	double c;

	a = 2 * x * y;
	b = 2 * y * z;
	c = 2 * x * z;
	*surface = a + b + c;

	return x * y * z;
}