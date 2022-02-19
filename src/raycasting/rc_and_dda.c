/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_and_dda.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:51:12 by mstrantz          #+#    #+#             */
/*   Updated: 2022/02/19 19:26:37 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

//DigitalDifferentialAlgorithm
	//jump to next map square, either in x-direction, or in y-direction
	//Check if ray has hit a wall
void	dda(void)
{
	while (data()->var.hit == 0)
	{
		if (data()->var.sideDistX < data()->var.sideDistY)
		{
			data()->var.sideDistX += data()->var.deltaDistX;
			data()->var.mapX += data()->var.stepX;
			data()->var.side = 0;
		}
		else
		{
			data()->var.sideDistY += data()->var.deltaDistY;
			data()->var.mapY += data()->var.stepY;
			data()->var.side = 1;
		}
		if (data()->map[data()->var.mapY][data()->var.mapX] == '1')
			data()->var.hit = 1;
	}
}

void	raycast_loop(void)
{
	int	x;

	x = 0;
	while (x < data()->var.sWidth)
	{
		calc_ray_pos_and_dir(x);
		set_box_pos();
		calc_delta_dist();
		calc_step_and_side_dist();
		dda();
		calc_dist_perp();
		calc_vertical_line_height();
		calc_draw_start_and_draw_end();
		set_color();
		draw_vertical_line(x);
		x++;
	}
}
