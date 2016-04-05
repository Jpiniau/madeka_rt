#include "RT.h"
#include "libft.h"
#include <stdlib.h>

void	init_plane(t_scene **scene, t_coord p, t_vec3 n, unsigned int color)
{
	t_plane	*plane;
	t_scene	*new_obj;

	plane = (t_plane *)malloc(sizeof(t_plane));
	new_obj = (t_scene *)malloc(sizeof(t_scene));
	if (plane == NULL || new_obj == NULL)
	{
		ft_putendl_fd("Fatal error : Failed malloc in init_plane", 2);
		exit(-1);
	}
	init_coord(&plane->p, p.x, p.y, p.z);
	normalize(&n);
	init_vec3(&plane->n, n.x, n.y, n.z);
	new_obj->type = PLANE;
	new_obj->object = plane;
	new_obj->color = color;
	new_obj->next = *scene;
	*scene = new_obj;
}
