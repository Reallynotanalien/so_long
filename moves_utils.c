/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:50:01 by kafortin          #+#    #+#             */
/*   Updated: 2023/03/17 18:30:42 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	is_win(t_game *game, void **player, void **exit, int option)
{
	if (game->collect_num == 0)
	{
		put_image(game, game->sprite.base, game->x, game->y);
		put_image(game, exit, game->x, game->y);
		if (option == 1)
			put_image(game, player, (game->x), game->y + 1);
		else if (option == 2)
			put_image(game, player, (game->x), game->y - 1);
		else if (option == 3)
			put_image(game, player, (game->x - 1), game->y);
		else if (option == 4)
			put_image(game, player, (game->x + 1), game->y);
		game_moves(game);
		ft_putstr_fd("\nYOU WIN!!\n", 1);
		put_arrows(game);
		mlx_key_hook(game->window, restart_game, game);
		return (true);
	}
	return (false);
}

bool	is_exit(t_game *game, int option)
{
	if (game->map[game->x][game->y] == EXIT)
	{
		if (option == LEFT)
			if (!is_win(game, game->sprite.left_kiss, game->sprite.right, 1))
				game->y++;
		if (option == RIGHT)
			if (!is_win(game, game->sprite.right_kiss, game->sprite.left, 2))
				game->y--;
		if (option == DOWN)
			if (!is_win(game, game->sprite.down_kiss, game->sprite.up, 3))
				game->x--;
		if (option == UP)
			if (!is_win(game, game->sprite.up_kiss, game->sprite.play, 4))
				game->x++;
		return (true);
	}
	return (false);
}

bool	is_wall(t_game *game, int option)
{
	if (option == LEFT
		&& (game->map[game->x][game->y - 1] != WALL))
	{
		game->y--;
		return (false);
	}
	else if (option == RIGHT
		&& (game->map[game->x][game->y + 1] != WALL))
	{
		game->y++;
		return (false);
	}
	else if (option == DOWN
		&& (game->map[game->x + 1][game->y] != WALL))
	{
		game->x++;
		return (false);
	}
	else if (option == UP
		&& (game->map[game->x - 1][game->y] != WALL))
	{
		game->x--;
		return (false);
	}
	return (true);
}

void	check_if_collectible(t_game *game)
{
	if (game->map[game->x][game->y] == COLLECTIBLE)
	{
		game->map[game->x][game->y] = 0;
		game->collect_num--;
		put_image(game, game->sprite.base, game->x, game->y);
	}
}
