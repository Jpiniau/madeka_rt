#include "RT.h"

#include <stdio.h>

int		intersect_light(t_coord point, t_ray *ray, t_scene *obj, t_light light)
{
	int			i;
	t_vec3		dis;
	t_vec3		dis2;
	t_vec3		n;
	t_circle	*circle;

	dis.x = point.x - light.center.x;
	dis.y = point.y - light.center.y;
	dis.z = point.z - light.center.z;

	dis2.x = dis.x; 
	dis2.y = dis.y; 
	dis2.z = dis.z; 

	normalize(&dis2);

	(void)ray;
	if (obj->type == CIRCLE)
	{
		circle = obj->object;
		n.x = circle->center.x - point.x;
		n.y = circle->center.y - point.y;
		n.z = circle->center.z - point.z;

		normalize(&n);
		i = obj->color * ( 1  / (0.000001 + distance(&dis)) * dot_product(&n ,&dis2));
		printf("%d\n", i);
		//i = dot_product(&n, &dis2);
		//if (i < 0)
		//	i = 0;
		//return(obj->color * (i + 20));
		return (i);
	}
	else
		return (obj->color);
}
