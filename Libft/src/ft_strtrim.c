/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprzybyl <kprzybyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:18:23 by kprzybyl          #+#    #+#             */
/*   Updated: 2022/02/21 13:21:54 by kprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	int		head;
	int		tail;
	int		i;
	int		size;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	head = 0;
	tail = ft_strlen(s1) - 1;
	while (s1[head] != '\0' && ft_strchr(set, s1[head]))
		head++;
	while (tail > 0 && ft_strchr(set, s1[tail]))
		tail--;
	if (head > tail)
		size = 0;
	else
		size = (tail + 1) - head + 1;
	new = (char *)malloc(size);
	if (!new)
		return (NULL);
	ft_strlcpy(new, &s1[head], size);
	return (new);
}
