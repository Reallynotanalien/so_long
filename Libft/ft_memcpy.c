/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:33:20 by kafortin          #+#    #+#             */
/*   Updated: 2022/05/12 15:18:52 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Copies "n" number of characters from memory area "src" to memory area 
"dest".*/
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	a;

	a = 0;
	if (!dest && !src)
		return (NULL);
	while (a < n)
	{
		((char *)dest)[a] = ((char *)src)[a];
		a++;
	}
	return (dest);
}
