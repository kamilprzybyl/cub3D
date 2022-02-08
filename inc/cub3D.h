#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h> 
# include "../mlx/mlx.h"
# include "../Libft/libft.h"
# include "../get_next_line/get_next_line.h"

typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_img {
	void	*ptr_img;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}				t_img;

typedef struct s_cub
{
	t_img	img[4];
	char	*xpm[4];
	t_vars	vars;
	char	**map;
}				t_cub;

# define NORTH "../textures/NO.xpm"
# define SOUTH "../textures/SO.xpm"
# define WEST "../textures/WE.xpm"
# define EAST "../textures/EA.xpm"

int		parse(char **argv);
void	init(t_cub *cub, int fd, char **argv);

int		get_num_of_rows(char *file);

#endif