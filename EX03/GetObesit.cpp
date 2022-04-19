#include "GetObesit.h"
int GetObesit(double bmi)
{
	int obesit;

	if (bmi <= 18.5)
	{
		obesit = -1;
	}
	else if (bmi <= 25)
	{
		obesit = 0;
	}
	else if (bmi <= 30)
	{
		obesit = 1;
	}
	else if (bmi <= 35)
	{
		obesit = 2;
	}
	else if (bmi <= 40)
	{
		obesit = 3;
	}
	else
	{
		obesit = 4;
	}

	return obesit;
}