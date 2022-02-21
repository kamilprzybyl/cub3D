/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 17:02:42 by kprzybyl          #+#    #+#             */
/*   Updated: 2022/02/21 12:07:04 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	move_forward(void)
{
	int	y;
	int	x;

	y = (int)data()->var.pos_y;
	x = (int)(data()->var.pos_x + data()->var.dir_x * data()->var.move_speed);
	if (data()->map[y][x] != '1')
		data()->var.pos_x += data()->var.dir_x * data()->var.move_speed;
	y = (int)(data()->var.pos_y + data()->var.dir_y * data()->var.move_speed);
	x = (int)data()->var.pos_x;
	if (data()->map[y][x] != '1')
		data()->var.pos_y += data()->var.dir_y * data()->var.move_speed;
}

void	move_backwards(void)
{
	int	y;
	int	x;

	y = (int)data()->var.pos_y;
	x = (int)(data()->var.pos_x - data()->var.dir_x * data()->var.move_speed);
	if (data()->map[y][x] != '1')
		data()->var.pos_x -= data()->var.dir_x * data()->var.move_speed;
	y = (int)(data()->var.pos_y - data()->var.dir_y * data()->var.move_speed);
	x = (int)data()->var.pos_x;
	if (data()->map[y][x] != '1')
		data()->var.pos_y -= data()->var.dir_y * data()->var.move_speed;
}

void	move_left(void)
{
	int	y;
	int	x;

	y = (int)data()->var.pos_y;
	x = (int)(data()->var.pos_x + data()->var.dir_y * data()->var.move_speed);
	if (data()->map[y][x] != '1')
		data()->var.pos_x += data()->var.dir_y * data()->var.move_speed;
	y = (int)(data()->var.pos_y - data()->var.dir_x * data()->var.move_speed);
	x = (int)data()->var.pos_x;
	if (data()->map[y][x] != '1')
		data()->var.pos_y -= data()->var.dir_x * data()->var.move_speed;
}

void	move_right(void)
{
	int	y;
	int	x;

	y = (int)data()->var.pos_y;
	x = (int)(data()->var.pos_x - data()->var.dir_y * data()->var.move_speed);
	if (data()->map[y][x] != '1')
		data()->var.pos_x -= data()->var.dir_y * data()->var.move_speed;
	y = (int)(data()->var.pos_y + data()->var.dir_x * data()->var.move_speed);
	x = (int)data()->var.pos_x;
	if (data()->map[y][x] != '1')
		data()->var.pos_y += data()->var.dir_x * data()->var.move_speed;
}
