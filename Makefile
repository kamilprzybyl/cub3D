# CC		=	gcc
# CFLAGS	=	-Wall -Wextra -Werror -D BUFFER_SIZE=100
# NAME	=	cub3D
# MLX		=	mlx/libmlx.a
# MFLAGS	=	-framework OpenGL -framework AppKit
# LIBFT	=	Libft/libft.a
# INC		=	./inc/
# SRC		=	src/main.c \
# 			src/launch.c \
# 			src/parsing/parse.c \
# 			src/parsing/parse_info.c \
# 			src/parsing/parse_map.c \
# 			src/hooks/mouse.c \
# 			src/hooks/hooks.c \
# 			src/movement/move.c \
# 			src/movement/rotate.c \
# 			src/movement/quit.c \
# 			src/raycasting/drawingCeilingFloor.c \
# 			src/raycasting/post_dda_calcs.c \
# 			src/raycasting/pre_dda_calcs.c \
# 			src/raycasting/rc_and_dda.c \
# 			src/raycasting/tex_calc.c \
# 			src/raycasting/verticalDrawing.c \
# 			src/init/init.c \
# 			src/init/init_colors.c \
# 			src/init/init_textures.c \
# 			src/init/validate_map.c \
# 			src/utils/ft_free.c \
# 			src/utils/rgb_to_hex.c \
# 			src/utils/ft_arrlen.c \
# 			src/utils/ft_realloc.c \
# 			src/utils/get_ext.c \
# 			gnl/get_next_line.c \
# 			gnl/get_next_line_utils.c
# OBJ = 	$(SRC:.c=.o)

# all: $(NAME)

# %.o: %.c
# 	$(CC) -c $(CFLAGS) -I $(INC) $^ -o $@

# $(NAME): $(MLX) $(LIBFT) $(OBJ)
# 	$(CC) $(CFLAGS) $(LIBFT) $(MLX) $(MFLAGS) $^ -o $@

# $(MLX):
# 	make --directory=./mlx

# $(LIBFT):
# 	make --directory=./Libft

# clean:
# 	make clean --directory=./Libft
# 	rm -fr $(OBJ)

# fclean:
# 	make fclean --directory=./Libft
# 	make clean
# 	rm -fr $(NAME)

# re: fclean all

NAME = cub3D
CC = gcc
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=100
LIBS = -lmlx -lm -lft -L$(LIBFT_DIR) -L$(MLX_DIR) -framework OpenGL -framework AppKit
INCLUDES = -I$(HEADERS_DIR) -I$(LIBFT_HEADERS) -I$(MLX_HEADERS)

MLX		=	$(MLX_DIR)libmlx.a
MLX_DIR =	./mlx/
MLX_HEADERS = $(MLX_DIR)

LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR = ./Libft/
LIBFT_HEADERS = $(LIBFT_DIR)

HEADERS_LIST =	cub3D.h
HEADERS_DIR = ./inc/
HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))

SRC_DIR = ./src/
SRC_LIST =	main.c \
			launch.c \
			parsing/parse.c \
			parsing/parse_info.c \
			parsing/parse_map.c \
			hooks/mouse.c \
			hooks/hooks.c \
			movement/move.c \
			movement/rotate.c \
			movement/quit.c \
			raycasting/drawingCeilingFloor.c \
			raycasting/drawMinimap.c \
			raycasting/post_dda_calcs.c \
			raycasting/pre_dda_calcs.c \
			raycasting/rc_and_dda.c \
			raycasting/tex_calc.c \
			raycasting/verticalDrawing.c \
			init/init.c \
			init/init_colors.c \
			init/init_textures.c \
			init/init_check_chars.c \
			init/validate_map.c \
			utils/ft_free.c \
			utils/rgb_to_hex.c \
			utils/ft_arrlen.c \
			utils/ft_realloc.c \
			utils/get_ext.c \
			gnl/get_next_line.c \
			gnl/get_next_line_utils.c

SRC = $(addprefix $(SRC_DIR), $(SRC_LIST))

OBJ_DIR = ./obj/
OBJ_DIR_LIST =	$(OBJ_DIR)parsing \
				$(OBJ_DIR)hooks \
				$(OBJ_DIR)movement \
				$(OBJ_DIR)raycasting \
				$(OBJ_DIR)init \
				$(OBJ_DIR)utils \
				$(OBJ_DIR)gnl

OBJ_LIST = $(patsubst %.c, %.o, $(SRC_LIST))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_LIST))

.PHONY : all bonus clean fclean re

all : $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ_DIR) $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(LIBS) $(OBJ) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR_LIST)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@

$(LIBFT):
	$(MAKE) -sC $(LIBFT_DIR)

$(MLX):
	$(MAKE) -sC $(MLX_DIR)

bonus : all

clean :
	$(MAKE) -sC $(LIBFT_DIR) clean
	$(MAKE) -sC $(MLX_DIR) clean
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -f $(MLX)
	rm -f $(LIBFT)
	rm -f $(NAME)

re : fclean all