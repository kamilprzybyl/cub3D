/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_dda_calcs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:37:42 by mstrantz          #+#    #+#             */
/*   Updated: 2022/02/21 12:14:23 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

//Calculate distance of perpendicular ray (Euclidean dist gives fisheye effect!)
void	calc_dist_perp(void)
{
	if (data()->var.side == 0)
		data()->var.perp_wall_dist = \
			data()->var.side_dist_x - data()->var.delta_dist_x;
	else
		data()->var.perp_wall_dist = \
			data()->var.side_dist_y - data()->var.delta_dist_y;
}

//Calculate height of line to draw on screen
//added * 2, not part of the guide, but with j&a's version
void	calc_vertical_line_height(void)
{
	data()->var.line_height = \
		(int)(SCREEN_HEIGHT / data()->var.perp_wall_dist);
}

//calculate lowest and highest pixel to fill in current stripe
void	calc_draw_start_and_draw_end(void)
{
	int	draw_start;

	draw_start = (-1) * data()->var.line_height / 2 + SCREEN_HEIGHT / 2;
	data()->var.draw_start = draw_start;
	if (data()->var.draw_start < 0)
		data()->var.draw_start = 0;
	data()->var.draw_end = data()->var.line_height / 2 + SCREEN_HEIGHT / 2;
	if (data()->var.draw_end >= SCREEN_HEIGHT)
		data()->var.draw_end = SCREEN_HEIGHT - 1;
}
