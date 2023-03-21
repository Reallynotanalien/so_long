/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:03:42 by kafortin          #+#    #+#             */
/*   Updated: 2022/10/06 18:28:11 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_str_malloc_copy(char	const *s, char c)
{
	size_t	a;
	size_t	b;
	char	*str;

	a = 0;
	b = 0;
	while (s[a] != '\0' && s[a] == c)
		a++;
	while (s[a] != '\0' && s[a] != c)
	{
		a++;
		b++;
	}
	str = ft_substr(s, (a - b), b);
	return (str);
}

/*Allocates (with malloc) and returns a table of char strings
obtained while separating "s" with char "c" acting as a delimiter
(the table must end with NULL).*/
void	**ft_split(char const *s, char c)
{
	void	**tab;
	char	*temp;
	size_t	a;
	size_t	b;
	size_t	len;

	a = 0;
	b = 0;
	if (!s)
		return (NULL);
	temp = ft_strdup((char *)s);
	if (!temp)
		return (NULL);
	len = ft_count_words(temp, c);
	tab = (void **)ft_calloc(sizeof(char *), (len + 1));
	while (a < len)
	{
		tab[a] = ft_str_malloc_copy((temp + b), c);
		while (temp[b] != '\0' && temp[b] == c)
			b++;
		b += ft_strlen(tab[a]);
		a++;
	}
	free(temp);
	return (tab);
}
