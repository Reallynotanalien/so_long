/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:12:46 by kafortin          #+#    #+#             */
/*   Updated: 2022/05/16 11:29:49 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Duplicates string "src" in a new allocated string, and returns a pointer to 
it.*/
char	*ft_strdup(char *src)
{
	int		len;
	char	*copy;

	len = ft_strlen(src);
	copy = ft_calloc(sizeof(char), len + 1);
	if (copy == NULL)
		return (NULL);
	ft_memmove(copy, src, len);
	return (copy);
}
