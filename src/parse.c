#include <cub3D.h>

int	parse(char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\nCannot open the map\n", 26);
		exit(1);
	}
	return (0);
}
