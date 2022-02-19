#include <cub3D.h>

void	my_mlx_pixel_put(int x, int y, int color)
{
	char	*dst;

	dst = data()->img[4].addr + (y * data()->img[4].line_len + x * (data()->img[4].bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	drawVerticalLine(int x)
{
	int	y;

	y = data()->var.drawStart;
	while (y < data()->var.drawEnd)
	{
		my_mlx_pixel_put(x, y, data()->var.color);
		y++;
	}
}

void	setColor(void)
{
	int	elmnt;

	elmnt = data()->map[data()->var.mapY][data()->var.mapX];
	if (elmnt == '1')
		data()->var.color = 0x80FF00;
	if (data()->var.side == 1)
		data()->var.color = data()->var.color / 2;
}

void	dda(void)
{
	while (data()->var.hit == 0)
	{
		//jump to next map square, either in x-direction, or in y-direction
		if (data()->var.sideDistX < data()->var.sideDistY)
		{
			data()->var.sideDistX += data()->var.deltaDistX;
			data()->var.mapX += data()->var.stepX;
			data()->var.side = 0;
		}
		else
		{
			data()->var.sideDistY += data()->var.deltaDistY;
			data()->var.mapY += data()->var.stepY;
			data()->var.side = 1;
		}
		//Check if ray has hit a wall
		if (data()->map[data()->var.mapY][data()->var.mapX] == '1')
			data()->var.hit = 1;
	}
}

void	raycast_loop(void)
{
	int	x;

	x = 0;
	while (x < data()->var.sWidth)
	{
		//calculate ray position and direction
		data()->var.cameraX = 2 * x / (double) data()->var.sWidth - 1;
		data()->var.rayDirX = data()->var.dirX + data()->var.planeX * data()->var.cameraX;
		data()->var.rayDirY = data()->var.dirY + data()->var.planeY * data()->var.cameraX;
		//which box of the map we're in
		data()->var.mapX = (int) data()->var.posX;
		data()->var.mapY = (int) data()->var.posY;
		//length of ray from one x or y-side to next x or y-side
		// if (data()->var.rayDirX == 0)
		// 	data()->var.deltaDistX = 1e30;
		// else
		// 	data()->var.deltaDistX = fabs(1 / data()->var.rayDirX);
		// if (data()->var.rayDirY == 0)
		// 	data()->var.deltaDistY = 1e30;
		// else
		// 	data()->var.deltaDistY = fabs(1 / data()->var.rayDirY);
		data()->var.deltaDistX = (data()->var.rayDirX == 0) ? 1e30 : fabs(1 / data()->var.rayDirX);
		data()->var.deltaDistY = (data()->var.rayDirY == 0) ? 1e30 : fabs(1 / data()->var.rayDirY);
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
			data()->var.perpWallDist = data()->var.sideDistX - data()->var.deltaDistX;
		else
			data()->var.perpWallDist = data()->var.sideDistY - data()->var.deltaDistY;
		//Calculate height of line to draw on screen
		data()->var.lineHeight = (int) (data()->var.sHeight / data()->var.perpWallDist) *2; //added *2, not part of the guide, but with j&a's version
		//calculate lowest and highest pixel to fill in current stripe
		data()->var.drawStart = (-1) * data()->var.lineHeight / 2 + data()->var.sHeight / 2;
		if (data()->var.drawStart < 0)
			data()->var.drawStart = 0;
		data()->var.drawEnd = data()->var.lineHeight / 2 + data()->var.sHeight / 2;
		if (data()->var.drawEnd >= data()->var.sHeight)
			data()->var.drawEnd = data()->var.sHeight - 1;
		setColor();
		drawVerticalLine(x);
		x++;
	}
}

void	drawFloor(void)
{
	int	i;
	int	j;
	int	color;

	color = 0x808080;
	i = 0;
	while (i < data()->var.sWidth)
	{
		j = data()->var.sHeight / 2 - 1;
		while (++j < data()->var.sHeight)
		{
			my_mlx_pixel_put(i, j, color);
		}
		i++;
	}
}

void	drawCeiling(void)
{
	int	i;
	int	j;
	int	color;

	color = 0x00FFFF;
	i = 0;
	while (i < data()->var.sWidth)
	{
		j = -1;
		while (++j < data()->var.sHeight / 2)
		{
			my_mlx_pixel_put(i, j, color);
		}
		i++;
	}
}

int	launch(void)
{
	data()->img[4].ptr_img = mlx_new_image(data()->mlx, data()->var.sWidth, data()->var.sHeight);
	data()->img[4].addr = mlx_get_data_addr(data()->img[4].ptr_img, &data()->img[4].bits_per_pixel, \
		&data()->img[4].line_len, &data()->img[4].endian);
	drawFloor();
	drawCeiling();
	raycast_loop();
	//timing for input and FPS counter
	//data()->var.oldTime =  data()->var.time;
	//data()->var.time = function_to_get_time(?)
	//data()->var.frameTime = (data()->var.time - data()->var.oldTime) / 1000.0;
	//printf(1.0 / data()->var.frameTime);

	//speed modifiers
	//data()->var.moveSpeed = data()->var.frameTime * 5.0;
	//data()->var.rotSpeed = data()->var.frameTime * 3.0;
	mlx_put_image_to_window(data()->mlx, data()->win, data()->img[4].ptr_img, 0, 0);
	mlx_destroy_image(data()->mlx, data()->img[4].ptr_img);
	return (0);
}
