#include <cub3D.h>

void	rotate_right(void)
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

void	rotate_left(void)
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
