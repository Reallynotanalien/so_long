/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:56:49 by katherinefo       #+#    #+#             */
/*   Updated: 2023/03/15 18:40:53 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Initializes the t_game struct without mallocating it, and saves argv in it.*/
void	init_game_struct(t_game *game, char **argv)
{
	ft_memset(game, 0, sizeof(t_game));
	game->argv = argv;
}

/*Initializes the t_game struct data (number of lines/columns/players/
collectibles/exits/moves) to zero.*/
void	init_data(t_game *game)
{
	game->lines = 0;
	game->columns = 0;
	game->player_num = 0;
	game->collect_num = 0;
	game->exit_num = 0;
	game->moves = 0;
}

void	**xpm_to_image(t_game *game, char *path)
{
	int		size;
	void	**image;

	size = SIZE;
	image = mlx_xpm_file_to_image(game->mlx, path, &size, &size);
	return (image);
}

void	init_sprites(t_game *game)
{
	game->sprite.base = xpm_to_image(game, "./Assets/tile2.xpm");
	game->sprite.play = xpm_to_image(game, "./Assets/character_face.xpm");
	game->sprite.wal = xpm_to_image(game, "./Assets/tree.xpm");
	game->sprite.coll = xpm_to_image(game, "./Assets/carrot.xpm");
	game->sprite.exit = xpm_to_image(game, "./Assets/character_face.xpm");
	game->sprite.left = xpm_to_image(game, "./Assets/character_left.xpm");
	game->sprite.right = xpm_to_image(game, "./Assets/character_right.xpm");
	game->sprite.up = xpm_to_image(game, "./Assets/character_back.xpm");
	game->sprite.right_kiss = xpm_to_image(game, "./Assets/char_rkiss.xpm");
	game->sprite.down_kiss = xpm_to_image(game, "./Assets/char_dkiss.xpm");
	game->sprite.up_kiss = xpm_to_image(game, "./Assets/char_ukiss.xpm");
	game->sprite.left_kiss = xpm_to_image(game, "./Assets/char_lkiss.xpm");
	game->sprite.arrow = xpm_to_image(game, "./Assets/arrow.xpm");
	game->sprite.exit_sign = xpm_to_image(game, "./Assets/exit_sign.xpm");
	game->sprite.start_sign = xpm_to_image(game, "./Assets/start_sign.xpm");
	game->sprite.zero = xpm_to_image(game, "./Assets/zero.xpm");
	game->sprite.one = xpm_to_image(game, "./Assets/one.xpm");
	game->sprite.two = xpm_to_image(game, "./Assets/two.xpm");
	game->sprite.three = xpm_to_image(game, "./Assets/three.xpm");
	game->sprite.four = xpm_to_image(game, "./Assets/four.xpm");
	game->sprite.five = xpm_to_image(game, "./Assets/five.xpm");
	game->sprite.six = xpm_to_image(game, "./Assets/six.xpm");
	game->sprite.seven = xpm_to_image(game, "./Assets/seven.xpm");
	game->sprite.eight = xpm_to_image(game, "./Assets/eight.xpm");
	game->sprite.nine = xpm_to_image(game, "./Assets/nine.xpm");
}

void	put_image(t_game *game, void **image, int x, int y)
{
	mlx_put_image_to_window
		(game->mlx, game->window, image, y * SIZE, x * SIZE);
}

void	init_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->lines > x)
	{
		y = 0;
		while (y < game->columns)
		{	
			put_image(game, game->sprite.base, x, y);
			if (game->map[x][y] == PLAYER)
				put_image(game, game->sprite.play, x, y);
			else if (game->map[x][y] == WALL)
				put_image(game, game->sprite.wal, x, y);
			else if (game->map[x][y] == COLLECTIBLE)
				put_image(game, game->sprite.coll, x, y);
			else if (game->map[x][y] == EXIT)
				put_image(game, game->sprite.exit, x, y);
			y++;
		}
		x++;
	}
	put_image(game, game->sprite.zero, game->lines, 0);
}
