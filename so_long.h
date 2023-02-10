/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katherinefortin <katherinefortin@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:25:03 by kafortin          #+#    #+#             */
/*   Updated: 2023/02/10 14:58:18 by katherinefo      ###   ########.fr       */
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

#endif