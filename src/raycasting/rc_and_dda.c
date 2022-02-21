/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_and_dda.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:51:12 by mstrantz          #+#    #+#             */
/*   Updated: 2022/02/21 14:49:06 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

//side == 0 x side of wall was hit, side == 1 -> y side;
void	set_texture(void)
{
	if (data()->var.side == 0)
	{
		if (data()->var.map_x > data()->var.pos_x)
			data()->var.tex_num = 1;
		else
			data()->var.tex_num = 3;
	}
	else
	{
		if (data()->var.map_y > data()->var.pos_y)
			data()->var.tex_num = 2;
		else
			data()->var.tex_num = 0;
	}
}

//DigitalDifferentialAlgorithm
	//jump to next map square, either in x-direction, or in y-direction
	//Check if ray has hit a wall
void	dda(void)
{
	while (data()->var.hit == 0)
	{
		if (data()->var.side_dist_x < data()->var.side_dist_y)
		{
			data()->var.side_dist_x += data()->var.delta_dist_x;
			data()->var.map_x += data()->var.step_x;
			data()->var.side = 0;
		}
		else
		{
			data()->var.side_dist_y += data()->var.delta_dist_y;
			data()->var.map_y += data()->var.step_y;
			data()->var.side = 1;
		}
		if (data()->map[data()->var.map_y][data()->var.map_x] == '1')
		{
			data()->var.hit = 1;
			set_texture();
		}
	}
}

void	raycast_loop(void)
{
	int	x;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		calc_ray_pos_and_dir(x);
		set_box_pos();
		calc_delta_dist();
		calc_step_and_side_dist();
		dda();
		calc_dist_perp();
		calc_vertical_line_height();
		calc_draw_start_and_draw_end();
		calc_tex_x();
		draw_vertical_texture_stripe(x);
		x++;
	}
}
