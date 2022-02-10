#include <cub3D.h>

// static int	validate_map(char **argv)
// {

// }

// static int	load_images(void)
// {
// 	int	i;

// 	i = 0;
// 	while (data()->xpm[i])
// 	{
// 		data()->img[i].ptr_img = mlx_xpm_file_to_image(data()->mlx,
// 				data()->xpm[i], &(data()->img[i].width), &(data()->img[i].height));
// 		data()->img[i].addr = mlx_get_data_addr(data()->img[i].ptr_img,
// 				&data()->img[i].bits_per_pixel, &data()->img[i].line_len,
// 				&data()->img[i].endian);
// 		i++;
// 	}
// 	return (0);
// }

// static char	**read_map(int fd, char **argv)
// {
// 	int		j;
// 	char	*line;

// 	j = 0;
// 	data()->map = malloc(sizeof(char *) * (get_num_of_rows(argv[1]) + 1));
// 	if (!data()->map)
// 		return (data()->map);
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (!line)
// 			break ;
// 		data()->map[j] = line;
// 		j++;
// 	}
// 	data()->map[j] = NULL;
// 	close(fd);
// 	return (data()->map);
// }

void	init()
{ 
	data()->mlx = mlx_init();
	// data()->map = read_map(fd, argv);
	// printf("init\n");
	// load_images();
	data()->win = mlx_new_window(data()->mlx, 2000, 1000, "data()3D");
}
