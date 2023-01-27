/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katherinefortin <katherinefortin@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:03:54 by kafortin          #+#    #+#             */
/*   Updated: 2022/10/13 21:19:46 by katherinefo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Allocates (with malloc) and returns a new char string from string "s", 
starting from "start" and for "len" number of characters.*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start > slen)
		return (ft_strdup(""));
	if (len > slen - start)
			len = slen - start;
	new = ft_calloc(sizeof(char), (len + 1));
	if (!(new && s))
		return (NULL);
	ft_memmove(new, s + start, len);
	return (new);
}
