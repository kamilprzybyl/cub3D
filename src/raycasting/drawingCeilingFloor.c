/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawingCeilingFloor.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:48:40 by mstrantz          #+#    #+#             */
/*   Updated: 2022/02/20 15:15:28 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	draw_floor(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < data()->var.sWidth)
	{
		j = data()->var.sHeight / 2 - 1;
		while (++j < data()->var.sHeight)
		{
			my_mlx_pixel_put(i, j, data()->floor);
		}
		i++;
	}
}

void	draw_ceiling(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < data()->var.sWidth)
	{
		j = -1;
		while (++j < data()->var.sHeight / 2)
		{
			my_mlx_pixel_put(i, j, data()->ceilling);
		}
		i++;
	}
}
