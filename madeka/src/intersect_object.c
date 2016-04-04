#include "RT.h"
#include <stdlib.h>

t_scene	*intersect_object(t_ray *ray, t_scene *scene)
{
	float	t;
	float	t_tmp;
	t_scene	*begin;
	t_scene	*obj;

	obj = NULL;
	t = -1;
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
		if (obj == NULL && t_tmp > 0)
		{
			t = t_tmp;
			obj = scene;
		}
		else if (t_tmp > 0)
		{
			if (t > t_tmp)
			{
				t = t_tmp;
				obj = scene;
			}
		}
		scene = scene->next;
	}
	if (obj != NULL)
		if (intersect_shadow(t, begin, ray) == 1)
			obj->color = 0xF0F0F0;
	return (obj);
}
