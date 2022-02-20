/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 11:19:04 by mstrantz          #+#    #+#             */
/*   Updated: 2022/02/20 18:22:39 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

//calculate value of wallX
//x coordinate on the texture
void	calc_texX(void)
{
	// data()->var.texNum = data()->map[data()->var.mapY][data()->var.mapX] - 48;
	// printf("texNum = %d\n", data()->var.texNum);
	if (data()->var.side == 0)
		data()->var.wallX = data()->var.posY + \
			data()->var.perpWallDist * data()->var.rayDirY;
	else
		data()->var.wallX = data()->var.posX + \
			data()->var.perpWallDist * data()->var.rayDirX;
	data()->var.wallX -= floor(data()->var.wallX);
	data()->var.texX = (int)(data()->var.wallX * (double)TEX_WIDTH);
	if (data()->var.side == 0 && data()->var.rayDirX > 0)
		data()->var.texX = TEX_WIDTH - data()->var.texX - 1;
	if (data()->var.side == 1 && data()->var.rayDirY < 0)
		data()->var.texX = TEX_WIDTH - data()->var.texX - 1;
}

void	draw_vertical_texture_stripe(int x)
{
	double	step;
	double	texPos;
	int		y;

	step = 1.0 * TEX_HEIGHT / data()->var.lineHeight;
	texPos = (data()->var.drawStart - SCREEN_HEIGHT / 2 \
		+ data()->var.lineHeight / 2) * step;
	y = data()->var.drawStart;
	while (y < data()->var.drawEnd)
	{
		data()->var.texY = (int) texPos & (TEX_HEIGHT - 1);
		texPos += step;
		data()->var.color = data()->texture[data()->var.texNum][TEX_HEIGHT \
			* data()->var.texY + data()->var.texX];
		if (data()->var.side == 1)
			data()->var.color = (data()->var.color >> 1) & 8355711;//data()->var.color /= 2;
		my_mlx_pixel_put(x, y, data()->var.color);
		y++;
	}
}