#include <cub3D.h>

int	get_num_of_rows(char *file)
{
	int		i;
	int		fd;
	char	*str;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\nBad file descriptor\n", 28);
		return (-1);
	}
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		free(str);
		i++;
	}
	close(fd);
	return (i);
}
