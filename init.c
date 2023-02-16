/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:56:49 by katherinefo       #+#    #+#             */
/*   Updated: 2023/02/16 15:55:11 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	int	size;

	size = SIZE;
	game->sprite.base = xpm_to_image(game, "./Assets/tile2.xpm");
	game->sprite.play = xpm_to_image(game, "./Assets/character_face.xpm");
	game->sprite.wal = xpm_to_image(game, "./Assets/tree.xpm");
	game->sprite.coll = xpm_to_image(game, "./Assets/carrot.xpm");
	game->sprite.exit = xpm_to_image(game, "./Assets/character_face.xpm");
	game->sprite.left = xpm_to_image(game, "./Assets/character_left.xpm");
	game->sprite.right = xpm_to_image(game, "./Assets/character_right.xpm");
	game->sprite.up = xpm_to_image(game, "./Assets/character_back.xpm");
	game->sprite.right_kiss = xpm_to_image(game, "./Assets/char_rkiss.xpm");
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

void	init_data(t_game *game)
{
	game->lines = 0;
	game->columns = 0;
	game->player_num = 0;
	game->collect_num = 0;
	game->exit_num = 0;
	game->moves = 0;
}

void	put_image(t_game *game, void **image, int x, int y)
{
	mlx_put_image_to_window
		(game->mlx, game->mlx_win, image, y * SIZE, x * SIZE);
}

void	init_game_start(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
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
