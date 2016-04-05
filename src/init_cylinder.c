#include "RT.h"
#include "libft.h"
#include <stdlib.h>

void	init_cylinder(t_scene **scene, t_coord center, t_vec3 n, float r, unsigned int color)
{
	t_cylinder	*cylinder;
	t_scene		*new_obj;

	cylinder = (t_cylinder *)malloc(sizeof(t_cylinder));
	new_obj = (t_scene *)malloc(sizeof(t_scene));
	if (cylinder == NULL || new_obj == NULL)
	{
		ft_putendl_fd("Fatal error : Failed malloc in init_cylinder", 2);
		exit(-1);
	}
	init_coord(&cylinder->center, center.x, center.y, center.z);
	normalize(&n);
	init_vec3(&cylinder->n, n.x, n.y, n.z);
	cylinder->r = r;
	new_obj->type = CYLINDER;
	new_obj->object = cylinder;
	new_obj->next = *scene;
	new_obj->color = color;
	*scene = new_obj;
}
