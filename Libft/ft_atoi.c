/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 19:03:42 by kafortin          #+#    #+#             */
/*   Updated: 2022/11/25 16:11:14 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <limits.h>

/*Converts the string argument "str" to an integer.*/
long	ft_atoi(const char *str)
{
	int		a;
	int		sign;
	long	res;

	a = 0;
	sign = 1;
	res = 0;
	while ((str[a] >= 9 && str[a] <= 13) || str[a] == 32)
		a++;
	if (str[a] == '+' || str[a] == '-')
	{
		if (str[a] == '-')
			sign *= -1;
		a++;
	}
	while (str[a] >= '0' && str[a] <= '9')
	{
		res *= 10;
		res += str[a] - '0';
		a++;
	}
	return (res * sign);
}
