/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_dda_calcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:33:55 by mstrantz          #+#    #+#             */
/*   Updated: 2022/02/19 19:25:02 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

//calculate ray position and direction
void	calc_ray_pos_and_dir(int x)
{
	data()->var.cameraX = 2 * x / (double) data()->var.sWidth - 1;
	data()->var.rayDirX = data()->var.dirX + \
							data()->var.planeX * data()->var.cameraX;
	data()->var.rayDirY = data()->var.dirY + \
							data()->var.planeY * data()->var.cameraX;
}

//which box of the map we're in
void	set_box_pos(void)
{
	data()->var.mapX = (int) data()->var.posX;
	data()->var.mapY = (int) data()->var.posY;
	data()->var.hit = 0;
}

//length of ray from one x or y-side to next x or y-side
void	calc_delta_dist(void)
{
	if (data()->var.rayDirX == 0)
		data()->var.deltaDistX = 1e30;
	else
		data()->var.deltaDistX = fabs(1 / data()->var.rayDirX);
	if (data()->var.rayDirY == 0)
		data()->var.deltaDistY = 1e30;
	else
		data()->var.deltaDistY = fabs(1 / data()->var.rayDirY);
}

//calculate step and initial sideDist
void	calc_step_and_side_dist(void)
{
	if (data()->var.rayDirX < 0)
	{
		data()->var.stepX = -1;
		data()->var.sideDistX = (data()->var.posX - data()->var.mapX) \
								* data()->var.deltaDistX;
	}
	else
	{
		data()->var.stepX = 1;
		data()->var.sideDistX = (data()->var.mapX + 1.0 - data()->var.posX) \
								* data()->var.deltaDistX;
	}
	if (data()->var.rayDirY < 0)
	{
		data()->var.stepY = -1;
		data()->var.sideDistY = (data()->var.posY - data()->var.mapY) \
								* data()->var.deltaDistY;
	}
	else
	{
		data()->var.stepY = 1;
		data()->var.sideDistY = (data()->var.mapY + 1.0 - data()->var.posY) \
								* data()->var.deltaDistY;
	}
}
