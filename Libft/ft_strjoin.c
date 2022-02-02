#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	new = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new)
		return (NULL);
	while (s1[j] != '\0')
	{
		new[j] = s1[j];
		j++;
	}
	while (s2[i] != '\0')
		new[j++] = s2[i++];
	new[j] = '\0';
	return (new);
}
