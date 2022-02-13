#include <cub3D.h>

static int	textures(char *line)
{
	char	**tokens;

	if (ft_strlen(line) == 0)
		return (0);
	tokens = ft_split(line, ' ');
	if (!tokens[0])
		return (1);
	if (ft_arrlen(tokens) != 2)
		return (1);
	if (ft_strncmp(tokens[0], "NO", 3) == 0)
		data()->xpm[0] = ft_strdup(tokens[1]);
	else if (ft_strncmp(tokens[0], "SO", 3) == 0)
		data()->xpm[1] = ft_strdup(tokens[1]);
	else if (ft_strncmp(tokens[0], "WE", 3) == 0)
		data()->xpm[2] = ft_strdup(tokens[1]);
	else if (ft_strncmp(tokens[0], "EA", 3) == 0)
		data()->xpm[3] = ft_strdup(tokens[1]);
	else if (ft_strncmp(tokens[0], "C", 2) \
	&& ft_strncmp(tokens[0], "F", 2))
		return (1);
	data()->xpm[4] = NULL;
	ft_free(tokens);
	return (0);
}

static int	rgb(char *line)
{
	char	**tokens;

	if (ft_strlen(line) == 0)
		return (0);
	tokens = ft_split(line, ' ');
	if (!tokens[0])
		return (1);
	if (ft_arrlen(tokens) != 2)
		return (1);
	if (ft_strncmp(tokens[0], "F", 1) == 0)
		data()->rgb[0] = ft_strdup(tokens[1]);
	else if (ft_strncmp(tokens[0], "C", 1) == 0)
		data()->rgb[1] = ft_strdup(tokens[1]);
	data()->xpm[4] = NULL;
	ft_free(tokens);
	return (0);
}

int	parse_info(int fd)
{
	char	*line;
	int		ret;

	while (ft_arrlen(data()->xpm) != 4
		|| ft_arrlen(data()->rgb) != 2)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1)
			return (1);
		if (ft_strlen(line) == 0 && !data()->map)
			;
		if (textures(line) == 1 || rgb(line) == 1)
			return (1);
		free(line);
		if (ret == 0)
			break ;
	}
	return (0);
}
