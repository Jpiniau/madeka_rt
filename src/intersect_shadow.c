#include "RT.h"
#include <stdlib.h>

#include "libft.h"
int	intersect_shadow(float t, t_scene *scene, t_ray *ray)
{
	t_coord	intersect_pt;
	t_ray	shadow;
	float	t_tmp;

	intersect_pt.x = ray->o.x + t * ray->d.x;
	intersect_pt.y = ray->o.y + t * ray->d.y;
	intersect_pt.z = ray->o.z + t * ray->d.z;
	init_coord(&shadow.o, 0, 0, -5);
	init_vec3(&(shadow.d), shadow.o.x - intersect_pt.x, shadow.o.y - intersect_pt.y, shadow.o.z - intersect_pt.z);
	t_tmp = -1;
	while (scene != NULL)
	{
		if (scene->type == CIRCLE)
			t_tmp = intersect_circle(&shadow, scene->object);
		else if (scene->type == PLANE)
			t_tmp = intersect_plane(&shadow, scene->object);
		else if (scene->type == CYLINDER)
			t_tmp = intersect_cylinder(&shadow, scene->object);
		if (t_tmp > 0)
		{
			return (1);
		}
		scene = scene->next;
	}
	return (0);
}
