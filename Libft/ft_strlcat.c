#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	len = ft_strlen(dst);
	while (dst[i] != '\0' && i < dstsize)
		i++;
	while (src[j] && i + j + 1 < dstsize)
	{
		((char *)dst)[i + j] = ((char *)src)[j];
		j++;
	}
	if (i + j < dstsize)
		((char *)dst)[i + j] = '\0';
	return (ft_strlen(src) + i);
}
