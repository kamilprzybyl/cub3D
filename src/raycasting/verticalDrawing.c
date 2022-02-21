/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verticalDrawing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:38:33 by mstrantz          #+#    #+#             */
/*   Updated: 2022/02/21 10:48:12 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	my_mlx_pixel_put(int x, int y, int color)
{
	char	*dst;

	dst = data()->img.addr + \
		(y * data()->img.line_len + x * (data()->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
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
