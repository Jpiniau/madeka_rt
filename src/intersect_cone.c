#include "RT.h"

float	intersect_cone(t_ray *ray, t_cone *cone)
{
	t_vec3	diff;
	double	a;
	double	b;
	double	c;
	double	delta;

	diff.x = ray->o.x - cone->center.x;
	diff.y = ray->o.y - cone->center.y;
	diff.z = ray->o.z - cone->center.z;
	a = ray->d.x * ray->d.x - ray->d.y * ray->d.y + ray->d.z * ray->d.z;
	b = ray->d.x * diff.x - ray->d.y * diff.y + ray->d.z * diff.z;
	c = diff.x * diff.x + diff.z * diff.z - diff.y * diff.y;
	delta = b * b - a * c;
	return (intersect_point(a, b, delta));
}
