#include <cub3D.h>

void	move_forward(void)
{
	if (data()->map[(int)data()->var.posY][(int)(data()->var.posX + data()->var.dirX * data()->var.moveSpeed)] != '1')
			data()->var.posX += data()->var.dirX * data()->var.moveSpeed;
	if (data()->map[(int)(data()->var.posY + data()->var.dirY * data()->var.moveSpeed)][(int)data()->var.posX] != '1')
			data()->var.posY += data()->var.dirY * data()->var.moveSpeed;
}

void	move_backwards(void)
{
	if (data()->map[(int)data()->var.posY][(int)(data()->var.posX - data()->var.dirX * data()->var.moveSpeed)] != '1')
		data()->var.posX -= data()->var.dirX * data()->var.moveSpeed;
	if (data()->map[(int)(data()->var.posY - data()->var.dirY * data()->var.moveSpeed)][(int)data()->var.posX] != '1')
		data()->var.posY -= data()->var.dirY * data()->var.moveSpeed;
}

void	move_left(void)
{
	if (data()->map[(int)data()->var.posY][(int)(data()->var.posX + data()->var.dirY * data()->var.moveSpeed)] != '1')
		data()->var.posX += data()->var.dirY * data()->var.moveSpeed;
	if (data()->map[(int)(data()->var.posY - data()->var.dirX * data()->var.moveSpeed)][(int)data()->var.posX] != '1')
		data()->var.posY -= data()->var.dirX * data()->var.moveSpeed;
}

void	move_right(void)
{
	if (data()->map[(int)data()->var.posY][(int)(data()->var.posX - data()->var.dirY * data()->var.moveSpeed)] != '1')
		data()->var.posX -= data()->var.dirY * data()->var.moveSpeed;
	if (data()->map[(int)(data()->var.posY + data()->var.dirX * data()->var.moveSpeed)][(int)data()->var.posX] != '1')
		data()->var.posY += data()->var.dirX * data()->var.moveSpeed;
}
