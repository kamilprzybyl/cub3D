/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprzybyl <kprzybyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 17:11:01 by kprzybyl          #+#    #+#             */
/*   Updated: 2022/03/05 17:39:56 by kprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static void	ft_exit(char *s, int fd)
{
	if (fd < 0)
		close(fd);
	write(2, s, ft_strlen(s));
	ft_free(&data()->xpm);
	ft_free(&data()->rgb);
	ft_free(&data()->map);
	exit(1);
}

int	parse(char *file)
{
	int	fd;

	if (ft_strncmp(get_ext(file), "cub", 4) != 0)
		ft_exit("Error\nInvalid extension\n", -1);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_exit("Error\nCannot open the map\n", fd);
	if (parse_info(fd) == 1)
		ft_exit("Error\nInvalid information\n", fd);
	if (parse_map(fd) == 1)
		ft_exit("Error\nInvalid map\n", fd);
	close(fd);
	return (0);
}
