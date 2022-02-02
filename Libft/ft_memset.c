#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	count;

	count = 0;
	while (count < len)
	{
		*((unsigned char *)b + count) = (unsigned char)c;
		count++;
	}
	return (b);
}
