#include "RT.h"
#include "math.h"

void	init_ray(t_ray *ray, int x, int y)
{
	float	ratio;
	float	px;
	float	py;
	int		fov;

	fov = 40;
	ratio = WIDTH / (float)HEIGHT;
	px = (2 * ((x + 0.5) / WIDTH) - 1) * tan(fov /(float)2 * M_PI /(float)180) * ratio;
	py = (1 - 2 * (y + 0.5) / HEIGHT) * tan(fov / 2 * M_PI / 180);
	init_coord(&(ray->o), 0, 0, 0);
	init_vec3(&(ray->d), px, py, -1);
	normalize(&(ray->d));
}
