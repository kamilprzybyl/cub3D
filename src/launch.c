#include <cub3D.h>

void	dda(void)
{
	while (data()->var.hit == 0)
	{
		//jump to next map square, either in x-direction, or in y-direction
		if (data()->var.sideDistX < data()->var.sideDistY)
		{
			data()->var.sideDistX += data()->var.deltaDistX;
			data()->var.mapX += data()->var.stepX;
			data()->side = 0;
		}
		else
		{
			data()->var.sideDistY += data()->var.deltaDistY;
			data()->var.mapY += data()->var.stepY;
			data()->side = 1;
		}
		//Check if ray has hit a wall
		if (data()->map[data()->var.mapY][data()->var.mapX] > 0) //change order?!
			data()->var.hit = 1;
	}
}

void	raycast_loop(void)
{
	int	x;
	int	x_max; // camera plane length (?), via FieldOfView (?)

	x = 0;
	while (x < x_max)
	{
		//calculate ray position and direction
		data()->var.cameraX = 2 * x / (double) x_max - 1;
		data()->var.rayDirX = data()->var.dirX + data()->var.planeX * data()->cameraX;
		data()->var.rayDirY = data()->var.dirY + data()->var.planeY * data()->cameraX;
		//which box of the map we're in
		data()->var.mapX = (int) data()->var.posX;
		data()->var.mapY = (int) data()->var.posY;
		//length of ray from one x or y-side to next x or y-side
		if (data()->var.rayDirX == 0)
			data()->var.deltaDistX = 1e30;
		else
			data()->var.deltaDistX = fabs(1 / data()->var.rayDirX);
		}
		if (data()->var.rayDirY == 0)
			data()->var.deltaDistY = 1e30;
		else
			data()->var.deltaDistY = fabs(1 / data()->var.rayDirY);
		data()->var.hit = 0;
		//calculate step and initial sideDist
		if (data()->var.rayDirX < 0)
		{
			data()->var.stepX = -1;
			data()->var.sideDistX = (data()->var.posX - data()->var.mapX) * data()->var.deltaDistX;
		}
		else
		{
			data()->var.stepX = 1;
			data()->var.sideDistX = (data()->var.mapX + 1.0 - data()->var.posX) * data()->var.deltaDistX;
		}
		if (data()->var.rayDirY < 0)
		{
			data()->var.stepY = -1;
			data()->var.sideDistY = (data()->var.posY - data()->var.mapY) * data()->var.deltaDistY;
		}
		else
		{
			data()->var.stepY = 1;
			data()->var.sideDistY = (data()->var.mapY + 1.0 - data()->var.posY) * data()->var.deltaDistY;
		}
		//DDA
		dda();
		//Calculate distance of perpendicular ray (Euclidean distance would give fisheye effect!)
		if (data()->var.side == 0)
		x++;
	}
}

void	launch(void)
{
	mlx_key_hook(data()->win, key_hook, NULL);
	mlx_hook(data()->win, 17, 1L << 0, mouse_events, NULL);
	mlx_loop(data()->mlx);
	while (1)
	{

		raycast_loop();
		//what direction to step in x or y-direction (either +1 or -1)


		//Calculate height of line to draw on screen
		//calculate lowest and highest pixel to fill in current stripe
	}
}
