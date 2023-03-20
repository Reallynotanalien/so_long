/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:50:01 by kafortin          #+#    #+#             */
/*   Updated: 2023/03/20 17:50:09 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	change_location_on_map(t_game *game, int direction, int option)
{
	if ((direction == LEFT && option == TRUE)
		|| (direction == RIGHT && option == FALSE))
		game->y--;
	else if ((direction == RIGHT && option == TRUE)
		|| (direction == LEFT && option == FALSE))
		game->y++;
	else if ((direction == DOWN && option == TRUE)
		|| (direction == UP && option == FALSE))
		game->x++;
	else if ((direction == UP && option == TRUE)
		|| (direction == DOWN && option == FALSE))
		game->x--;
}

void	is_win(t_game *game, void **player, void **exit, int option)
{
	put_image(game, game->sprite.base, game->x, game->y);
	put_image(game, exit, game->x, game->y);
	if (option == LEFT)
		put_image(game, player, game->x, game->y + 1);
	else if (option == RIGHT)
		put_image(game, player, game->x, game->y - 1);
	else if (option == DOWN)
		put_image(game, player, game->x - 1, game->y);
	else if (option == UP)
		put_image(game, player, game->x + 1, game->y);
	put_moves(game);
	ft_putstr_fd("\nYOU WON!!\n", 1);
	put_arrows(game);
	mlx_key_hook(game->window, restart_game, game);
}

bool	is_exit(t_game *game, int option)
{
	if (game->map[game->x][game->y] == EXIT)
	{
		if (game->collect_num == 0)
		{
			if (option == LEFT)
				is_win(game, game->sprite.left_kiss, game->sprite.right, LEFT);
			if (option == RIGHT)
				is_win(game, game->sprite.right_kiss, game->sprite.left, RIGHT);
			if (option == DOWN)
				is_win(game, game->sprite.down_kiss, game->sprite.up, DOWN);
			if (option == UP)
				is_win(game, game->sprite.up_kiss, game->sprite.play, UP);
		}
		change_location_on_map(game, option, FALSE);
		return (true);
	}
	return (false);
}

bool	is_wall(t_game *game, int option)
{
	if ((option == LEFT && (game->map[game->x][game->y - 1] != WALL))
		|| (option == RIGHT && (game->map[game->x][game->y + 1] != WALL))
		|| (option == DOWN && (game->map[game->x + 1][game->y] != WALL))
		|| (option == UP && (game->map[game->x - 1][game->y] != WALL)))
		return (false);
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
