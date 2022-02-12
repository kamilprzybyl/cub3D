#include <cub3D.h>

static int	load_textures(void)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		data()->img[i].ptr_img = mlx_xpm_file_to_image(data()->mlx,
				data()->xpm[i], &(data()->img[i].width), &(data()->img[i].height));
		if (!data()->img[i].ptr_img)
			return (1);
		data()->img[i].addr = mlx_get_data_addr(data()->img[i].ptr_img,
				&data()->img[i].bits_per_pixel, &data()->img[i].line_len,
				&data()->img[i].endian);
		if (!data()->img[i].addr)
			return (1);
		i++;
	}
	return (0);
}

static int	convert_colors(void)
{
	char	**rgb;

	rgb = ft_split(data()->rgb[0], ',');
	data()->floor = rgb_to_hex(ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]));
	ft_free(rgb);
	rgb = ft_split(data()->rgb[1], ',');
	data()->ceilling = rgb_to_hex(ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]));
	ft_free(rgb);
	return (0);
}

static int	check_empty_space(int i, int j)
{
	if (data()->map[i][j] == ' ')
	{
		if (i != 0 && data()->map[i - 1][j] == '0')
			return (1);
		if (data()->map[i + 1] && data()->map[i + 1][j] && data()->map[i + 1][j] == '0')
			return (1);
		if (j != 0 && data()->map[i][j - 1] == '0')
			return (1);
		if (data()->map[i][j + 1] && data()->map[i][j + 1] == '0')
			return (1);
	}
	return (0);
}

static int	check_edge(int i, int j)
{
	if (i == 0 || !data()->map[i + 1] || j == 0 || !data()->map[i][j + 1])
	{
		if (data()->map[i][j] == '0')
			return (1);
	}
	return (0);
}

static int	validate_map(void)
{
	int	i;
	int	j;

	if (ft_arrlen(data()->map) < 3)
		return (1);
	i = 0;
	while (data()->map[i])
	{
		j = 0;
		while (data()->map[i][j])
		{
			if (ft_strlen(data()->map[i]) == 0 || data()->map[i][0] == '\n')
				return (1);
			if (check_edge(i, j) == 1)
				return (1);
			if (check_empty_space(i, j) == 1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	init(void)
{
	data()->mlx = mlx_init();
	if (load_textures() == 1)
	{
		write(1, "Error\nCannot load textures\n", 27);
		exit(1);
	}
	if (validate_map() == 1)
	{
		write(1, "Error\nInvalid map\n", 18);
		exit(1);
	}
	convert_colors();
	data()->win = mlx_new_window(data()->mlx, 2000, 1000, "cub3D");
}
