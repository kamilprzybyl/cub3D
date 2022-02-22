/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:53:42 by mstrantz          #+#    #+#             */
/*   Updated: 2022/02/21 20:52:43 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	launch(void)
{
	void	*img;
	char	*addr;

	img = mlx_new_image(data()->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	data()->img.ptr_img = img;
	addr = mlx_get_data_addr(data()->img.ptr_img, \
		&data()->img.bits_per_pixel, &data()->img.line_len, \
		&data()->img.endian);
	data()->img.addr = addr;
	draw_floor();
	draw_ceiling();
	raycast_loop();
	draw_minimap();
	hooks();
	data()->var.frame_time = 16 / 1000.0;
	data()->var.move_speed = data()->var.frame_time * 5.0;
	data()->var.rot_speed = data()->var.frame_time * 3.0;
	mlx_put_image_to_window(data()->mlx, data()->win, \
		data()->img.ptr_img, 0, 0);
	mlx_destroy_image(data()->mlx, data()->img.ptr_img);
	return (0);
}
