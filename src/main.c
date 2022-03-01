/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprzybyl <kprzybyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 19:14:30 by kamilprzyby       #+#    #+#             */
/*   Updated: 2022/03/01 18:19:43 by kprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

t_cub	*data(void)
{
	static t_cub	data;

	return (&data);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "Error\nMap not provided\n", 23);
		return (1);
	}
	parse(argv[1]);
	init();
	data()->key.p = 1;
	mlx_loop_hook(data()->mlx, launch, NULL);
	mlx_hook(data()->win, 6, (1L << 6), mouse_hook, NULL);
	mlx_hook(data()->win, X_EVENT_KEY_PRESS, 0, &key_press, NULL);
	mlx_hook(data()->win, X_EVENT_KEY_RELEASE, 0, &key_release, NULL);
	mlx_hook(data()->win, X_EVENT_EXIT, 0, &quit, NULL);
	mlx_loop(data()->mlx);
	return (0);
}
