#include <cub3D.h>

int	init_colors(void)
{
	char	**rgb;

	rgb = ft_split(data()->rgb[0], ',');
	if (!rgb)
		return (1);
	data()->floor = rgb_to_hex(ft_atoi(rgb[0]),
		ft_atoi(rgb[1]), ft_atoi(rgb[2]));
	ft_free(rgb);
	rgb = ft_split(data()->rgb[1], ',');
	if (!rgb)
		return (1);
	data()->ceilling = rgb_to_hex(ft_atoi(rgb[0]),
		ft_atoi(rgb[1]), ft_atoi(rgb[2]));
	ft_free(rgb);
	return (0);
}