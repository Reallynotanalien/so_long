/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:25:03 by kafortin          #+#    #+#             */
/*   Updated: 2023/02/22 18:24:00 by kafortin         ###   ########.fr       */
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
bool	win(t_game *game, void **player, void **exit);
void	if_collectible(t_game *game);
void	destroy_images(t_game *game);

/*end_game_options*/
int		restart_game(int key, void *game);

/*flood_fill*/
void	flood_fill(t_game *game);

/*init*/
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
void	open_map(char *argv, t_game *game);
void	read_map(char *argv, t_game *game);

/*utils*/
void	map_exit_error(char *error);
int		end_game(t_game *game);
void	free_map(char **tab, t_game *game);

/*validate_map*/
void	validate_map(char *argv, t_game *game);

#endif