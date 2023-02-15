/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katherinefortin <katherinefortin@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:25:03 by kafortin          #+#    #+#             */
/*   Updated: 2023/02/14 20:44:04 by katherinefo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./Libft/libft.h"
# include "./minilibx_opengl_20191021/mlx.h"
# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>

# ifndef SIZE
#  define SIZE 32
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

typedef struct sprites
{
	void		**base;
	void		**play;
	void		**wal;
	void		**coll;
	void		**exit;
	void		**left;
	void		**right;
	void		**up;
	void		**right_kiss;
	void		**exit_sign;
	void		**start_sign;
	void		**arrow;
	void		**zero;
	void		**one;
	void		**two;
	void		**three;
	void		**four;
	void		**five;
	void		**six;
	void		**seven;
	void		**eight;
	void		**nine;
}				t_sprites;

typedef struct game
{
	char		**map;
	void		*mlx_win;
	int			lines;
	int			columns;
	int			player_num;
	int			collect_num;
	int			exit_num;
	int			temp;
	int			fd;
	int			size;
	void		*mlx;
	t_sprites	sprite;
	int			arrow_position;
	int			moves;
	t_coordin	location;
}				t_game;

/*flood_fill*/
void		flood_fill(t_game *game);

/*read_map*/
void		open_map(char *argv, t_game *game);
void		read_map(char *argv, t_game *game);

/*utils*/
void		exit_error(char *error);

/*validate_map*/
void		validate_map(char *argv, t_game *game);

#endif