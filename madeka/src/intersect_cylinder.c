#include "RT.h"

float	intersect_cylinder(t_ray *ray, t_cylinder *cylinder)
{
	float	a;
	float	b;
	float	c;
	float	delta;

	a = ray->d.x * ray->d.x + ray->d.z * ray->d.z;
	b = 2 * (ray->d.x * (ray->o.x - cylinder->center.x) + ray->d.z * (ray->o.z - cylinder->center.z));
	c = (ray->o.x - cylinder->center.x) * (ray->o.x - cylinder->center.x) +
		(ray->o.z - cylinder->center.z) * (ray->o.z - cylinder->center.z) - cylinder->r * cylinder->r;
	delta = b * b - 4 * a * c;
	if (delta < 0)
		return (-1);
	else
		return (intersect_point(a, b, delta));
}
