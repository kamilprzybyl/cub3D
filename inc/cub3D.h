#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "../Libft/libft.h"
# include "../gnl/get_next_line.h"

typedef struct s_var {

	double	posX; //x start position
	double	posY; //y start position
	double	dirX; //initial direction vector x component
	double	dirY; //initial direction vector y component
	double	planeX; // camera plane x component
	double	planeY; // camera plane y component

	double	time; //time of current frame
	double	oldTime; //time of previous frame

	//calculate ray position and direction
	double	cameraX; //x-coordinate in camera space
	double	rayDirX;
	double	rayDirY;

	//which box of the map we're in
	int		mapX;
	int		mapY;

	//length of ray form current position to next x- or y-side
	double	sideDistX;
	double	sideDistY;

	//length of ray from one x or y-side to next x or y-side
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;

	//what direction to step in x or y-direction (either +1 or -1)
	int		stepX;
	int		stepY;

	//wall hit? which side?
	int		hit;
	int		side;

	//calculate height of line to draw on screen
	int		lineHeight;

	//calculate lowest and highest pixel to fill in current stripe
	int		drawStart;
	int		drawEnd;

	//choose wall color
	//..

	//timing for input and FPS counter
	double	frameTime; //time this frame has taken, in seconds

	//speed modifiers
	double	moveSpeed; //constant value is in squares/second
	double	rotSpeed; //constant value is in radians/second
}			t_var;

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
	char			*xpm[5];
	char			*rgb[3];
	char			**map;
	unsigned long	floor;
	unsigned long	ceilling;
	t_var			var;
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

# define screenWidth 640

t_cub			*data(void);

int				parse(char *file);
int				parse_info(int fd);
int				parse_map(int fd);

void			init();
int				init_colors(void);
int				init_textures(void);
int				validate_map(void);

void			launch(void);
int				key_hook(int keycode, void *unused);
int				mouse_events(int keycode);

void			ft_free(char **arr);
unsigned long	rgb_to_hex(int r, int g, int b);
int				ft_arrlen(char **arr);
char			**ft_realloc(char **ptr, int size);
const char		*get_ext(const char *file);

#endif