/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katherinefortin <katherinefortin@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:25:03 by kafortin          #+#    #+#             */
/*   Updated: 2023/02/03 15:42:54 by katherinefo      ###   ########.fr       */
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

# ifndef PLAYER
#  define PLAYER 'P'
# endif

# ifndef BORDER
#  define BORDER '1'
# endif

# ifndef EXIT
#  define EXIT 'E'
# endif

# ifndef COLLECTIBLE
#  define COLLECTIBLE 'C'
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