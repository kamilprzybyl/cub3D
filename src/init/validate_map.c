#include <cub3D.h>

static int	check_empty_space(int i, int j)
{
	if (data()->map[i][j] == ' ')
	{
		if (i != 0 && data()->map[i - 1][j] == '0')
			return (1);
		if (data()->map[i + 1] && data()->map[i + 1][j]
			&& data()->map[i + 1][j] == '0')
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

int	validate_map(void)
{
	int	i;
	int	j;

	if (ft_arrlen(data()->map) < 3)
		return (1);
	i = 0;
	while (data()->map[i])
	{
		if (ft_strlen(data()->map[i]) == 0 || data()->map[i][0] == '\n')
			return (1);
		j = 0;
		while (data()->map[i][j])
		{
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
