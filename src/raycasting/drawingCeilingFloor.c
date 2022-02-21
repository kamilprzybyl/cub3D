/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawingCeilingFloor.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:48:40 by mstrantz          #+#    #+#             */
/*   Updated: 2022/02/21 12:11:17 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	draw_floor(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < SCREEN_WIDTH)
	{
		j = SCREEN_HEIGHT / 2 - 1;
		while (++j < SCREEN_HEIGHT)
			my_mlx_pixel_put(i, j, data()->floor);
		i++;
	}
}

void	draw_ceiling(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < SCREEN_WIDTH)
	{
		j = -1;
		while (++j < SCREEN_HEIGHT / 2)
			my_mlx_pixel_put(i, j, data()->ceilling);
		i++;
	}
}
