#include <math.h>

float	tan2(float x)
{
	return ((1 - cos(2 * x)) / (1 + cos(2 * x)));
}
