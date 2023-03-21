/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:27:11 by kafortin          #+#    #+#             */
/*   Updated: 2022/05/11 10:27:16 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Allocates (with malloc) and returns a copie of char string "s1", 
without "set" characters at the beginning and the end of the string.*/
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	size_t	size;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	size = ft_strlen(s1);
	while (size && ft_strchr(set, s1[size]))
		size--;
	new = ft_substr((char *)s1, 0, size + 1);
	return (new);
}
