/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprzybyl <kprzybyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:16:35 by kprzybyl          #+#    #+#             */
/*   Updated: 2022/02/21 13:20:24 by kprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	long int		res;

	sign = 1;
	res = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -sign;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		if (res < 2147483647)
			res = res * 10 + str[i] - '0';
		else
			break ;
		i++;
	}
	if (res * sign < -2147483648)
		return (0);
	if (res * sign > 2147483647)
		return (-1);
	return (res * sign);
}
