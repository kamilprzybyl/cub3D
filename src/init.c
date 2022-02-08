#include <cub3D.h>

// int	validate_map(t_cub *cub, char **argv)
// {

// }

static int	load_images(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		printf("i = %d\n", i);
		cub->img[i].ptr_img = mlx_xpm_file_to_image(cub->vars.mlx,
				cub->xpm[i], &(cub->img[i].width), &(cub->img[i].height));
		printf("here\n");
		cub->img[i].addr = mlx_get_data_addr(cub->img[i].ptr_img,
				&cub->img[i].bits_per_pixel, &cub->img[i].line_len,
				&cub->img[i].endian);
		printf("here\n");
		i++;
	}
	return (0);
}

static char	**read_map(t_cub *cub, int fd, char **argv)
{
	int		j;
	char	*line;

	j = 0;
	cub->map = (char **)malloc(sizeof(char *) * (get_num_of_rows(argv[1]) + 1));
	if (!cub->map)
		return (cub->map);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		cub->map[j] = line;
		j++;
	}
	cub->map[j] = NULL;
	close(fd);
	return (cub->map);
}

void	init(t_cub *cub, int fd, char **argv)
{
	cub->vars.mlx = mlx_init();
	cub->map = read_map(cub, fd, argv);
	cub->xpm[0] = NORTH;
	cub->xpm[1] = SOUTH;
	cub->xpm[2] = WEST;
	cub->xpm[3] = EAST;
	load_images(cub);
	cub->vars.win = mlx_new_window(cub->vars.mlx, 800, 400, "CUB3D");
}
