/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 17:17:09 by kprzybyl          #+#    #+#             */
/*   Updated: 2022/02/21 12:33:25 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	init_colors(void)
{
	char	**rgb;
	int		tmp;

	rgb = ft_split(data()->rgb[0], ',');
	if (!rgb)
		return (1);
	tmp = rgb_to_hex(ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]));
	data()->floor = tmp;
	ft_free(rgb);
	rgb = ft_split(data()->rgb[1], ',');
	if (!rgb)
		return (1);
	tmp = rgb_to_hex(ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]));
	data()->ceilling = tmp;
	ft_free(rgb);
	return (0);
}
