/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswhitespace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 13:04:22 by kafortin          #+#    #+#             */
/*   Updated: 2022/05/19 13:07:10 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Checks whether a character is a whitespace.*/
int	ft_iswhitespace(int a)
{
	if ((a >= 9 && a <= 13) || a == 32)
		return (1);
	else
		return (0);
}
