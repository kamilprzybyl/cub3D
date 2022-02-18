#include <cub3D.h>

t_cub	*data(void)
{
	static t_cub	data;

	return (&data);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "Error\nMap not provided\n", 23);
		return (1);
	}
	parse(argv[1]);
	init();
	// for (int i = 0; data()->map[i]; i++) {
	// 	printf("[%s]\n", data()->map[i]);
	// }
	launch();
	return (0);
}
