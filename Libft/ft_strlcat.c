/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:10:13 by kafortin          #+#    #+#             */
/*   Updated: 2022/05/12 15:38:26 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Concatenates (joins) two strings by putting string "src" at the end of the
memory area "dest", without overflowing the destination buffer.*/
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	slen;
	size_t	dlen;
	size_t	a;

	a = 0;
	slen = ft_strlen(src);
	dlen = ft_strlen(dest);
	if (size == 0)
		return (slen);
	if (size < dlen)
		slen += size;
	else
		slen += dlen;
	if (dlen < size - 1 && size > 0)
	{
		while (src[a] != '\0' && (dlen + a) < size - 1)
		{
			dest[dlen + a] = src[a];
			a++;
		}
		dest[dlen + a] = '\0';
	}
	return (slen);
}
