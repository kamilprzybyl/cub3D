#include <cub3D.h>

void	fill_texture_array(int i)
{
	int	x;
	int	y;

	y = -1;
	while (++y < data()->img2[i].height)
	{
		x = -1;
		while (++x < data()->img2[i].width)
		{
			data()->texture[i][data()->img2[i].height * y + x] = \
				(data()->img2[i].addr[data()->img2[i].height * y + x]);
		}
	}
}

int	init_textures(void)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		data()->img2[i].ptr_img = mlx_xpm_file_to_image(data()->mlx, \
			data()->xpm[i], &(data()->img2[i].width), &(data()->img2[i].height));
		if (!data()->img2[i].ptr_img)
			return (1);
		data()->img2[i].addr = (int *) mlx_get_data_addr(data()->img2[i].ptr_img, \
			&data()->img2[i].bits_per_pixel, &data()->img2[i].line_len, \
			&data()->img2[i].endian);
		if (!data()->img2[i].addr)
			return (1);
		fill_texture_array(i);
		mlx_destroy_image(data()->mlx, data()->img2[i].ptr_img);
		i++;
	}
	return (0);
}
