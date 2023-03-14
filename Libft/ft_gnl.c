/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:54:58 by katherinefo       #+#    #+#             */
/*   Updated: 2023/02/22 19:24:53 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_gnljoin(char *s, char c)
{
	char	*out;
	int		len;

	len = ft_strlen(s) + 2;
	out = malloc(sizeof(char) * len);
	out[--len] = '\0';
	out[--len] = c;
	if (s)
	{
		while (len--)
			out[len] = s[len];
		free(s);
	}
	return (out);
}

//gnl with auto free
char	*get_next_line(int fd)
{
	char		c;
	static char	*line = NULL;

	if (line)
		free(line);
	line = NULL;
	while (read(fd, &c, 1) && (c != '\n' || line == NULL))
	{
		if (c == '\n')
			continue ;
		line = ft_gnljoin(line, c);
	}
	return (line);
}
