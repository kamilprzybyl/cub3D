/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprzybyl <kprzybyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:18:17 by kprzybyl          #+#    #+#             */
/*   Updated: 2022/02/21 13:21:48 by kprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	len2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return ((char *)haystack);
	len2 = ft_strlen(needle);
	while (haystack[i] != '\0' && len-- >= len2)
	{
		if (ft_strncmp(&haystack[i], needle, len2) == 0)
			return (&((char *)haystack)[i]);
		i++;
	}
	return (NULL);
}
