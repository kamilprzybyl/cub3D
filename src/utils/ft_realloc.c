#include <cub3D.h>

char	**ft_realloc(char **ptr, int size)
{
	char	**new_ptr;
	int		i;

	i = 0;
	new_ptr = malloc(sizeof(char *) * size);
	if (!new_ptr)
		return (NULL);
	while (ptr[i])
	{
		new_ptr[i] = ptr[i];
		i++;
	}
	new_ptr[i] = NULL;
	new_ptr[i + 1] = NULL;
	free(ptr);
	return (new_ptr);
}
