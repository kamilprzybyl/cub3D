#include <cub3D.h>

int	parse(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\nCannot open the map\n", 26);
		exit(1);
	}
	if (parse_info(fd) == 1)
	{
		write(1, "Error\nInvalid information\n", 26);
		exit(1);
	}
	if (parse_map(fd) == 1)
	{
		write(1, "Error\nInvalid map\n", 18);
		exit(1);
	}
	close(fd);
	return (0);
}
