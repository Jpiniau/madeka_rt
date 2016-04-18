#include "RT.h"
#include "libft.h"

#include <stdio.h>

void	init_scene(t_scene **scene)
{
	t_coord	coord;
	t_vec3	v;

	init_coord(&coord, 0, 0, -50);
	init_vec3(&v, 0, 0, 1);
	//init_plane(scene, coord, v, 0x0000FF);

	init_coord(&coord, 0, -3, 0);
	init_vec3(&v, 0, 1, 0);
	init_plane(scene, coord, v, 0x00FF66);
	
	init_coord(&coord, -5, 4, -21);
	init_circle(scene, coord, 0xFFFFFF, 4);

	init_coord(&coord, 0, 4, -21);
	init_circle(scene, coord, 0xFF0000, 2);

	init_coord(&coord, 5, 2, -25);
	init_vec3(&v, 0, 0, 1);
	init_cylinder(scene, coord, v, 2, 0x0000FF);
	
	init_coord(&coord, -10, -2, -25);
	init_vec3(&v, 0, 0, 1);
	init_cone(scene, coord, v, 0x00FFFF);
}
