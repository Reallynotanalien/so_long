/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 18:12:00 by kafortin          #+#    #+#             */
/*   Updated: 2022/05/12 15:46:45 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Compares the first "n" number of bytes between two strings and
returns 0 if both are equal, or the difference between the ascii value of
the first unmatched character if they are not.*/
int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	a;

	a = 0;
	while (((unsigned char)str1[a] != '\0' || (unsigned char)str2[a] != '\0') \
	&& (a < n))
	{
		if ((unsigned char)str1[a] != (unsigned char)str2[a])
			return ((unsigned char)str1[a] - (unsigned char)str2[a]);
		a++;
	}
	return (0);
}
