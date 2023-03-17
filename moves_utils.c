/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:50:01 by kafortin          #+#    #+#             */
/*   Updated: 2023/03/17 18:26:23 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	is_win(t_game *game, void **player, void **exit, int option)
{
	if (game->collect_num == 0)
	{
		put_image(game, game->sprite.base, game->location.x, game->location.y);
		put_image(game, exit, game->location.x, game->location.y);
		if (option == 1)
			put_image(game, player, (game->location.x), game->location.y + 1);
		else if (option == 2)
			put_image(game, player, (game->location.x), game->location.y - 1);
		else if (option == 3)
			put_image(game, player, (game->location.x - 1), game->location.y);
		else if (option == 4)
			put_image(game, player, (game->location.x + 1), game->location.y);
		game_moves(game);
		ft_putstr_fd("\nYOU WIN!!\n", 1);
		put_arrows(game);
		mlx_key_hook(game->window, restart_game, game);
		return (true);
	}
	return (false);
}

void	move_character(t_game *game, void **player, int option)
{
	if (option == LEFT)
		put_image(game, game->sprite.base, game->location.x, (game->location.y + 1));
	else if (option == RIGHT)
		put_image(game, game->sprite.base, game->location.x, (game->location.y - 1));
	else if (option == DOWN)
		put_image(game, game->sprite.base, game->location.x - 1, (game->location.y));
	else if (option == UP)
		put_image(game, game->sprite.base, game->location.x + 1, (game->location.y));
	put_image(game, player, game->location.x, game->location.y);
	game_moves(game);
}

bool	is_exit(t_game *game, int option)
{
	if (game->map[game->location.x][game->location.y] == EXIT)
	{
		if (option == LEFT)
			if (!is_win(game, game->sprite.left_kiss, game->sprite.right, 1))
				game->location.y++;
		if (option == RIGHT)
			if (!is_win(game, game->sprite.right_kiss, game->sprite.left, 2))
				game->location.y--;
		if (option == DOWN)
			if (!is_win(game, game->sprite.down_kiss, game->sprite.up, 3))
				game->location.x--;
		if (option == UP)
			if (!is_win(game, game->sprite.up_kiss, game->sprite.play, 4))
				game->location.x++;
		return (true);
	}
	return (false);
}

bool	is_wall(t_game *game, int option)
{
	if (option == LEFT
		&& (game->map[game->location.x][game->location.y - 1] != WALL))
	{
		game->location.y--;
		return (false);
	}
	else if (option == RIGHT
		&& (game->map[game->location.x][game->location.y + 1] != WALL))
	{
		game->location.y++;
		return (false);
	}
	else if (option == DOWN
		&& (game->map[game->location.x + 1][game->location.y] != WALL))
	{
		game->location.x++;
		return (false);
	}
	else if (option == UP
		&& (game->map[game->location.x - 1][game->location.y] != WALL))
	{
		game->location.x--;
		return (false);
	}
	return (true);
}

void	check_if_collectible(t_game *game)
{
	if (game->map[game->location.x][game->location.y] == COLLECTIBLE)
	{
		game->map[game->location.x][game->location.y] = 0;
		game->collect_num--;
		put_image(game, game->sprite.base, game->location.x, game->location.y);
	}
}
