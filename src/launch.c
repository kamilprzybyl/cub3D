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

	//printf("drawStart %d\n", data()->var.drawStart);
	//printf("drawEnd %d\n", data()->var.drawEnd);
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
	if (elmnt == 1)
		data()->var.color = 0x000080; //navy color
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
		if (data()->map[data()->var.mapY][data()->var.mapX] > 0) //change order?!
			data()->var.hit = 1;
	}
}

void	raycast_loop(void)
{
	int	x;

	x = 0;
	while (x < 5) //data()->var.sWidth)
	{
		//calculate ray position and direction
		data()->var.cameraX = 2 * x / (double) data()->var.sWidth - 1;
		printf("cameraX %f\n", data()->var.cameraX);
		printf("dirX %f\n", data()->var.dirX);
		printf("dirY %f\n", data()->var.dirY);
		printf("planeX %f\n", data()->var.planeX);
		printf("planeY %f\n", data()->var.planeY);
		data()->var.rayDirX = data()->var.dirX + data()->var.planeX * data()->var.cameraX;
		data()->var.rayDirY = data()->var.dirY + data()->var.planeY * data()->var.cameraX;
		printf("rayDirX %f\n", data()->var.rayDirX);
		printf("rayDirY %f\n", data()->var.rayDirY);
		//which box of the map we're in
		data()->var.mapX = (int) data()->var.posX;
		data()->var.mapY = (int) data()->var.posY;
		printf("mapX %d\n", data()->var.mapX);
		printf("mapY %d\n", data()->var.mapY);
		//length of ray from one x or y-side to next x or y-side
		if (data()->var.rayDirX == 0)
			data()->var.deltaDistX = 1e30;
		else
			data()->var.deltaDistX = fabs(1 / data()->var.rayDirX);
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
		printf("sideDistX %f\n", data()->var.sideDistX);
		printf("sideDistY %f\n", data()->var.sideDistY);
		printf("deltaDistX %f\n", data()->var.deltaDistX);
		printf("deltaDistY %f\n", data()->var.deltaDistY);
		if (data()->var.side == 0)
			data()->var.perpWallDist = data()->var.sideDistX - data()->var.deltaDistX;
		else
			data()->var.perpWallDist = data()->var.sideDistY - data()->var.deltaDistY;
		printf("perpWallDist %f\n", data()->var.perpWallDist);
		//Calculate height of line to draw on screen
		data()->var.lineHeight = (int) (data()->var.sHeight / data()->var.perpWallDist);
		printf("lineHeight %d\n", data()->var.lineHeight);
		//calculate lowest and highest pixel to fill in current stripe
		data()->var.drawStart = (-1) * data()->var.lineHeight / 2 + data()->var.sHeight / 2;
		if (data()->var.drawStart < 0)
			data()->var.drawStart = 0;
		data()->var.drawEnd = data()->var.lineHeight / 2 + data()->var.sHeight / 2;
		if (data()->var.drawEnd >= data()->var.sHeight)
			data()->var.drawEnd = data()->var.sHeight - 1;
		printf("drawStart = %d; drawEnd = %d\n", data()->var.drawStart, data()->var.drawEnd);
		setColor();
		drawVerticalLine(x);
		x++;
	}
}

void	launch(void)
{
	int x;

	x = 0; //testing/debugging
	while (x < 1)
	{
		raycast_loop();

		//timing for input and FPS counter
		//data()->var.oldTime =  data()->var.time;
		//data()->var.time = function_to_get_time(?)
		//data()->var.frameTime = (data()->var.time - data()->var.oldTime) / 1000.0;
		//printf(1.0 / data()->var.frameTime);
		//redraw(); something like put_image_to_window?
		//cls(); (?)

		//speed modifiers
		data()->var.moveSpeed = data()->var.frameTime * 5.0;
		data()->var.rotSpeed = data()->var.frameTime * 3.0;
		mlx_put_image_to_window(data()->mlx, data()->win, data()->img[4].ptr_img, 0, 0);
		//read key events
		mlx_key_hook(data()->win, key_hook, NULL);
		mlx_hook(data()->win, 17, 1L << 0, mouse_events, NULL);
		mlx_loop(data()->mlx);
	}
}
