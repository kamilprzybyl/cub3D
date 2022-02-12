#include <cub3D.h>

static int	textures(char *line)
{
	char	**tokens;

	if (ft_strlen(line) == 0)
		return (0);
	tokens = ft_split(line, ' ');
	if (!tokens[0])
		return (1);
	if (ft_strncmp(tokens[0], "NO", 2) == 0)
		data()->xpm[0] = ft_strdup(tokens[1]);
	else if (ft_strncmp(tokens[0], "SO", 2) == 0)
		data()->xpm[1] = ft_strdup(tokens[1]);
	else if (ft_strncmp(tokens[0], "WE", 2) == 0)
		data()->xpm[2] = ft_strdup(tokens[1]);
	else if (ft_strncmp(tokens[0], "EA", 2) == 0)
		data()->xpm[3] = ft_strdup(tokens[1]);
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
	if (ft_strncmp(tokens[0], "F", 1) == 0)
		data()->rgb[0] = ft_strdup(tokens[1]);
	else if (ft_strncmp(tokens[0], "C", 1) == 0){
		data()->rgb[1] = ft_strdup(tokens[1]);}
	ft_free(tokens);
	return (0);
}

char	**ft_realloc(char **ptr, int size, char *line)
{
	char	**new_ptr;
	int		i;

	i = 0;
	new_ptr = malloc(sizeof(char *) * size);
	if (!new_ptr)
		return (NULL);
	while (ptr[i])
	{
		new_ptr[i] = ptr[i];
		i++;
	}
	new_ptr[i] = ft_strdup(line);
	new_ptr[i + 1] = NULL;
	free(ptr);
	return (new_ptr);
}

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
		data()->map = ft_realloc(data()->map, ft_arrlen(data()->map) + 2, line);
		// data()->map[ft_arrlen(data()->map) - 1] = ft_strdup(line);
	}
	return (0);
}

int	parse(int fd)
{
	char	*line;
	int		ret;

	while (1)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1)
			return (1);
		if (!data()->xpm[3])
		{
			if (textures(line) == 1)
				return (1);
		}
		else if (!data()->rgb[1])
		{
			if (rgb(line) == 1)
				return (1);
		}
		else if (ft_strlen(line) == 0)
		{
			;
		}
		else
		{
			if (map(line) == 1)
				return (1);
		}
		free(line);
		if (ret == 0)
			break ;
	}
	close(fd);
	return (0);
}
// int	parse(int fd)
// {
// 	char	*line;
// 	int		ret;

// 	while (!data()->rgb[1])
// 	{
// 		ret = get_next_line(fd, &line);
// 		if (ret == -1 || textures(line) == 1 || rgb(line) == 1)
// 			return (1);
// 		free(line);
// 		if (ret == 0)
// 			break ;
// 	}
// 	ret = get_next_line(fd, &line);
// 	while (1)
// 	{
// 		ret = get_next_line(fd, &line);
// 		if (ret == -1 || map(line) == 1)
// 			return (1);
// 		free(line);
// 		if (ret == 0)
// 			break ;
// 	}
// 	for (int i = 0; data()->map[i]; i++)
// 		printf("%s\n", data()->map[i]);
// 	close(fd);
// 	return (0);
// }
