#include "libft.h"
#include "RT.h"
#include <stdlib.h>

void	init_object(t_scene **scene, enum e_object type)
{
	t_coord		coord;
	t_scene		*obj;

	init_coord(&coord, 233, 236, 0);
	obj = (t_scene *)malloc(sizeof(t_scene));
	if (obj == NULL)
	{
		ft_putendl_fd("Fatal error : Failed malloc in init_object", 2);
		exit(-1);
	}
	if (type == CIRCLE)
	{
		obj->type = type;
		obj->object = init_circle(coord, 0xFF0000, 200);
	}
	else
	{
		free(obj);
		return ;
	}
	obj->next = *scene;
	*scene = obj;
}
