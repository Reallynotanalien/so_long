/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:14:51 by kafortin          #+#    #+#             */
/*   Updated: 2022/10/11 11:19:25 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Copies a string pointed by "src" to the memory area "dest", without
overflowing the destination buffer.*/
size_t	ft_strlcpy(char *dest, const char *src, size_t dlen)
{
	size_t	a;
	size_t	slen;

	a = 0;
	slen = ft_strlen(src);
	if (dlen == 0)
		return (slen);
	while ((a < (dlen - 1)) && src[a] != '\0')
	{
		dest[a] = src[a];
		a++;
	}
	return (slen);
}
