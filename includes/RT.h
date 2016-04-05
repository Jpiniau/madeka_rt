#ifndef RT_H
# define RT_H

#include <mlx.h>

# define	WIDTH	800
# define	HEIGHT	640

enum	e_object{CIRCLE, PLANE, CYLINDER, CONE};

typedef	struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			bpp;
	int			sizeline;
	int			endian;
}				t_env;

typedef struct	s_vec3
{
	float	x;
	float	y;
	float	z;
}				t_vec3;

typedef struct	s_coord
{
	float	x;
	float	y;
	float	z;
}				t_coord;

typedef struct	s_ray
{
	t_coord		o;
	t_vec3		d;
}				t_ray;

typedef struct	s_circle
{
	t_coord			center;
	float			r;
}				t_circle;

typedef struct	s_plane
{
	t_coord			p;
	t_vec3			n;
}				t_plane;

typedef struct	s_cylinder
{
	t_coord		center;
	t_vec3		n;
	float		r;
}				t_cylinder;

typedef struct	s_cone
{
	t_coord		center;
	t_vec3		n;
	float		r;
}				t_cone;

typedef struct	s_light
{
	t_coord		center;
	int			power;
}				t_light;

typedef struct			s_scene
{
	enum	e_object	type;
	void				*object;
	unsigned int		color;
	struct s_scene		*next;
}						t_scene;


float			cos2(float x);
float			distance(t_vec3 *a);
float			dot_product(t_vec3 *a, t_vec3 *b);
void			ft_pixel_to_img(t_env *env, int x, int y, int color);
void			init_coord(t_coord *coord, float x, float y, float z);
void			init_env(t_env *env);
void			init_img(t_env *env);
void			init_object(t_scene **scene, enum e_object type);
void			init_ray(t_ray *ray, int x, int y);
void			init_shadow_ray(t_ray *ray, t_coord light, t_coord point);
void			init_scene(t_scene **scene);
void			init_plane(t_scene **scene, t_coord p, t_vec3 n, unsigned int color);
void			init_circle(t_scene **scene, t_coord center, unsigned int color, float radius);
void			init_cylinder(t_scene **scene, t_coord center, t_vec3 n, float r, unsigned int color);
void			init_cone(t_scene **scene, t_coord center, t_vec3 n, unsigned int color);
void			init_vec3(t_vec3 *v, float x, float y, float z);
float			intersect_circle(t_ray *ray, t_circle *circle);
float			intersect_cylinder(t_ray *ray, t_cylinder *cylinder);
float			intersect_cone(t_ray *ray, t_cone *cone);
t_scene			*intersect_object(t_ray *ray, t_scene *scene, t_coord *point);
float			intersect_plane(t_ray *ray, t_plane *plane);
int				intersect_shadow(float t, t_scene *scene, t_ray *ray);
int				intersect_light(t_coord point, t_ray *ray, t_scene *obj, t_light light);
float			intersect_point(float a, float b, float delta);
void			normalize(t_vec3 *a);
void			scan_scene(t_env *env, t_scene *scene);
float			sin2(float x);
float			tan2(float x);

#endif
