#include <cub3D.h>

static int	is_closed(int i, int j)
{
	if (data()->map[i][j] == '0')
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

static int	find_char(char character)
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
			if (data()->map[i][j] == character)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

static int	check_chars(void)
{
	int	amount;

	if (!find_char(' ') || !find_char('1') || !find_char('0'))
		return (1);
	amount = 0;
	amount += find_char('N');
	amount += find_char('S');
	amount += find_char('E');
	amount += find_char('W');
	if (amount != 1)
		return (1);
	return (0);
}

int	validate_map(void)
{
	int	i;
	int	j;

	if (ft_arrlen(data()->map) < 3)
		return (1);
	if (check_chars() == 1)
		return (1);
	i = 0;
	while (data()->map[i])
	{
		if (ft_strlen(data()->map[i]) == 0)
			return (1);
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
