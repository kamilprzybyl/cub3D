#include <cub3D.h>

static int	map(char *line)
{
	if (!data()->map)
	{
		data()->map = malloc(sizeof(char *) * 2);
		if (!data()->map)
			return (1);
		data()->map[0] = ft_strdup(line);
		data()->map[1] = NULL;
	}
	else
	{
		data()->map = ft_realloc(data()->map, ft_arrlen(data()->map) + 2);
		data()->map[ft_arrlen(data()->map)] = ft_strdup(line);
	}
	return (0);
}

int	parse_map(int fd)
{
	char	*line;
	int		ret;

	while (1)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1)
			return (1);
		if (ft_strlen(line) == 0 && !data()->map)
			;
		else if (map(line) == 1)
			return (1);
		free(line);
		if (ret == 0)
			break ;
	}
	return (0);
}
