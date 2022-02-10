#include <cub3D.h>

static int	textures(char **line)
{
	if (!data()->xpm)
	{
		data()->xpm = malloc(sizeof(char *) * (4 + 1));
		if (!data()->xpm)
			return (1);
		data()->xpm[6] = NULL;
	}
	if (ft_strncmp(*line, "NO", 2) == 0)
		data()->xpm[0] = &(*line)[3];
	else if (ft_strncmp(*line, "SO", 2) == 0)
		data()->xpm[1] = &(*line)[3];
	else if (ft_strncmp(*line, "WE", 2) == 0)
		data()->xpm[2] = &(*line)[3];
	else if (ft_strncmp(*line, "EA", 2) == 0)
		data()->xpm[3] = &(*line)[3];
	else if (ft_strncmp(*line, "F", 1) == 0)
		data()->xpm[4] = &(*line)[2];
	else if (ft_strncmp(*line, "C", 1) == 0)
		data()->xpm[5] = &(*line)[2];
	else
		return (-1);
	return (0);
}

// static void	colors((char **line)
// {
// 	if (ft_strncmp(line, "F", 1) == 0)

// 	if (ft_strncmp(line, "C", 1) == 0)
// 	return (0);
// }

static int	map(char **line)
{
	// printf("[%s]\n", *line);
	int		i;
	char	**tmp;

	if (!data()->map)
	{
		data()->map = malloc(sizeof(char *) * 1);
		if (!data()->map)
			return (1);
		data()->map[0] = NULL;
	}
	i = 0;
	while (data()->map[i])
		i++;
	tmp = malloc(sizeof(char *) * (i + 1 + 1));
	if (!tmp)
		return (1);
	i = 0;
	while (data()->map[i])
	{
		tmp[i] = data()->map[i];
		i++;	
	}
	tmp[i] = *line;
	tmp[i + 1] = NULL;
	data()->map = tmp;
	return (0);
}

int	parse(int fd)
{
	char	*line;
	int		ret;
	int		text;
	int		i;

	i = 0;
	while (1)
	{
		ret = get_next_line(fd, &line);
		if (ret == 0 || ret == -1)
			break ;
		text = textures(&line);
		if (text == 1)
			return (1);
		if (data()->xpm[5] && text != 0 && ft_strlen(line) != 0)
		{
			if (map(&line) == 1)
				return (1);
		}
	}
	// for (int i = 0; i < 6; i++)
	// 	printf("%s\n", data()->xpm[i]);
	for (int i = 0; data()->map[i]; i++)
		printf("%s\n", data()->map[i]);
	close(fd);
	return (0);
}
