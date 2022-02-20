/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprzybyl <kprzybyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 17:02:42 by kprzybyl          #+#    #+#             */
/*   Updated: 2022/02/20 17:08:19 by kprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	move_forward(void)
{
	int	y;
	int	x;

	y = (int)data()->var.posY;
	x = (int)(data()->var.posX + data()->var.dirX * data()->var.moveSpeed);
	if (data()->map[y][x] != '1')
		data()->var.posX += data()->var.dirX * data()->var.moveSpeed;
	y = (int)(data()->var.posY + data()->var.dirY * data()->var.moveSpeed);
	x = (int)data()->var.posX;
	if (data()->map[y][x] != '1')
		data()->var.posY += data()->var.dirY * data()->var.moveSpeed;
}

void	move_backwards(void)
{
	int	y;
	int	x;

	y = (int)data()->var.posY;
	x = (int)(data()->var.posX - data()->var.dirX * data()->var.moveSpeed);
	if (data()->map[y][x] != '1')
		data()->var.posX -= data()->var.dirX * data()->var.moveSpeed;
	y = (int)(data()->var.posY - data()->var.dirY * data()->var.moveSpeed);
	x = (int)data()->var.posX;
	if (data()->map[y][x] != '1')
		data()->var.posY -= data()->var.dirY * data()->var.moveSpeed;
}

void	move_left(void)
{
	int	y;
	int	x;

	y = (int)data()->var.posY;
	x = (int)(data()->var.posX + data()->var.dirY * data()->var.moveSpeed);
	if (data()->map[y][x] != '1')
		data()->var.posX += data()->var.dirY * data()->var.moveSpeed;
	y = (int)(data()->var.posY - data()->var.dirX * data()->var.moveSpeed);
	x = (int)data()->var.posX;
	if (data()->map[y][x] != '1')
		data()->var.posY -= data()->var.dirX * data()->var.moveSpeed;
}

void	move_right(void)
{
	int	y;
	int	x;

	y = (int)data()->var.posY;
	x = (int)(data()->var.posX - data()->var.dirY * data()->var.moveSpeed);
	if (data()->map[y][x] != '1')
		data()->var.posX -= data()->var.dirY * data()->var.moveSpeed;
	y = (int)(data()->var.posY + data()->var.dirX * data()->var.moveSpeed);
	x = (int)data()->var.posX;
	if (data()->map[y][x] != '1')
		data()->var.posY += data()->var.dirX * data()->var.moveSpeed;
}
