#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	if (ft_strlen(&s[start]) < len)
		len = ft_strlen(&s[start]);
	sub = (char *)malloc(sizeof(char) * len + 1);
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, &s[start], len + 1);
	return (sub);
}
