/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 10:41:42 by kafortin          #+#    #+#             */
/*   Updated: 2022/05/20 10:51:56 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Counts the number of words in a pointed string, using a char delimitator.*/
size_t	ft_count_words(char const *s, char sep)
{
	size_t	l;
	size_t	words;
	char	*str;

	l = 0;
	words = 0;
	if (ft_strlen(s) == 0)
		return (0);
	if (sep == '\0')
		return (1);
	str = ft_strtrim(s, &sep);
	if (!str)
		return (0);
	while (str[l])
	{
		while (str[l] && str[l] != sep)
			l++;
		while (str[l] == sep)
			l++;
		words++;
	}
	free(str);
	return (words);
}
