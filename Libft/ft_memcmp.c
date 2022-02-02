#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int					i;
	unsigned char		*temp1;
	unsigned char		*temp2;

	temp1 = (unsigned char *)s1;
	temp2 = (unsigned char *)s2;
	i = 0;
	while (i < (int)n)
	{
		if (temp1[i] != temp2[i])
		{
			return (temp1[i] - temp2[i]);
		}
		i++;
	}
	return (0);
}
