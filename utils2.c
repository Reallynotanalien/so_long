/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:31:41 by kafortin          #+#    #+#             */
/*   Updated: 2023/03/17 16:22:22 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_game *game, void **image, int x, int y)
{
	mlx_put_image_to_window
		(game->mlx, game->window, image, y * SIZE, x * SIZE);
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

void	put_arrows(t_game *game)
{
	int	x;
	int	y;

	x = game->lines / 2;
	y = game->columns / 2;
	put_image(game, game->sprite.start_sign, x, y);
	put_image(game, game->sprite.exit_sign, x + 1, y);
	put_image(game, game->sprite.arrow, x, y - 1);
	game->arrow_position = 1;
}

bool	win(t_game *game, void **player, void **exit)
{
	if (game->collect_num == 0)
	{
		put_image(game, game->sprite.base, game->location.x, game->location.y);
		put_image(game, exit, game->location.x, game->location.y);
		put_image(game, player, (game->location.x), game->location.y - 1);
		game_moves(game);
		ft_putstr_fd("\nYOU WIN!!\n", 1);
		put_arrows(game);
		mlx_key_hook(game->window, restart_game, game);
		return (true);
	}
	return (false);
}
