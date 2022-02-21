/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprzybyl <kprzybyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:18:04 by kprzybyl          #+#    #+#             */
/*   Updated: 2022/02/21 13:21:34 by kprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

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
