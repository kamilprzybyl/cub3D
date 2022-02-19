/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawingCeilingFloor.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:48:40 by mstrantz          #+#    #+#             */
/*   Updated: 2022/02/19 19:19:56 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	draw_floor(void)
{
	int	i;
	int	j;
	int	color;

	color = 0x808080;
	i = 0;
	while (i < data()->var.sWidth)
	{
		j = data()->var.sHeight / 2 - 1;
		while (++j < data()->var.sHeight)
		{
			my_mlx_pixel_put(i, j, color);
		}
		i++;
	}
}

void	draw_ceiling(void)
{
	int	i;
	int	j;
	int	color;

	color = 0x00FFFF;
	i = 0;
	while (i < data()->var.sWidth)
	{
		j = -1;
		while (++j < data()->var.sHeight / 2)
		{
			my_mlx_pixel_put(i, j, color);
		}
		i++;
	}
}
