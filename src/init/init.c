#include <cub3D.h>

void	init(void)
{
	data()->mlx = mlx_init();
	if (init_textures() == 1)
	{
		write(1, "Error\nCannot load textures\n", 27);
		exit(1);
	}
	if (init_colors() == 1)
	{
		write(1, "Error\nCannot load colors\n", 25);
		exit(1);
	}
	if (validate_map() == 1)
	{
		write(1, "Error\nInvalid map\n", 18);
		exit(1);
	}
	data()->win = mlx_new_window(data()->mlx, 2000, 1000, "cub3D");
}
