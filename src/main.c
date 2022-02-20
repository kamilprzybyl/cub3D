/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 19:14:30 by kamilprzyby       #+#    #+#             */
/*   Updated: 2022/02/19 19:17:25 by mstrantz         ###   ########.fr       */
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
	mlx_loop_hook(data()->mlx, launch, NULL);
	mlx_hook(data()->win, X_EVENT_KEY_PRESS, 0, &key_press, NULL);
	mlx_hook(data()->win, X_EVENT_KEY_RELEASE, 0, &key_release, NULL);
	mlx_hook(data()->win, 17, 1L << 0, mouse_events, NULL);
	mlx_loop(data()->mlx);
	return (0);
}
