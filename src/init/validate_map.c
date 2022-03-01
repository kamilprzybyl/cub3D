/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprzybyl <kprzybyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:38:17 by mstrantz          #+#    #+#             */
/*   Updated: 2022/03/01 18:47:04 by kprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static int	is_closed(int i, int j)
{
	if (data()->map[i][j] == '0' \
		|| (data()->map[i][j] != '1' && data()->map[i][j] != ' '))
	{
		if (i == 0 || !data()->map[i + 1] || j == 0 || !data()->map[i][j + 1])
			return (1);
		if (data()->map[i - 1] && data()->map[i - 1][j]
			&& data()->map[i - 1][j] == ' ')
			return (1);
		if (data()->map[i + 1] && data()->map[i + 1][j]
			&& data()->map[i + 1][j] == ' ')
			return (1);
		if (data()->map[i] && data()->map[i][j - 1]
			&& data()->map[i][j - 1] == ' ')
			return (1);
		if (data()->map[i] && data()->map[i][j + 1]
			&& data()->map[i][j + 1] == ' ')
			return (1);
	}
	return (0);
}

static int	is_end(int index)
{
	int		i;

	i = index;
	i++;
	while (data()->map[i])
	{
		if (ft_strlen(data()->map[i]) > 0)
			return (1);
		i++;
	}
	data()->map[i] = NULL;
	return (0);
}

int	validate_map(void)
{
	int	i;
	int	j;

	if (ft_arrlen(data()->map) < 3 || check_chars() != 1)
		return (1);
	i = 0;
	while (data()->map[i])
	{
		if (ft_strlen(data()->map[i]) == 0)
		{
			if (is_end(i) == 1)
				return (1);
			break ;
		}
		j = 0;
		while (data()->map[i][j])
		{
			if (is_closed(i, j) == 1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
