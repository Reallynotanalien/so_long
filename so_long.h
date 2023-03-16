/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:25:03 by kafortin          #+#    #+#             */
/*   Updated: 2023/03/16 15:39:51 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./Libft/libft.h"
# include "./minilibx_opengl_20191021/mlx.h"
# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>

# define SIZE 32

# define PLAYER 'P'
# define WALL '1'
# define EXIT 'E'
# define COLLECTIBLE 'C'

# define ARG_ERROR "Number of arguments is invalid.\n"
# define OPEN_ERROR "Map is invalid (file could not be opened).\n"
# define EMPTY_ERROR "Map is invalid (map is empty).\n"
# define EXIT_ERROR "Map is invalid (map should contain exactly one exit).\n"
# define COLL_ERROR "Map is invalid \
(map should contain at least one collectible).\n"
# define PLAY_ERROR "Map is invalid (map should contain exactly one player).\n"
# define EXTENSION_ERROR "Map is invalid (extension should be .ber).\n"
# define RECTANGLE_ERROR "Map is invalid (map should form a rectangle).\n"
# define WALL_ERROR "Map is invalid (map should be surrounded by walls).\n"
# define CHAR_ERROR "Map is invalid (invalid character found).\n"
# define PATH_EXIT_ERROR "Map is invalid (impossible to get to the exit).\n"
# define PATH_COLL_ERROR "Map is invalid \
(impossible to get to all the collectibles).\n"
# define LINES_ERROR "Map is invalid (too many lines).\n"

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
	void		**down_kiss;
	void		**up_kiss;
	void		**left_kiss;
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
	char		**argv;
	char		**map;
	void		*window;
	void		*mlx;
	int			lines;
	int			columns;
	int			player_num;
	int			collect_num;
	int			exit_num;
	int			moves;
	int			temp;
	int			fd;
	int			arrow_position;
	t_sprites	sprite;
	t_coordin	location;
}				t_game;

/*main*/
void	start_game(t_game *game);

/*destroy*/
void	destroy_images(t_game *game);

/*end_game_options*/
int		restart_game(int key, void *game);

/*flood_fill*/
void	flood_fill(t_game *game);

/*init*/
void	init_game_struct(t_game *game, char **argv);
void	init_data(t_game *game);
void	init_sprites(t_game *game);
void	put_image(t_game *game, void **image, int x, int y);
void	init_map(t_game *game);

/*moves_counter*/
void	game_moves(t_game *game);

/*moves*/
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_right(t_game *game);
void	move_left(t_game *game);

/*read_map*/
void	read_map(char *argv, t_game *game);

/*utils*/
void	exit_error(char *error);
void	free_close_and_exit_error(char *error, t_game *game, int option);
int		end_game(t_game *game);
void	free_map(char **tab, t_game *game);

/*utils2*/
void	if_collectible(t_game *game);
void	put_arrows(t_game *game);
bool	win(t_game *game, void **player, void **exit);
int		deal_key(int key, void *game);

/*validate_map*/
void	validate_map(char *argv, t_game *game);

#endif