/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:50:08 by kafortin          #+#    #+#             */
/*   Updated: 2022/05/12 16:03:11 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Allocates a specified amount of memory and initialize it to zero.*/
void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	if (count * size > SIZE_MAX)
		return (NULL);
	p = malloc(count * size);
	if (!p)
		return (NULL);
	ft_bzero(p, (count * size));
	return (p);
}
