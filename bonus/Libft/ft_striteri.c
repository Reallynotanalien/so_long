/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:36:14 by kafortin          #+#    #+#             */
/*   Updated: 2022/05/10 10:44:43 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Uses function "f" on each character from char string passed as  
an argument, passing by the index as a first argument. Each characters
is transmitted to "f" by their address, so they can be modified if necessary.*/
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int		a;

	if (s)
	{
		a = 0;
		while (s[a] != '\0')
		{
			(*f)(a, s + a);
			a++;
		}
	}
}
