/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:50:01 by kafortin          #+#    #+#             */
/*   Updated: 2023/03/17 17:28:50 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	wall(t_game *game, char option)
{
	if (option == 'L'
		&& (game->map[game->location.x][game->location.y - 1] != WALL))
	{
		game->location.y--;
		return (false);
	}
	else if (option == 'R'
		&& (game->map[game->location.x][game->location.y + 1] != WALL))
	{
		game->location.y++;
		return (false);
	}
	else if (option == 'D'
		&& (game->map[game->location.x + 1][game->location.y] != WALL))
	{
		game->location.x++;
		return (false);
	}
	else if (option == 'U'
		&& (game->map[game->location.x - 1][game->location.y] != WALL))
	{
		game->location.x--;
		return (false);
	}
	return (true);
}

void	if_collectible(t_game *game)
{
	if (game->map[game->location.x][game->location.y] == COLLECTIBLE)
	{
		game->map[game->location.x][game->location.y] = 0;
		game->collect_num--;
		put_image(game, game->sprite.base, game->location.x, game->location.y);
	}
}

bool	win(t_game *game, void **player, void **exit, int option)
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
