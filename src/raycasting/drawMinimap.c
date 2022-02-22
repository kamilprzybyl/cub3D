/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawMinimap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 19:51:36 by mstrantz          #+#    #+#             */
/*   Updated: 2022/02/22 12:20:00 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

//loops over pixels to draw
static void	draw_element(int color, int pixels_x, int pixels_y)
{
	int	i;
	int	j;
	int	tmp_x;
	int	tmp_y;

	tmp_y = data()->var_mm.pix_y;
	i = 0;
	while (i < pixels_y)
	{
		j = 0;
		tmp_x = data()->var_mm.pix_x;
		while (j < pixels_x)
		{
			my_mlx_pixel_put(tmp_x, tmp_y, color);
			tmp_x++;
			j++;
		}
		tmp_y++;
		i++;
	}
}

static void	select_minimap_element(int n_pixel_x, int n_pixel_y)
{
	char	e;

	e = data()->map[data()->var_mm.height][data()->var_mm.width];
	if (e == '1')
		draw_element(WALL, n_pixel_x, n_pixel_y);
	else if (e == '0' || e == 'N' || e == 'E' || e == 'S' || e == 'W')
		draw_element(WALKABLE, n_pixel_x, n_pixel_y);
	if (data()->var_mm.height == (int) data()->var.pos_y \
		&& data()->var_mm.width == (int) data()->var.pos_x)
		draw_element(PLAYER, n_pixel_x, n_pixel_y);
}

//loops over elements in map
void	draw_minimap(void)
{
	int	n_pixel_x;
	int	n_pixel_y;

	n_pixel_x = SCREEN_WIDTH / 100;
	n_pixel_y = SCREEN_HEIGHT / 100;
	data()->var_mm.height = 0;
	data()->var_mm.pix_y = 0;
	while (data()->map[data()->var_mm.height])
	{
		data()->var_mm.width = 0;
		data()->var_mm.pix_x = 0;
		while (data()->map[data()->var_mm.height][data()->var_mm.width])
		{
			select_minimap_element(n_pixel_x, n_pixel_y);
			data()->var_mm.pix_x += n_pixel_x;
			data()->var_mm.width++;
		}
		data()->var_mm.pix_y += n_pixel_y;
		data()->var_mm.height++;
	}
}
