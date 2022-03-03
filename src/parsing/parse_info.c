/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprzybyl <kprzybyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 17:10:49 by kprzybyl          #+#    #+#             */
/*   Updated: 2022/03/03 16:05:13 by kprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static int	textures(char *line)
{
	char	**tokens;

	tokens = ft_split(line, ' ');
	if (!tokens)
		return (1);
	if (ft_arrlen(tokens) != 2)
		return (1);
	if (ft_strncmp(tokens[0], "NO", 3) == 0)
		data()->xpm[0] = ft_strdup(tokens[1]);
	else if (ft_strncmp(tokens[0], "EA", 3) == 0)
		data()->xpm[1] = ft_strdup(tokens[1]);
	else if (ft_strncmp(tokens[0], "SO", 3) == 0)
		data()->xpm[2] = ft_strdup(tokens[1]);
	else if (ft_strncmp(tokens[0], "WE", 3) == 0)
		data()->xpm[3] = ft_strdup(tokens[1]);
	else if (ft_strncmp(tokens[0], "C", 2) \
		&& ft_strncmp(tokens[0], "F", 2))
		return (1);
	ft_free(&tokens);
	return (0);
}

static int	rgb(char *line)
{
	char	**tokens;

	tokens = ft_split(line, ' ');
	if (!tokens)
		return (1);
	if (ft_arrlen(tokens) != 2)
		return (1);
	if (ft_strncmp(tokens[0], "F", 1) == 0)
		data()->rgb[0] = ft_strdup(tokens[1]);
	else if (ft_strncmp(tokens[0], "C", 1) == 0)
		data()->rgb[1] = ft_strdup(tokens[1]);
	ft_free(&tokens);
	return (0);
}

int	parse_info(int fd)
{
	char	*line;
	int		ret;

	data()->xpm = ft_calloc(sizeof(char *) , 5);
	if (!data()->xpm)
		return (1);
	data()->rgb = ft_calloc(sizeof(char *) , 3);
	if (!data()->rgb)
		return (1);
	while (ft_arrlen(data()->xpm) != 4 \
		|| ft_arrlen(data()->rgb) != 2)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1)
			return (1);
		if (ft_strlen(line) == 0)
			;
		else if (textures(line) == 1 || rgb(line) == 1)
		{
			free(line);
			return (1);
		}
		free(line);
		if (ret == 0)
			break ;
	}
	return (0);
}
