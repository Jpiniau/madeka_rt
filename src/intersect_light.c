#include "RT.h"

#include <stdio.h>

static int	rgb_int(int r, int g, int b)
{
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

static t_vec3	vecsvec(t_vec3 a, t_vec3 b)
{
	t_vec3 result;

	init_vec3(&result, a.x - b.x, a.y - b.y, a.z - b.z);
	return (result);
}
/*
static t_vec3	vecmvec(t_vec3 *a, t_vec3 *b)
{
	t_vec3 result;

	init_vec3(&result, a->x * b->x, a->y * b->y, a->z * b->z);
	return (result);
}
*/
/*
static t_vec3	vecaf(t_vec3 *a, float b)
{
	t_vec3	result;

	init_vec3(&result, a->x + b, a->y + b, a->z + b);
	return (result);
}
*/
static t_vec3	vecmf(t_vec3 a, float b)
{
	t_vec3	result;

	init_vec3(&result, a.x * b, a.y * b, a.z * b);
	return (result);
}

int		intersect_light(t_coord point, t_ray *ray, t_scene *obj, t_light light)
{
	float		dif;
	float		refl;
	int			rgb[3];
	t_vec3		tmp;
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

	refl = 0;
	(void)ray;
	if (obj->type == CIRCLE)
	{
		circle = obj->object;
		n.x = point.x - circle->center.x;
		n.y = point.y - circle->center.y;
		n.z = point.z - circle->center.z;

		normalize(&n);
		dif = dot_product(&dis2 ,&n);
		if (dot_product(&n, &dis2) > 0)
		{
			ft_putchar('d');
			tmp = vecsvec(dis2, vecmf(vecmf(n, dot_product(&n, &dis2)), 2.0));
			refl = dot_product(&ray->d, &tmp);
		}
		if (refl < 0)
			refl = 0;
		if (refl > 1)
			refl = 1;
		if (dif < 0)
			dif = 0;
		if (dif > 1)
			dif = 1;
		//		rgb[0] = rgb[0] * (float)( 0.1  / (0.000001 + (float)distance(&dis)) * dif);
		//		rgb[1] = rgb[1] * (float)( 0.1  / (0.000001 + (float)distance(&dis)) * dif);
		//		rgb[2] = rgb[2] * (float)( 0.1  / (0.000001 + (float)distance(&dis)) * dif);
		rgb[0] = rgb[0] * (dif + 0.2 + ft_pow(refl, 512));
		rgb[1] = rgb[1] * (dif + 0.2 + ft_pow(refl, 512));
		rgb[2] = rgb[2] * (dif + 0.2 + ft_pow(refl, 512));
		rgb[0] = rgb[0] > 255 ? 255 : rgb[0];
		rgb[1] = rgb[1] > 255 ? 255 : rgb[1];
		rgb[2] = rgb[2] > 255 ? 255 : rgb[2];
		return (rgb_int(rgb[0], rgb[1], rgb[2]));
	}
	else
		return (obj->color);
}
