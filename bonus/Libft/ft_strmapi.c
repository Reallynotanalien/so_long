/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:36:14 by kafortin          #+#    #+#             */
/*   Updated: 2022/05/09 16:01:55 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Uses function "f" on each character from char string passed as  
an argument to create a new char string (with malloc), resulting from
the consecutive use of function "f".*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	int		len;
	int		a;

	if (!s)
		return (NULL);
	a = 0;
	len = ft_strlen(s);
	new = malloc(sizeof(char) * len + 1);
	if (!new)
		return (NULL);
	while (s[a] != '\0')
	{
		new[a] = f(a, s[a]);
		a++;
	}
	new[a] = '\0';
	return (new);
}
