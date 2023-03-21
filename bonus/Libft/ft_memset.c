/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:27:57 by kafortin          #+#    #+#             */
/*   Updated: 2022/11/23 16:17:21 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Fills a block of memory "*b" with character "c", for a specified length.*/
void	*ft_memset(void *b, int c, size_t len)
{
	char	*str;
	size_t	a;

	a = 0;
	str = (char *)b;
	while (len > a)
	{
		str[a] = (unsigned char)c;
		a++;
	}
	return (b);
}
