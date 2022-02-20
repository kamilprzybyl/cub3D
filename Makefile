CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -D BUFFER_SIZE=100
NAME	=	cub3D
MLX		=	mlx/libmlx.a
MFLAGS	=	-framework OpenGL -framework AppKit
LIBFT	=	Libft/libft.a
INC		=	./inc/
SRC		=	src/main.c \
			src/launch.c \
			src/parsing/parse.c \
			src/parsing/parse_info.c \
			src/parsing/parse_map.c \
			src/hooks/mouse.c \
			src/hooks/hooks.c \
			src/movement/move.c \
			src/movement/rotate.c \
			src/movement/quit.c \
			src/raycasting/drawingCeilingFloor.c \
			src/raycasting/post_dda_calcs.c \
			src/raycasting/pre_dda_calcs.c \
			src/raycasting/rc_and_dda.c \
			src/raycasting/tex_calc.c \
			src/raycasting/verticalDrawing.c \
			src/init/init.c \
			src/init/init_colors.c \
			src/init/init_textures.c \
			src/init/validate_map.c \
			src/utils/ft_free.c \
			src/utils/rgb_to_hex.c \
			src/utils/ft_arrlen.c \
			src/utils/ft_realloc.c \
			src/utils/get_ext.c \
			gnl/get_next_line.c \
			gnl/get_next_line_utils.c
OBJ = 	$(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) -I $(INC) $^ -o $@

$(NAME): $(MLX) $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(LIBFT) $(MLX) $(MFLAGS) $^ -o $@

$(MLX):
	make --directory=./mlx

$(LIBFT):
	make --directory=./Libft

clean:
	make clean --directory=./Libft
	rm -fr $(OBJ)

fclean:
	make fclean --directory=./Libft
	make clean
	rm -fr $(NAME)

re: fclean all