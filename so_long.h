/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:25:03 by kafortin          #+#    #+#             */
/*   Updated: 2023/02/09 15:48:14 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./Libft/libft.h"
# include "./minilibx_opengl_20191021/mlx.h"
# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef PLAYER
#  define PLAYER 'P'
# endif

# ifndef WALL
#  define WALL '1'
# endif

# ifndef EXIT
#  define EXIT 'E'
# endif

# ifndef COLLECTIBLE
#  define COLLECTIBLE 'C'
# endif

typedef struct coordinates
{
	int	x;
	int	y;
}				t_coordin;

typedef struct game
{
	char	**map;
	void	*mlx_win;
	int		lines;
	int		columns;
	int		player_num;
	int		collect_num;
	int		exit_num;
	int		fd;
}				t_game;

char			*copy_from_src(char *dest, const char *src, unsigned int len);
unsigned int	scan_for_nl(const char *src);
char			*null_calloc(char **str, unsigned int count, unsigned int size);
void			free_if_not_empty(char	**str);
unsigned int	find_len_until(const char *str, const char to_find);

#endif