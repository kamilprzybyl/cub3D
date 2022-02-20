/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprzybyl <kprzybyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 17:09:02 by kprzybyl          #+#    #+#             */
/*   Updated: 2022/02/20 17:09:41 by kprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	rotate_right(void)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data()->var.dirX;
	data()->var.dirX = data()->var.dirX * cos(data()->var.rotSpeed) \
		- data()->var.dirY * sin(data()->var.rotSpeed);
	data()->var.dirY = old_dir_x * sin(data()->var.rotSpeed) \
		+ data()->var.dirY * cos(data()->var.rotSpeed);
	old_plane_x = data()->var.planeX;
	data()->var.planeX = data()->var.planeX * cos(data()->var.rotSpeed) \
		- data()->var.planeY * sin(data()->var.rotSpeed);
	data()->var.planeY = old_plane_x * sin(data()->var.rotSpeed) \
		+ data()->var.planeY * cos(data()->var.rotSpeed);
}

void	rotate_left(void)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data()->var.dirX;
	data()->var.dirX = data()->var.dirX * cos(-data()->var.rotSpeed) \
		- data()->var.dirY * sin(-data()->var.rotSpeed);
	data()->var.dirY = old_dir_x * sin(-data()->var.rotSpeed) \
		+ data()->var.dirY * cos(-data()->var.rotSpeed);
	old_plane_x = data()->var.planeX;
	data()->var.planeX = data()->var.planeX * cos(-data()->var.rotSpeed) \
		- data()->var.planeY * sin(-data()->var.rotSpeed);
	data()->var.planeY = old_plane_x * sin(-data()->var.rotSpeed) \
		+ data()->var.planeY * cos(-data()->var.rotSpeed);
}
