#include <cub3D.h>

static int	ft_close(void)
{
	mlx_destroy_window(data()->mlx, data()->win);
	exit(0);
}

int	key_hook(int keycode, void *unused)
{
	if (keycode == ESC)
		ft_close();
	return (1);
	(void)unused;
}
