/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprzybyl <kprzybyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 17:10:56 by kprzybyl          #+#    #+#             */
/*   Updated: 2022/03/01 18:00:56 by kprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static int	map(char *line)
{
	char	**tmp;

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
		tmp = ft_realloc(data()->map, ft_arrlen(data()->map) + 2);
		if (!tmp)
			return (1);
		data()->map = tmp;
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
