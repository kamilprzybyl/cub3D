#include <cub3D.h>

static int	is_closed(int i, int j)
{
	if (data()->map[i][j] == '0' \
		|| (data()->map[i][j] != '1' && data()->map[i][j] != ' '))
	{
		if (i == 0 || !data()->map[i + 1] || j == 0 || !data()->map[i][j + 1])
			return (1);
		if (data()->map[i - 1] && data()->map[i - 1][j]
			&& data()->map[i - 1][j] == ' ')
			return (1);
		if (data()->map[i + 1] && data()->map[i + 1][j]
			&& data()->map[i + 1][j] == ' ')
			return (1);
		if (data()->map[i] && data()->map[i][j - 1]
			&& data()->map[i][j - 1] == ' ')
			return (1);
		if (data()->map[i] && data()->map[i][j + 1]
			&& data()->map[i][j + 1] == ' ')
			return (1);
	}
	return (0);
}

static void	initVectors(int x, int y) {

	data()->var.posX = x;
	data()->var.posY = y;
	if (data()->map[y][x] == 'N')
	{
		data()->var.dirX = 0;
		data()->var.dirY = -1; //which dir is positive, which negative?
	}
	else if (data()->map[y][x] == 'S')
	{
		data()->var.dirX = 0;
		data()->var.dirY = 1;
	}
	else if (data()->map[y][x] == 'E')
	{
		data()->var.dirX = 1;
		data()->var.dirY = 0;
	}
	else if (data()->map[y][x] == 'W')
	{
		data()->var.dirX = -1;
		data()->var.dirY = 0;
	}
	data()->var.planeX = 0;
	data()->var.planeY = 0.66;
}

static int	check_chars(void)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (data()->map[i])
	{
		j = 0;
		while (data()->map[i][j])
		{
			if (!ft_strchr(" 10NSEW", data()->map[i][j]))
				return (0);
			if (data()->map[i][j] == 'N' || data()->map[i][j] == 'S' \
				|| data()->map[i][j] == 'E' || data()->map[i][j] == 'W') {
				initVectors(j, i);
				count++;
				}
			j++;
		}
		i++;
	}
	return (count);
}

static int	is_end(int index)
{
	int	i;

	i = index;
	i++;
	while (data()->map[i])
	{
		if (ft_strlen(data()->map[i]) > 0)
			return (1);
		i++;
	}
	data()->map[index] = NULL;
	return (0);
}

int	validate_map(void)
{
	int	i;
	int	j;

	if (ft_arrlen(data()->map) < 3 || check_chars() != 1)
		return (1);
	i = 0;
	while (data()->map[i])
	{
		if (ft_strlen(data()->map[i]) == 0)
		{
			if (is_end(i) == 1)
				return (1);
			break ;
		}
		j = 0;
		while (data()->map[i][j])
		{
			if (is_closed(i, j) == 1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
