#include "RT.h"
#include <stdlib.h>

t_scene	*intersect_shadow(t_ray *ray, t_scene *scene, t_light *light)
{
	float	t;
	float	t_tmp;
	t_scene	*begin;
	t_scene	*obj;

	obj = NULL;
	if (ray->d.x > 0)
		t = (light->center.x - ray->o.x) / ray->d.x;
	else if (ray->d.y > 0)
		t = (light->center.y - ray->o.y) / ray->d.y;
	else if (ray->d.z > 0)
		t = (light->center.z - ray->o.z) / ray->d.z;
	begin = scene;
	while (scene != NULL)
	{
		if (scene->type == CIRCLE)
		{
			t_tmp = intersect_circle(ray, scene->object);
		}
		else if (scene->type == PLANE)
		{
			t_tmp = intersect_plane(ray, scene->object);
		}
		else if (scene->type == CYLINDER)
		{
			t_tmp = intersect_cylinder(ray, scene->object);
		}
		else if (scene->type == CONE)
		{
			t_tmp = intersect_cone(ray, scene->object);
		}
		if (obj == NULL && t_tmp > 0 && t_tmp < t)
		{
			t = t_tmp;
			obj = scene;
		}
		else if (t_tmp > 0 && t_tmp < t)
		{
			if (t > t_tmp)
			{
				t = t_tmp;
				obj = scene;
			}
		}
		scene = scene->next;
	}
	return (obj);
}
