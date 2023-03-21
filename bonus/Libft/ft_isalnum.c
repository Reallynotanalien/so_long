/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:39:09 by kafortin          #+#    #+#             */
/*   Updated: 2022/05/12 14:59:28 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Checks whether a character is an alphabet or a number.*/
int	ft_isalnum(int a)
{
	if (ft_isalpha(a) == 1 || ft_isdigit(a) == 1)
		return (1);
	else
		return (0);
}
