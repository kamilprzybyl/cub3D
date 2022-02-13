FLAGS	=	-Wall -Wextra -Werror ./Libft/libft.a -L ./mlx -lmlx -framework OpenGL -framework AppKit
NAME	=	cub3D
MLX		=	mlx/libmlx.a
LIBFT	=	Libft/libft.a
SRC		=	src/main.c \
			src/mouse.c \
			src/hooks.c \
			src/parsing/parse.c \
			src/parsing/parse_info.c \
			src/parsing/parse_map.c \
			src/utils/ft_free.c \
			src/utils/rgb_to_hex.c \
			src/utils/ft_arrlen.c \
			src/utils/ft_realloc.c \
			src/init/init.c \
			src/init/init_colors.c \
			src/init/init_textures.c \
			src/init/validate_map.c \
			get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c
OBJ = 	$(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	gcc -c -Wall -Werror -Wextra -I ./inc/ -D BUFFER_SIZE=100 $^ -o $@

$(NAME): $(MLX) $(LIBFT) $(OBJ)
	gcc $(FLAGS) $^ -o $@

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