#include "RT.h"
#include "libft.h"
#include <stdlib.h>

void	init_cone(t_scene **scene, t_coord center, t_vec3 n, unsigned int color)
{
	t_cone	*cone;
	t_scene		*new_obj;

	cone = (t_cone *)malloc(sizeof(t_cone));
	new_obj = (t_scene *)malloc(sizeof(t_scene));
	if (cone == NULL || new_obj == NULL)
	{
		ft_putendl_fd("Fatal error : Failed malloc in init_cone", 2);
		exit(-1);
	}
	init_coord(&cone->center, center.x, center.y, center.z);
	normalize(&n);
	init_vec3(&cone->n, n.x, n.y, n.z);
	new_obj->type = CONE;
	new_obj->object = cone;
	new_obj->next = *scene;
	new_obj->color = color;
	*scene = new_obj;
}
