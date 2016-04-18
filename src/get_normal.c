#include "RT.h"

static void		get_cylinder_normal(t_vec3 *normal, t_cylinder *cylinder, t_coord *point)
{
	t_vec3	v;
	t_vec3	project;
	float	dot;
	t_vec3	n;

	n = cylinder->d;
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

static void		get_cone_normal(t_vec3 *normal, t_cone *cone, t_coord *point)
{
	t_vec3	v;
	t_vec3	project;
	float	dot;
	t_vec3	n;

	n = cone->n;
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

int			get_normal(t_vec3 *normal, t_scene *obj, t_coord *point)
{
	t_cone		*circle;
	t_cone		*plane;
	t_cone		*cone;
	t_cylinder	*cylinder;

	if (obj->type == CONE)
	{
		cone = obj->object;
		get_cone_normal(normal, cone, point);
	}
	else if (obj->type == CYLINDER)
	{
		cylinder = obj->object;
		get_cylinder_normal(normal, cylinder, point);
	}
	else if (obj->type == PLANE)
	{
		plane = obj->object;
		normal->x =  plane->n.x;
		normal->y =  plane->n.y;
		normal->z =  plane->n.z;
		normalize(normal);
	}
	else if (obj->type == CIRCLE)
	{
		circle = obj->object;
		normal->x =  point->x - circle->center.x;
		normal->y =  point->y - circle->center.y;
		normal->z =  point->z - circle->center.z;
		normalize(normal);
	}
	else
		return (1);
	return (0);
}
