/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprzybyl <kprzybyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 17:16:07 by kprzybyl          #+#    #+#             */
/*   Updated: 2022/02/20 17:19:44 by kprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	init(void)
{
	data()->mlx = mlx_init();
	if (init_textures() == 1)
	{
		write(1, "Error\nCannot load textures\n", 27);
		exit(1);
	}
	if (init_colors() == 1)
	{
		write(1, "Error\nCannot load colors\n", 25);
		exit(1);
	}
	if (validate_map() == 1)
	{
		write(1, "Error\nInvalid map\n", 18);
		exit(1);
	}
	data()->var.sWidth = SCREEN_WIDTH;
	data()->var.sHeight = SCREEN_HEIGHT;
	data()->win = mlx_new_window(data()->mlx, data()->var.sWidth, data()->var.sHeight, "cub3D");
}
