/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprzybyl <kprzybyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 17:17:09 by kprzybyl          #+#    #+#             */
/*   Updated: 2022/02/21 12:54:32 by kprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static int	validate_rgb(char **rgb)
{
	int	i;

	i = 0;
	while (rgb[i])
	{
		if (ft_atoi(rgb[i]) < 0 || ft_atoi(rgb[i]) > 255)
			return (1);
		i++;
	}
	return (0);
}

int	init_colors(void)
{
	int		i;
	char	**rgb;
	int		tmp;

	i = 0;
	while (data()->rgb[i])
	{
		rgb = ft_split(data()->rgb[i], ',');
		if (!rgb)
			return (1);
		if (validate_rgb(rgb) == 1)
			return (1);
		if (i == 0)
			data()->floor = rgb_to_hex(ft_atoi(rgb[0]), \
				ft_atoi(rgb[1]), ft_atoi(rgb[2]));
		if (i == 1)
			data()->ceilling = rgb_to_hex(ft_atoi(rgb[0]), \
				ft_atoi(rgb[1]), ft_atoi(rgb[2]));
		ft_free(rgb);
		i++;
	}
	return (0);
}
