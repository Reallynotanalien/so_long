/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:05:08 by kafortin          #+#    #+#             */
/*   Updated: 2022/05/12 15:54:37 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Locates the first occurence of the null-terminated string "needle" in the
string "hay", and searches for only "len" number of characters and returns 
a pointer to it.*/
char	*ft_strnstr(const char *hay, const char *needle, size_t len)
{
	size_t	count;
	size_t	index;

	count = 0;
	if (*needle == '\0' || needle == NULL)
		return ((char *)hay);
	while (hay[count] != '\0' && count < len)
	{
		index = 0;
		while (hay[count + index] == needle[index] && count + index < len)
		{
			if (needle[index + 1] == '\0')
				return ((char *)hay + count);
			index++;
		}
		count++;
	}
	return (NULL);
}
