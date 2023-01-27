/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:32:50 by kafortin          #+#    #+#             */
/*   Updated: 2022/11/23 16:17:21 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Calculates the length of a string.*/
size_t	ft_strlen(const char *str)
{
	size_t	a;

	a = 0;
	while (str[a] != '\0')
	{
		a++;
	}
	return (a);
}
