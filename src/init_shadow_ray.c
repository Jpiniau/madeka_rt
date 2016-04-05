#include "RT.h"

void 	init_shadow_ray(t_ray *ray, t_coord light, t_coord point)
{
	init_coord(&(ray->o), point.x, point.y, point.z);
	init_vec3(&(ray->d), light.x - point.x, light.y - point.y, light.z - point.z);
	normalize(&(ray->d));
}
