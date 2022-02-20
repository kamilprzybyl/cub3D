/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_dda_calcs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:37:42 by mstrantz          #+#    #+#             */
/*   Updated: 2022/02/20 15:00:15 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

//Calculate distance of perpendicular ray (Euclidean dist gives fisheye effect!)
void	calc_dist_perp(void)
{
	if (data()->var.side == 0)
		data()->var.perpWallDist = \
			data()->var.sideDistX - data()->var.deltaDistX;
	else
		data()->var.perpWallDist = \
			data()->var.sideDistY - data()->var.deltaDistY;
}

//Calculate height of line to draw on screen
//added * 2, not part of the guide, but with j&a's version
void	calc_vertical_line_height(void)
{
	data()->var.lineHeight = \
		(int)(data()->var.sHeight / data()->var.perpWallDist);
}

//calculate lowest and highest pixel to fill in current stripe
void	calc_draw_start_and_draw_end(void)
{
	int	draw_start;

	draw_start = (-1) * data()->var.lineHeight / 2 + data()->var.sHeight / 2;
	data()->var.drawStart = draw_start;
	if (data()->var.drawStart < 0)
		data()->var.drawStart = 0;
	data()->var.drawEnd = data()->var.lineHeight / 2 + data()->var.sHeight / 2;
	if (data()->var.drawEnd >= data()->var.sHeight)
		data()->var.drawEnd = data()->var.sHeight - 1;
}
