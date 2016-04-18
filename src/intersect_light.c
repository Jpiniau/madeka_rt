#include "RT.h"
#include <math.h>

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
/*
void			get_cylinder_normal(t_vec3 *normal, t_cylinder *cylinder, t_coord *point)
{
	t_vec3	v;
	t_vec3	project;
	float	dot;
	t_vec3	n;

	n = cylinder->d;
	//	if (vect_norm(&n) - 1 > 0.05)
	//		normalize_vector(&cylinder->n);
	v.x = point->x - cylinder->center.x;
	v.y = point->y - cylinder->center.y;
	v.z = point->z - cylinder->center.z;
	dot = dot_product(&v, &cylinder->n);
	project.x = dot * cylinder->d.x;
	project.y = dot * cylinder->d.y;
	project.z = dot * cylinder->d.z;
	normal->x = v.x - project.x;
	normal->y = v.y - project.y;
	normal->z = v.z - project.z;
	normalize(normal);
}

void		get_cone_normal(t_vec3 *normal, t_cone *cone,	t_coord *point)
{
	t_vec3	v;
	t_vec3	project;
	float	dot;
	t_vec3	n;

	n = cone->n;
//	if (vect_norm(&n) - 1 > 0.05)
//		normalize_vector(&cone->normal);
	v.x = point->x - cone->center.x;
	v.y = point->y - cone->center.y;
	v.z = point->z - cone->center.z;
	dot = dot_product(&v, &cone->n);
	project.x = dot * cone->n.x;
	project.y = dot * cone->n.y;
	project.z = dot * cone->n.z;
	normal->x = v.x - project.x;
	normal->y = v.y - project.y;
	normal->z = v.z - project.z;
	normalize(normal);
}
*/
static t_vec3	vecmf(t_vec3 a, float b)
{
	t_vec3	result;

	init_vec3(&result, a.x * b, a.y * b, a.z * b);
	return (result);
}

static t_vec3	ft_reflect(t_vec3 i, t_vec3 n)
{
	return(vecsvec(i, vecmf(n, 2 * dot_product(&n, &i))));
}

static float	reflect(t_coord point, t_ray *ray, t_vec3 n, t_light light)
{
	t_vec3	v;
	t_vec3	r;
	t_vec3	l;
	t_vec3	tmp;
	float	refl;

	l.x = light.center.x - point.x;
	l.y = light.center.y - point.y;
	l.z = light.center.z - point.z;
	normalize(&l);

	v.x = ray->o.x - point.x;
	v.y = ray->o.y - point.y;
	v.z = ray->o.z - point.z;
	normalize(&v);

	if (dot_product(&n, &l) <= 0)
		return (0);
	tmp = vecmf(n, dot_product(&n, &l) * 2);
	r = ft_reflect(l, n);
	normalize(&r);
	refl = dot_product(&ray->d, &r);
	refl = refl < 0 ? 0 : refl;
	refl = refl > 1 ? 1 : refl;
	return (pow(refl, 128));
}

int		intersect_light(t_coord point, t_ray *ray, t_scene *obj, t_light light)
{
	float		dif;
	float		amb;
	float		refl;
	int			rgb[3];
	t_vec3		dis;
	t_vec3		n;
	t_circle	*circle;
	t_plane		*plane;
	t_vec3		normal;

	//	rgb = int_rgb(obj->color);
	rgb[2] = obj->color & 255;
	rgb[1] = (obj->color>>8) & 255;
	rgb[0] = (obj->color>>16) & 255;

	dis.x = light.center.x - point.x;
	dis.y = light.center.y - point.y;
	dis.z = light.center.z - point.z;

	normalize(&dis);

	refl = 0;
	amb = 0.2;
	if (obj->type == CIRCLE)
	{
		circle = obj->object;
		n.x = point.x - circle->center.x;
		n.y = point.y - circle->center.y;
		n.z = point.z - circle->center.z;
		normalize(&n);
		dif = dot_product(&dis, &n);
		refl = reflect(point, ray, n, light);
	}
	else if (obj->type == PLANE)
	{
		plane = obj->object;
		dif = dot_product(&dis, &plane->n);
		refl = reflect(point, ray, plane->n, light);
	}
	else if (obj->type == CYLINDER)
	{
		get_normal($normal, obj, &point)
		dif = dot_product(&dis, &normal);
		refl = reflect(point, ray, normal, light);
	}
	else if (obj->type == CONE)
	{
		get_normal($normal, obj, &point)
		dif = dot_product(&dis, &normal);
		refl = reflect(point, ray, normal, light);
	}
	else
		return (obj->color);
	dif = dif < 0 ? 0 : dif;
	dif = dif > 1 ? 1 : dif;
	rgb[0] = rgb[0] * (dif + amb + refl);
	rgb[1] = rgb[1] * (dif + amb + refl);
	rgb[2] = rgb[2] * (dif + amb + refl);
	rgb[0] = rgb[0] > 255 ? 255 : rgb[0];
	rgb[1] = rgb[1] > 255 ? 255 : rgb[1];
	rgb[2] = rgb[2] > 255 ? 255 : rgb[2];
	return (rgb_int(rgb[0], rgb[1], rgb[2]));
}
