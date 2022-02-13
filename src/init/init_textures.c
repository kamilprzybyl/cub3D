#include <cub3D.h>

int	init_textures(void)
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
