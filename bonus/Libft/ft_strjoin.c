/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:59:28 by kafortin          #+#    #+#             */
/*   Updated: 2022/05/16 11:15:36 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Allocates (with malloc) and returns a new char string resulting 
from concatenation between s1 and s2.*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new = malloc(sizeof(*s1) * (len1 + len2 + 1));
	if (!new)
		return (NULL);
	ft_memmove(new, s1, len1);
	ft_memmove(new + len1, s2, len2);
	new[len1 + len2] = '\0';
	return (new);
}
