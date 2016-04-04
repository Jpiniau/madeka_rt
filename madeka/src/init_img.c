#include "RT.h"
#include <stdlib.h>


void	init_img(t_env *env)
{
	char	*data;
	int		bpp;
	int		sizeline;
	int		endian;

	env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	if (env->img == NULL)
		exit(-1);
	data = mlx_get_data_addr(env->img, &bpp, &sizeline, &endian);
	env->data = data;
	env->bpp = bpp;
	env->sizeline = sizeline;
	env->endian = endian;

}
