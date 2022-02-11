#include <cub3D.h>

t_cub	*data(void)
{
	static t_cub	data;

	return &data;
}

int	main(int argc, char **argv)
{
	int		fd;

	if (argc != 2)
	{
		write(1, "Error\nMap not provided\n", 23);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\nCannot open the map\n", 26);
		exit(1);
	}
	if (parse(fd) == 1)
	{
		write(1, "Error\nInvalid map\n", 18);
		exit(1);
	}
	init(fd, argv);
	// system("leaks cub3D");
	mlx_key_hook(data()->win, key_hook, NULL);
	mlx_hook(data()->win, 17, 1L << 0, mouse_events, NULL);
	mlx_loop(data()->mlx);
	return (0);
}
