/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:08:58 by kafortin          #+#    #+#             */
/*   Updated: 2022/05/12 15:43:32 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Searches for the last occurence of the character "c" in the string pointed
to by "*str" and returns the pointer to it.*/
char	*ft_strrchr(const char *str, int c)
{
	int	a;

	a = ft_strlen(str);
	while (a >= 0)
	{
		if (str[a] == (unsigned char)c)
			return ((char *)&str[a]);
		a--;
	}
	return (0);
}
