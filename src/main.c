#include <cub3D.h>

int	main(int argc, char **argv)
{
	t_cub	cub;
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
	// if (parse(argv) == 1)
	// {
	// 	write(1, "Error\nInvalid map\n", 18);
	// 	exit(1);
	// }
	init(&cub, fd, argv);
	mlx_loop(cub.vars.mlx);
	return (0);
}
