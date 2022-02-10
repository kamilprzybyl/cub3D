#include <cub3D.h>

static int	ft_close(void)
{
	mlx_destroy_window(data()->mlx, data()->win);
	exit(0);
}

int	key_hook(int keycode, void *unused)
{
	// int	x;
	// int	y;
	// int	i;
	// int	j;

	// mlx_clear_window(cub->mlx, cub->win);
	if (keycode == ESC)
		ft_close();
	// else
	// {
	// 	find_character(game, &x, &y, 'P');
	// 	handle_key(game, keycode);
	// 	find_character(game, &i, &j, 'P');
	// 	if (j != y || x != i)
	// 		printf("moves = %d\n", ++game->moves);
	// }
	// draw_map(game);
	return (1);
	(void)unused;
}
