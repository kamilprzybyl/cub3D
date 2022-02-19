/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:53:42 by mstrantz          #+#    #+#             */
/*   Updated: 2022/02/19 19:20:32 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	launch(void)
{
	void	*img;
	char	*addr;

	img = mlx_new_image(data()->mlx, data()->var.sWidth, data()->var.sHeight);
	data()->img[4].ptr_img = img;
	addr = mlx_get_data_addr(data()->img[4].ptr_img, \
		&data()->img[4].bits_per_pixel, &data()->img[4].line_len, \
		&data()->img[4].endian);
	data()->img[4].addr = addr;
	draw_floor();
	draw_ceiling();
	raycast_loop();
	mlx_put_image_to_window(data()->mlx, data()->win, \
		data()->img[4].ptr_img, 0, 0);
	mlx_destroy_image(data()->mlx, data()->img[4].ptr_img);
	return (0);
}
	//timing for input and FPS counter
	//data()->var.oldTime =  data()->var.time;
	//data()->var.time = function_to_get_time(?)
	//data()->var.frameTime = (data()->var.time - data()->var.oldTime) / 1000.0;
	//printf(1.0 / data()->var.frameTime);

	//speed modifiers
	//data()->var.moveSpeed = data()->var.frameTime * 5.0;
	//data()->var.rotSpeed = data()->var.frameTime * 3.0;
