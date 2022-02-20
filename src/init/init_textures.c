#include <cub3D.h>

void	fill_texture_array(int i)
{
	int	x;
	int	y;

	y = -1;
	while (++y < data()->img[i].height)
	{
		x = -1;
		while (++x < data()->img[i].width)
		{
			data()->texture[i][data()->img[i].height * y + x] = \
				(int)(data()->img[i].addr[data()->img[i].height * y + x]);
		}
	}
}

int	init_textures(void)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		data()->img[i].ptr_img = mlx_xpm_file_to_image(data()->mlx, \
			data()->xpm[i], &(data()->img[i].width), &(data()->img[i].height));
		if (!data()->img[i].ptr_img)
			return (1);
		data()->img[i].addr = mlx_get_data_addr(data()->img[i].ptr_img, \
			&data()->img[i].bits_per_pixel, &data()->img[i].line_len, \
			&data()->img[i].endian);
		if (!data()->img[i].addr)
			return (1);
		fill_texture_array(i);
		mlx_destroy_image(data()->mlx, data()->img[i].ptr_img);
		i++;
	}
	return (0);
}
