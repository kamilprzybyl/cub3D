#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (!dst)
		return (0);
	if (dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	while (src[i] != '\0' && i < dstsize - 1)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	if (dstsize != 0)
		((char *)dst)[i] = '\0';
	return (ft_strlen(src));
}
