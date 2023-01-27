/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:22:50 by kafortin          #+#    #+#             */
/*   Updated: 2022/05/12 15:42:29 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Searches for the first occurence of the character "c" in the string pointed
to by "*str" and returns the pointer to it.*/
char	*ft_strchr(const char *str, int c)
{
	while (*str && *str != (unsigned char)c)
		str++;
	if (*str == (unsigned char)c)
		return ((char *)str);
	return (0);
}
