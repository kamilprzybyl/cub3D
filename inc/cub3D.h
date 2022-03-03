/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprzybyl <kprzybyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 11:50:04 by mstrantz          #+#    #+#             */
/*   Updated: 2022/03/03 15:57:16 by kprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "../Libft/inc/libft.h"
# include "../src/gnl/get_next_line.h"

# define SCREEN_HEIGHT 			512
# define SCREEN_WIDTH 			512
# define TEX_HEIGHT 			64
# define TEX_WIDTH 				64
# define WALL					0x00F0F0F0
# define WALKABLE				0x00000000
# define PLAYER					0x00FF0000
# define ESC 					53
# define W 						13
# define A 						0
# define S 						1
# define D 						2
# define UP 					126
# define DOWN 					125
# define LEFT 					123
# define RIGHT 					124
# define P 						35
# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_EXIT			17

typedef struct s_var {
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			time;
	double			old_time;
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	int				tex_width;
	int				tex_height;
	int				tex_num;
	double			wall_x;
	double			step;
	double			tex_pos;
	int				tex_y;
	int				tex_x;
	unsigned int	color;
	double			frame_time;
	double			move_speed;
	double			rot_speed;
}			t_var;

typedef struct s_var_minimap {
	int	width;
	int	height;
	int	pix_x;
	int	pix_y;
}	t_var_minimap;

//for screen
typedef struct s_img {
	void	*ptr_img;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}				t_img;

//for textures
typedef struct s_img2 {
	void	*ptr_img;
	int		*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}				t_img2;

typedef struct s_key
{
	int	w;
	int	s;
	int	a;
	int	d;
	int	right;
	int	left;
	int	p;
}				t_key;

typedef struct s_cub
{
	void			*mlx;
	void			*win;
	t_img			img;
	t_img2			img2[4];
	char			**rgb;
	char			**xpm;
	char			**map;
	unsigned long	floor;
	unsigned long	ceilling;
	t_var			var;
	t_var_minimap	var_mm;
	int				texture[4][TEX_HEIGHT * TEX_WIDTH];
	t_key			key;
	char			mouse;
}				t_cub;

t_cub			*data(void);

int				parse(char *file);
int				parse_info(int fd);
int				parse_map(int fd);

void			init(void);
int				init_colors(void);
int				init_textures(void);
int				check_chars(void);
int				validate_map(void);

void			calc_ray_pos_and_dir(int x);
void			set_box_pos(void);
void			calc_delta_dist(void);
void			calc_step_and_side_dist(void);

void			dda(void);
void			raycast_loop(void);

void			calc_dist_perp(void);
void			calc_vertical_line_height(void);
void			calc_draw_start_and_draw_end(void);

void			calc_tex_x(void);
void			draw_vertical_texture_stripe(int x);

void			my_mlx_pixel_put(int x, int y, int color);
void			set_color(void);
void			draw_vertical_line(int x);

void			draw_floor(void);
void			draw_ceiling(void);

void			draw_minimap(void);

int				launch(void);

void			hooks(void);
int				key_press(int keycode);
int				key_release(int keycode);
int				mouse_hook(void);

void			rotate_left(void);
void			rotate_right(void);
void			move_forward(void);
void			move_backwards(void);
void			move_left(void);
void			move_right(void);
int				quit(void);

void			ft_free(char ***arr);
unsigned long	rgb_to_hex(int r, int g, int b);
int				ft_arrlen(char **arr);
char			**ft_realloc(char **ptr, int size);
const char		*get_ext(const char *file);

#endif
