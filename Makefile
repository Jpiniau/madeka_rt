NAME = rtv1

SRC_REP = src

SRC_FILE = cos2.c\
		   distance.c\
		   dot_product.c\
		   ft_pixel_to_img.c\
		   init_circle.c\
		   init_coord.c\
		   init_cylinder.c\
		   init_cone.c\
		   init_env.c\
		   init_img.c\
		   init_plane.c\
		   init_ray.c\
		   init_shadow_ray.c\
		   init_scene.c\
		   init_vec3.c\
		   intersect_circle.c\
		   intersect_cylinder.c\
		   intersect_cone.c\
		   intersect_object.c\
		   intersect_plane.c\
		   intersect_point.c\
		   intersect_shadow.c\
		   intersect_light.c\
		   main.c\
		   normalize.c\
		   scan_scene.c\
		   sin2.c\
		   tan2.c\
		   get_normal.c

SRC = $(addprefix $(SRC_REP)/,$(SRC_FILE))

LIBFT = -L libft/ -lft -lm

MINILIBX = -lmlx -framework OpenGl -framework AppKit

FLAGS = -Wall -Werror -Wextra

OBJ_REP = obj

OBJ_FILE = $(SRC_FILE:.c=.o)

OBJ = $(addprefix $(OBJ_REP)/,$(OBJ_FILE))

INC_REP = includes

INC = -I $(INC_REP) -I libft/includes

all: lib $(NAME)


lib:
	make -C libft/

$(NAME) : $(OBJ)
	clang $(FLAGS) -o $(NAME) $(LIBFT) $(MINILIBX) $^

$(OBJ_REP)/%.o: $(SRC_REP)/%.c $(INC_REP)/RT.h
	@mkdir $(OBJ_REP) 2> /dev/null || true
	clang $(FLAGS) $(INC) -o $@ -c $<

clean:
	rm -rf $(OBJ)
	make -C libft/ clean
	@rmdir $(OBJ_REP) 2> /dev/null || true

fclean: clean
	rm -rf $(NAME)
	make -C libft/ fclean

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC_REP)/*.h

