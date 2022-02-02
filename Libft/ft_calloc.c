#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;

	ret = malloc(size * count);
	if (!ret)
		return (NULL);
	ft_bzero(ret, count * size);
	return (ret);
}
