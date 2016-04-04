#include "RT.h"
#include <stdlib.h>

#include "libft.h"

int	key_hook(int keycode, t_env *env)
{
	if (keycode == 53)
	{
		mlx_destroy_image(env->mlx, env->img);
		exit(1);
	}
	return (1);
}

int main()
{
	t_env	env;
	t_scene	*scene;

	scene = NULL;
	init_env(&env);
	init_scene(&scene);
	scan_scene(&env, scene);
	mlx_hook(env.win, 2, 4, key_hook, &env);
	mlx_loop(env.mlx);
	return (0);
}
