#include <cub3D.h>

void	launch(void)
{
	mlx_key_hook(data()->win, key_hook, NULL);
	mlx_hook(data()->win, 17, 1L << 0, mouse_events, NULL);
	mlx_loop(data()->mlx);
	while (1)
	{
		// for(int x = 0; x < w; x++)
		// {
		//calculate ray position and direction
		//which box of the map we're in
		//length of ray from current position to next x or y-side
		//length of ray from one x or y-side to next x or y-side
		//what direction to step in x or y-direction (either +1 or -1)
		//calculate step and initial sideDist
		//perform DDA
		// while (hit == 0)
		// {
			//jump to next map square, either in x-direction, or in y-direction
			//Check if ray has hit a wall
		// }
		//Calculate distance of perpendicular ray (Euclidean distance would give fisheye effect!)
		//Calculate height of line to draw on screen
		//calculate lowest and highest pixel to fill in current stripe
	}
}
