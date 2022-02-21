/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 11:19:04 by mstrantz          #+#    #+#             */
/*   Updated: 2022/02/21 12:50:45 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

//calculate value of wallX
//x coordinate on the texture
void	calc_tex_x(void)
{
	if (data()->var.side == 0)
		data()->var.wall_x = data()->var.pos_y + \
			data()->var.perp_wall_dist * data()->var.ray_dir_y;
	else
		data()->var.wall_x = data()->var.pos_x + \
			data()->var.perp_wall_dist * data()->var.ray_dir_x;
	data()->var.wall_x -= floor(data()->var.wall_x);
	data()->var.tex_x = (int)(data()->var.wall_x * (double)TEX_WIDTH);
	if (data()->var.side == 0 && data()->var.ray_dir_x > 0)
		data()->var.tex_x = TEX_WIDTH - data()->var.tex_x - 1;
	if (data()->var.side == 1 && data()->var.ray_dir_y < 0)
		data()->var.tex_x = TEX_WIDTH - data()->var.tex_x - 1;
}

void	draw_vertical_texture_stripe(int x)
{
	double	step;
	double	tex_pos;
	int		y;

	step = 1.0 * TEX_HEIGHT / data()->var.line_height;
	tex_pos = (data()->var.draw_start - SCREEN_HEIGHT / 2 \
		+ data()->var.line_height / 2) * step;
	y = data()->var.draw_start;
	while (y < data()->var.draw_end)
	{
		data()->var.tex_y = (int) tex_pos & (TEX_HEIGHT - 1);
		tex_pos += step;
		data()->var.color = data()->texture[data()->var.tex_num][TEX_HEIGHT \
			* data()->var.tex_y + data()->var.tex_x];
		if (data()->var.side == 1)
			data()->var.color = (data()->var.color >> 1) & 8355711;
		my_mlx_pixel_put(x, y, data()->var.color);
		y++;
	}
}
