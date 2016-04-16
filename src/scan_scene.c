#include "RT.h"
#include "libft.h"

#include <stdio.h>

static int	rgb_int(int r, int g, int b)
{
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

static int ambient_color(int color)
{
	int	rgb[3];

	rgb[2] = color & 255;
	rgb[1] = (color>>8) & 255;
	rgb[0] = (color>>16) & 255;

	rgb[0] *= 0.2;
	rgb[1] *= 0.2;
	rgb[2] *= 0.2;
	return (rgb_int(rgb[0], rgb[1], rgb[2]));
}

void	scan_scene(t_env *env, t_scene *scene)
{
	int			x;
	int			y;
	t_coord		point;
	t_coord		tmp;
	t_light		light;
	t_ray		ray;
	t_ray		ray2;
	t_scene		*obj;

	(void) env;
	x = 0;
	init_coord(&(light.center), 0, 7, -20);

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
				init_shadow_ray(&ray2, light.center, point);
				if (intersect_object(&ray2, scene, &tmp) != NULL)
					ft_pixel_to_img(env, x, y, ambient_color(obj->color));
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
