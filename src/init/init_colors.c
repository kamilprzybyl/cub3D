/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprzybyl <kprzybyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 17:17:09 by kprzybyl          #+#    #+#             */
/*   Updated: 2022/03/03 15:58:28 by kprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static int	*validate_rgb(char **arr)
{
	int	i;
	int	*rgb;

	i = 0;
	rgb = malloc(sizeof(int) * 4);
	if (!rgb)
		return (NULL);
	while (arr[i])
	{
		rgb[i] = ft_atoi(arr[i]);
		if (rgb[i] < 0 || rgb[i] > 255)
			return (NULL);
		i++;
	}
	rgb[i] = 0;
	return (rgb);
}

void	convert_colors(int *rgb, int i)
{
	unsigned long	tmp;

	if (i == 0)
	{
		tmp = rgb_to_hex(rgb[0], rgb[1], rgb[2]);
		data()->floor = tmp;
	}
	if (i == 1)
	{
		tmp = rgb_to_hex(rgb[0], rgb[1], rgb[2]);
		data()->ceilling = tmp;
	}
}

int	init_colors(void)
{
	int				i;
	char			**tmp;
	int				*rgb;

	i = 0;
	while (data()->rgb[i])
	{
		tmp = ft_split(data()->rgb[i], ',');
		if (!tmp)
			return (1);
		rgb = validate_rgb(tmp);
		if (!rgb)
		{
			free(rgb);
			return (1);
		}
		convert_colors(rgb, i);
		ft_free(&tmp);
		free(rgb);
		i++;
	}
	return (0);
}
