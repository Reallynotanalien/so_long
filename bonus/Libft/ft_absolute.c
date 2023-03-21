/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_absolute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 10:46:48 by kafortin          #+#    #+#             */
/*   Updated: 2022/05/20 10:54:28 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Returns the absolute value of a number (turns a negative number into a
positive one).*/
long	ft_absolute(long a)
{
	if (a < 0)
		return (a *= -1);
	else
		return (a);
}
