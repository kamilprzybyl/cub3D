FLAGS	=	-Wall -Wextra -Werror ./Libft/libft.a -L ./mlx -lmlx -framework OpenGL -framework AppKit
NAME	=	cub3D
MLX		=	mlx/libmlx.a
LIBFT	=	Libft/libft.a
SRC		=	main.c

OBJ = 	$(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	gcc -c -Wall -Werror -Wextra -D BUFFER_SIZE=100 $^ -o $@

$(NAME): $(MLX) $(LIBFT) $(OBJ)
	gcc $(FLAGS) $^ -o $@

$(MLX):
	make --directory=./mlx

$(LIBFT):
	make --directory=./Libft

clean:
	rm -fr $(OBJ)

fclean:
	make clean
	rm -fr $(NAME)

re: fclean all