/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katherinefortin <katherinefortin@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:56:49 by katherinefo       #+#    #+#             */
/*   Updated: 2023/02/15 10:45:46 by katherinefo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_sprites(t_game *game)
{
	game->sprite.base = mlx_xpm_file_to_image(game->mlx, "./Assets/tile2.xpm", &game->size, &game->size);
	game->sprite.play = mlx_xpm_file_to_image(game->mlx, "./Assets/character_face.xpm", &game->size, &game->size);
	game->sprite.wal = mlx_xpm_file_to_image(game->mlx, "./Assets/tree.xpm", &game->size, &game->size);
	game->sprite.coll = mlx_xpm_file_to_image(game->mlx, "./Assets/carrot.xpm", &game->size, &game->size);
	game->sprite.exit = mlx_xpm_file_to_image(game->mlx, "./Assets/character_face.xpm", &game->size, &game->size);
	game->sprite.left = mlx_xpm_file_to_image(game->mlx, "./Assets/character_left.xpm", &game->size, &game->size);
	game->sprite.right = mlx_xpm_file_to_image(game->mlx, "./Assets/character_right.xpm", &game->size, &game->size);
	game->sprite.up = mlx_xpm_file_to_image(game->mlx, "./Assets/character_back.xpm", &game->size, &game->size);
	game->sprite.right_kiss = mlx_xpm_file_to_image(game->mlx, "./Assets/character_right_kiss.xpm", &game->size, &game->size);
	game->sprite.arrow = mlx_xpm_file_to_image(game->mlx, "./Assets/arrow.xpm", &game->size, &game->size);
	game->sprite.exit_sign = mlx_xpm_file_to_image(game->mlx, "./Assets/exit_sign.xpm", &game->size, &game->size);
	game->sprite.start_sign = mlx_xpm_file_to_image(game->mlx, "./Assets/start_sign.xpm", &game->size, &game->size);
	game->sprite.zero = mlx_xpm_file_to_image(game->mlx, "./Assets/zero.xpm", &game->size, &game->size);
	game->sprite.one = mlx_xpm_file_to_image(game->mlx, "./Assets/one.xpm", &game->size, &game->size);
	game->sprite.two = mlx_xpm_file_to_image(game->mlx, "./Assets/two.xpm", &game->size, &game->size);
	game->sprite.three = mlx_xpm_file_to_image(game->mlx, "./Assets/three.xpm", &game->size, &game->size);
	game->sprite.four = mlx_xpm_file_to_image(game->mlx, "./Assets/four.xpm", &game->size, &game->size);
	game->sprite.five = mlx_xpm_file_to_image(game->mlx, "./Assets/five.xpm", &game->size, &game->size);
	game->sprite.six = mlx_xpm_file_to_image(game->mlx, "./Assets/six.xpm", &game->size, &game->size);
	game->sprite.seven = mlx_xpm_file_to_image(game->mlx, "./Assets/seven.xpm", &game->size, &game->size);
	game->sprite.eight = mlx_xpm_file_to_image(game->mlx, "./Assets/eight.xpm", &game->size, &game->size);
	game->sprite.nine = mlx_xpm_file_to_image(game->mlx, "./Assets/nine.xpm", &game->size, &game->size);
}

void	init_data(t_game *game)
{
	game->size = SIZE;
	game->lines = 0;
	game->columns = 0;
	game->player_num = 0;
	game->collect_num = 0;
	game->exit_num = 0;
	game->moves = 0;
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
			mlx_put_image_to_window(game->mlx, game->mlx_win, game->sprite.base, y * 32, x * 32);
			if (game->map[x][y] == PLAYER)
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->sprite.play, y * 32, x * 32);
			else if (game->map[x][y] == WALL)
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->sprite.wal, y * 32, x * 32);
			else if (game->map[x][y] == COLLECTIBLE)
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->sprite.coll, y * 32, x * 32);
			else if (game->map[x][y] == EXIT)
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->sprite.exit, y * 32, x * 32);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->sprite.zero, 0, game->lines * 32);
}