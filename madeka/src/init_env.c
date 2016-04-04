#include "RT.h"
#include <stdlib.h>

static void	mlx_init_all(t_env *env, char *win_name)
{
	env->mlx = mlx_init();
	if (env->mlx == NULL)
		exit(-1);
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, win_name);
	if (env->win == NULL)
		exit(-1);
	init_img(env);
}

void	init_env(t_env *env)
{
	mlx_init_all(env, "RTv1");
}
