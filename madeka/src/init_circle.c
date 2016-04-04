#include "RT.h"
#include "libft.h"
#include <stdlib.h>

void	init_circle(t_scene **scene, t_coord center, unsigned int color, float radius)
{
	t_circle	*circle;
	t_scene		*new_obj;

	circle = (t_circle *)malloc(sizeof(t_circle));
	new_obj = (t_scene *)malloc(sizeof(t_scene));
	if (circle == NULL || new_obj == NULL)
	{
		ft_putendl_fd("Fatal error : Failed malloc in init_circle", 2);
		exit(-1);
	}
	init_coord(&circle->center, center.x, center.y, center.z);
	circle->r = radius;
	new_obj->type = CIRCLE;
	new_obj->object = circle;
	new_obj->color = color;
	new_obj->next = *scene;
	*scene = new_obj;
}
