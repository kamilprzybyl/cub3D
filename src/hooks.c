#include <cub3D.h>

static int	ft_close(void)
{
	mlx_destroy_window(data()->mlx, data()->win);
	exit(0);
}

void	rotate_left(void)
{
	double	oldDirX;
	double	oldPlaneX;

	oldDirX = data()->var.dirX;
	data()->var.dirX = data()->var.dirX * cos(data()->var.rotSpeed) - data()->var.dirY * sin(data()->var.rotSpeed);
	data()->var.dirY = oldDirX * sin(data()->var.rotSpeed) + data()->var.dirY * cos(data()->var.rotSpeed);
	oldPlaneX = data()->var.planeX;
	data()->var.planeX = data()->var.planeX * cos(data()->var.rotSpeed) - data()->var.planeY * sin(data()->var.rotSpeed);
	data()->var.planeY = oldPlaneX * sin(data()->var.rotSpeed) + data()->var.planeY * cos(data()->var.rotSpeed);
}

void	rotate_right(void)
{
	double	oldDirX;
	double	oldPlaneX;

	oldDirX = data()->var.dirX;
	data()->var.dirX = data()->var.dirX * cos(-data()->var.rotSpeed) - data()->var.dirY * sin(-data()->var.rotSpeed);
	data()->var.dirY = oldDirX * sin(-data()->var.rotSpeed) + data()->var.dirY * cos(-data()->var.rotSpeed);
	oldPlaneX = data()->var.planeX;
	data()->var.planeX = data()->var.planeX * cos(-data()->var.rotSpeed) - data()->var.planeY * sin(-data()->var.rotSpeed);
	data()->var.planeY = oldPlaneX * sin(-data()->var.rotSpeed) + data()->var.planeY * cos(-data()->var.rotSpeed);
}

int	key_hook(int keycode, void *unused)
{
	if (keycode == ESC)
		ft_close();
	else if (keycode == W || keycode == UP)
	{
		if (data()->map[(int) (data()->var.posX + data()->var.dirX * data()->var.moveSpeed)][(int) data()->var.posY] == 0)
			data()->var.posX += data()->var.dirX * data()->var.moveSpeed;
		if (data()->map[(int) data()->var.posX][(int) (data()->var.posY + data()->var.dirY * data()->var.moveSpeed)] == 0)
			data()->var.posY += data()->var.dirY * data()->var.moveSpeed;
	}
	else if (keycode == A || keycode == LEFT)
		rotate_left();
	else if (keycode == S || keycode == DOWN)
	{
		if (data()->map[(int) (data()->var.posX - data()->var.dirX * data()->var.moveSpeed)][(int) data()->var.posY] == 0)
			data()->var.posX -= data()->var.dirX * data()->var.moveSpeed;
		if (data()->map[(int) data()->var.posX][(int) (data()->var.posY - data()->var.dirY * data()->var.moveSpeed)] == 0)
			data()->var.posY -= data()->var.dirY * data()->var.moveSpeed;
	}
	else if (keycode == D || keycode == RIGHT)
		rotate_right();
	return (1);
	(void)unused;
}
