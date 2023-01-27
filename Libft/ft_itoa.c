/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:39:15 by kafortin          #+#    #+#             */
/*   Updated: 2022/05/20 10:50:52 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_put_num(char *res, int len, long n)
{
	while (len > 0)
	{
		res[len - 1] = (n % 10) + 48;
		n /= 10;
		len--;
	}
	return (res);
}

static int	ft_num_len(long n)
{
	long	a;
	int		len;

	a = 1;
	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len = 1;
		n *= -1;
	}
	while (a <= n)
	{
		a *= 10;
		len++;
	}
	return (len);
}

/*Allocates (with malloc) and returns a char string representing 
int "n" passed as an argument. Negative numbers must be managed.*/
char	*ft_itoa(int n)
{
	int		len;
	char	*res;
	long	nb;

	nb = n;
	len = ft_num_len(nb);
	res = ft_calloc(sizeof(char), len + 1);
	if (!res)
		return (NULL);
	if (nb < 0)
	{
		len--;
		res[0] = '-';
		res = ft_put_num(res + 1, len, ft_absolute(nb));
		res--;
	}
	else
		res = ft_put_num(res, len, nb);
	return (res);
}
