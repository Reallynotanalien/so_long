/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 19:47:51 by kafortin          #+#    #+#             */
/*   Updated: 2022/05/12 15:51:06 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Compares the first "n" number of bytes between two memory areas and
returns 0 if both are equal, or the difference between the ascii value of
the first unmatched character if they are not.*/
int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t			a;
	unsigned char	*ss1;
	unsigned char	*ss2;

	a = 0;
	ss1 = (unsigned char *)str1;
	ss2 = (unsigned char *)str2;
	while (a < n)
	{
		if (ss1[a] != ss2[a])
			return (ss1[a] - ss2[a]);
		a++;
	}
	return (0);
}
