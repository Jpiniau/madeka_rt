#include "RT.h"

void	ft_pixel_to_img(t_env *env, int x, int y, int color)
{
	unsigned int	bytes;
	unsigned int	d;
	unsigned int	j;

	bytes = env->bpp / 8;
	d = x * bytes + y *env->sizeline;
	j = -1;
	while (++j < bytes)
	{
		env->data[d + j] = color;
		color >>= 8;
	}
}
