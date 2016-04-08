#include "RT.h"
#include "libft.h"

#include <stdio.h>

void	scan_scene(t_env *env, t_scene *scene)
{
	int			x;
	int			y;
	t_coord		point;
	t_coord		tmp;
	t_light		light;
	t_ray		ray;
	t_scene		*obj;

	(void) env;
	x = 0;
	init_coord(&(light.center), 0, 20, -19);

	t_scene *begin;
 	begin = scene;
 	while (scene != NULL)
	{
	//	circle = scene->object;
		printf("%d\n", scene->type);
		scene = scene->next;
	}
	scene = begin;

	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			init_ray(&ray, x, y);
			obj = intersect_object(&ray, scene, &point);
			if (obj != NULL)
			{
		//		ft_putnbr(obj->type);
				init_shadow_ray(&ray, light.center, point);
				if (intersect_object(&ray, scene, &tmp) != NULL)
					ft_pixel_to_img(env, x, y, 0x000000);
				else
					ft_pixel_to_img(env, x, y, intersect_light(point, &ray, obj, light));
					//ft_pixel_to_img(env, x, y, obj->color);
			}
			else
				ft_pixel_to_img(env, x, y, 0);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}
