/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:10:43 by kafortin          #+#    #+#             */
/*   Updated: 2022/05/12 15:21:23 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Copies "n" number of characters from memory area "src" to memory area
"dest", but deals with overlapping memory blocks.*/
void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*temp;
	char	*dest;

	temp = (char *)src;
	dest = (char *)dst;
	if (!temp && !dest)
		return (NULL);
	if (dest > temp)
	{
		while (n > 0)
		{
			((char *)dst)[n - 1] = ((char *)src)[n - 1];
			n--;
		}
	}
	else
		ft_memcpy(dst, src, n);
	return (dst);
}
