/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 10:22:48 by kafortin          #+#    #+#             */
/*   Updated: 2022/07/15 09:41:48 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*join_free(char *text, const char *buffer)
{
	char			*temp;
	unsigned int	len1;
	unsigned int	len2;

	len1 = find_len_until(text, '\0');
	len2 = find_len_until(buffer, '\0');
	if (!null_calloc(&temp, sizeof (char), (len1 + len2 + 1)))
	{
		free_if_not_empty(&text);
		return (NULL);
	}
	copy_from_src(temp, text, len1);
	copy_from_src(temp + len1, buffer, len2);
	free_if_not_empty(&text);
	return (temp);
}

char	*read_text(int fd, char **text)
{
	char	*buffer;
	int		bytes;

	bytes = BUFFER_SIZE;
	if (!null_calloc(&buffer, sizeof (char), BUFFER_SIZE + 1))
	{
		free_if_not_empty(&*text);
		return (NULL);
	}
	while (bytes == BUFFER_SIZE)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if ((bytes == 0 && find_len_until(*text, '\0') == 0) || bytes == -1)
		{
			free_if_not_empty(&buffer);
			free_if_not_empty(&*text);
			return (NULL);
		}
		buffer[bytes] = '\0';
		*text = join_free(*text, buffer);
		if (scan_for_nl(buffer) == 1)
			break ;
	}
	free_if_not_empty(&buffer);
	return (*text);
}

char	*erase_returned_line(char *text, unsigned int llen)
{
	unsigned int	tlen;
	unsigned int	count;
	char			*temp;

	count = 0;
	tlen = find_len_until(text, '\0');
	if (!null_calloc(&temp, sizeof (char), ((tlen - llen) + 2)))
		temp = NULL;
	while (temp && text[llen - 1] != '\0')
		temp[count++] = text[llen++];
	free_if_not_empty(&text);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char		*text;
	char			*line;
	unsigned int	llen;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!text)
		if (!null_calloc(&text, sizeof (char), 1))
			return (NULL);
	if (scan_for_nl(text) == 0)
		text = read_text(fd, &text);
	if (!text)
		return (NULL);
	llen = find_len_until(text, '\n');
	if (!null_calloc(&line, sizeof (char), (llen + 1)))
	{
		free_if_not_empty(&text);
		return (NULL);
	}
	line = copy_from_src(line, text, (llen - 1));
	text = erase_returned_line(text, llen);
	return (line);
}
