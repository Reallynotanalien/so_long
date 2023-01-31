/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:25:03 by kafortin          #+#    #+#             */
/*   Updated: 2023/01/27 18:31:53 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./Libft/libft.h"
# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct game
{
	char	**map;
	int		lines;
	int		columns;
	int		fd;
}				t_game;

char			*get_next_line(int fd);
char			*copy_from_src(char *dest, const char *src, unsigned int len);
unsigned int	scan_for_nl(const char *src);
char			*null_calloc(char **str, unsigned int count, unsigned int size);
void			free_if_not_empty(char	**str);
unsigned int	find_len_until(const char *str, const char to_find);

#endif