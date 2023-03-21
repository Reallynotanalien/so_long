/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:24:35 by kafortin          #+#    #+#             */
/*   Updated: 2022/09/28 11:04:08 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Checks whether a character is numeric (0-9) or not.*/
int	ft_isdigit(char a)
{
	if (a >= '0' && a <= '9')
		return (1);
	else
		return (0);
}
