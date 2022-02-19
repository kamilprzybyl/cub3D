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
//test
int	key_hook(int keycode, void *unused)
{
	if (keycode == ESC)
		ft_close();
	else if (keycode == W)
	{
		// if (data()->map[(int)(data()->var.posX + data()->var.dirX * data()->var.moveSpeed)][(int) data()->var.posY] == 0)
			// printf("speed = %f", data()->var.moveSpeed);
			// data()->var.posX += data()->var.dirX * data()->var.moveSpeed;
		// if (data()->map[(int) data()->var.posX][(int) (data()->var.posY + data()->var.dirY * data()->var.moveSpeed)] == 0)
			// printf("w = %f\n", data()->var.dirY * data()->var.moveSpeed);
			data()->var.posY += data()->var.dirY * data()->var.moveSpeed;
	}
	else if (keycode == LEFT)
		rotate_left();
	else if (keycode == A)
	{
		// if (data()->map[(int) (data()->var.posX - data()->var.dirX * data()->var.moveSpeed)][(int) data()->var.posY] == 0)
			data()->var.posX += data()->var.dirY * data()->var.moveSpeed;
		// if (data()->map[(int) data()->var.posX][(int) (data()->var.posY - data()->var.dirY * data()->var.moveSpeed)] == 0)
			// data()->var.posY -= data()->var.dirY;// * data()->var.moveSpeed;
	}
	else if (keycode == S)
	{
		// if (data()->map[(int) (data()->var.posX - data()->var.dirX * data()->var.moveSpeed)][(int) data()->var.posY] == 0)
			// data()->var.posX -= data()->var.dirX * data()->var.moveSpeed;
		// if (data()->map[(int) data()->var.posX][(int) (data()->var.posY - data()->var.dirY * data()->var.moveSpeed)] == 0)
			// printf("s = %f\n", data()->var.dirY * data()->var.moveSpeed);
			data()->var.posY -= data()->var.dirY * data()->var.moveSpeed;
	}
	else if (keycode == RIGHT)
	{
		rotate_right();
	}
	else if (keycode == D)
	{
		// if (data()->map[(int) (data()->var.posX - data()->var.dirX * data()->var.moveSpeed)][(int) data()->var.posY] == 0)
			// printf("d = %f\n", data()->var.dirX * data()->var.moveSpeed);
			data()->var.posX -= data()->var.dirY * data()->var.moveSpeed;
		// if (data()->map[(int) data()->var.posX][(int) (data()->var.posY - data()->var.dirY * data()->var.moveSpeed)] == 0)
			// data()->var.posY -= data()->var.dirY;// * data()->var.moveSpeed;
	}
	return (1);
	(void)unused;
}
