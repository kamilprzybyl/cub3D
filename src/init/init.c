/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprzybyl <kprzybyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 17:16:07 by kprzybyl          #+#    #+#             */
/*   Updated: 2022/03/03 15:58:21 by kprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static void	ft_exit(char *s)
{
	write(2, s, ft_strlen(s));
	ft_free(&data()->xpm);
	ft_free(&data()->rgb);
	ft_free(&data()->map);
	exit(1);
}

void	init(void)
{
	void	*tmp;

	data()->mlx = mlx_init();
	if (init_textures() == 1)
		ft_exit("Error\nCannot load textures\n");
	if (init_colors() == 1)
		ft_exit("Error\nCannot load colors\n");
	if (validate_map() == 1)
		ft_exit("Error\nInvalid map\n");
	tmp = mlx_new_window(data()->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
	data()->win = tmp;
}
