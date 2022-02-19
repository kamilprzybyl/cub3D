/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verticalDrawing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:38:33 by mstrantz          #+#    #+#             */
/*   Updated: 2022/02/19 19:25:43 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	my_mlx_pixel_put(int x, int y, int color)
{
	char	*dst;

	dst = data()->img[4].addr + \
		(y * data()->img[4].line_len + x * (data()->img[4].bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	set_color(void)
{
	int	elmnt;

	elmnt = data()->map[data()->var.mapY][data()->var.mapX];
	if (elmnt == '1')
		data()->var.color = 0x80FF00;
	if (data()->var.side == 1)
		data()->var.color = data()->var.color / 2;
}

void	draw_vertical_line(int x)
{
	int	y;

	y = data()->var.drawStart;
	while (y < data()->var.drawEnd)
	{
		my_mlx_pixel_put(x, y, data()->var.color);
		y++;
	}
}
