/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:54:58 by katherinefo       #+#    #+#             */
/*   Updated: 2023/04/14 17:46:40 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*null_calloc(char **str, unsigned int count, unsigned int size)
{
	void			*p;
	unsigned int	index;

	index = 0;
	p = malloc(count * size);
	if (p == ((void *)0))
		return (NULL);
	while ((count * size) > index)
		((char *)p)[index++] = 0;
	*str = p;
	if (!*str)
		return (NULL);
	return (*str);
}

char	*join(char *s, char c)
{
	char	*out;
	int		len;

	len = ft_strlen(s) + 2;
	if (!null_calloc(&out, sizeof(char), len + 1))
	{
		ft_putstr_fd(MALLOC_ERROR, 2);
		return (NULL);
	}
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

char	*get_next_line(int fd)
{
	char		c;
	static char	*text;

	if (fd < 0)
		return (0);
	if (text)
		free(text);
	text = NULL;
	while (read(fd, &c, 1) && (c != '\n' || text == NULL))
	{
		if (text == NULL && c == '\n')
			return ("\n");
		if (c == '\n')
			continue ;
		text = join(text, c);
	}
	return (text);
}
