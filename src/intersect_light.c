#include "RT.h"

#include <stdio.h>

static int	rgb_int(int r, int g, int b)
{
    return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

/*
int		int_rgb(int color)
{
	int	rgb[3];

	rgb[0] = (color>>16) & 255;
	rgb[0] = (color>>8) & 255;
	rgb[0] = color & 255;
	return (rgb);
}
*/
int		intersect_light(t_coord point, t_ray *ray, t_scene *obj, t_light light)
{
	float		tmp;
	int			rgb[3];
	t_vec3		dis;
	t_vec3		dis2;
	t_vec3		n;
	t_circle	*circle;



//	rgb = int_rgb(obj->color);
	rgb[2] = obj->color & 255;
	rgb[1] = (obj->color>>8) & 255;
	rgb[0] = (obj->color>>16) & 255;

	dis.x = light.center.x - point.x;
	dis.y = light.center.y - point.y;
	dis.z = light.center.z - point.z;

	dis2.x = dis.x; 
	dis2.y = dis.y; 
	dis2.z = dis.z; 

	normalize(&dis2);

	(void)ray;
	if (obj->type == CIRCLE)
	{
		circle = obj->object;
		n.x = point.x - circle->center.x;
		n.y = point.y - circle->center.y;
		n.z = point.z - circle->center.z;

		normalize(&n);
		tmp = dot_product(&dis2 ,&n);
		if (tmp < 0)
			tmp = 0;
		if (tmp > 1)
			tmp = 1;
//		rgb[0] = rgb[0] * (float)( 0.1  / (0.000001 + (float)distance(&dis)) * tmp);
//		rgb[1] = rgb[1] * (float)( 0.1  / (0.000001 + (float)distance(&dis)) * tmp);
//		rgb[2] = rgb[2] * (float)( 0.1  / (0.000001 + (float)distance(&dis)) * tmp);
		rgb[0] = rgb[0] * tmp;
		rgb[1] = rgb[1] * tmp;
		rgb[2] = rgb[2] * tmp;
		return (rgb_int(rgb[0], rgb[1], rgb[2]));
	}
	else
		return (obj->color);
}
