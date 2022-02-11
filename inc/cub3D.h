#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h> 
# include "../mlx/mlx.h"
# include "../Libft/libft.h"
# include "../get_next_line/get_next_line.h"

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
	void			*mlx;
	void			*win;
	t_img			img[4];
	char			**xpm;
	char			**map;
	unsigned long	floor;
	unsigned long	ceilling;
}				t_cub;

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

t_cub	*data(void);
int		parse(int fd);
void	init();
int		key_hook(int keycode, void *unused);
int		mouse_events(int keycode);

void			ft_free(char **arr);
unsigned long	rgb_to_hex(int r, int g, int b);

#endif