#include "RT.h"

float	intersect_circle(t_ray *ray, t_circle *circle)
{
	float	a;
	float	b;
	float	c;
	float	delta;

	a = ray->d.x * ray->d.x + ray->d.y * ray->d.y + ray->d.z * ray->d.z;
	b = 2 * (ray->d.x * (ray->o.x - circle->center.x) + ray->d.y * (ray->o.y - circle->center.y) +
			ray->d.z * (ray->o.z - circle->center.z));
	c = ((ray->o.x - circle->center.x) * (ray->o.x - circle->center.x) + (ray->o.y - circle->center.y) * (ray->o.y - circle->center.y) +
			(ray->o.z - circle->center.z) * (ray->o.z - circle->center.z)) - circle->r * circle->r;
	delta = b * b - 4 * a * c;
	if (delta < 0)
		return (-1);
	else
		return (intersect_point(a, b, delta));
}
