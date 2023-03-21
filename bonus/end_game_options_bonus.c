/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game_options_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:25:33 by kafortin          #+#    #+#             */
/*   Updated: 2023/03/21 18:45:02 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	end_game(t_game *game)
{
	destroy_images(game);
	mlx_clear_window(game->mlx, game->window);
	mlx_destroy_window(game->mlx, game->window);
	free_map(game->map, game);
	ft_putstr_fd("GAME ENDED\n", 1);
	exit(1);
	return (0);
}

void	reset_game(t_game *game)
{
	destroy_images(game);
	mlx_clear_window(game->mlx, game->window);
	free_map(game->map, game);
	start_game(game);
}

void	put_arrows(t_game *game, int direction)
{
	int	x;
	int	y;

	x = game->lines / 2;
	y = game->columns / 2;
	put_image(game, game->sprite.start_sign, x, y);
	put_image(game, game->sprite.exit_sign, x + 1, y);
	if (direction == UP)
	{
		put_image(game, game->sprite.base, x + 1, y - 1);
		if (game->map[x + 1][y - 1] == WALL)
			put_image(game, game->sprite.wall, x + 1, y - 1);
		put_image(game, game->sprite.arrow, x, y - 1);
		game->arrow_position = UP;
	}
	else if (direction == DOWN)
	{
		put_image(game, game->sprite.base, x, y - 1);
		if (game->map[x][y - 1] == WALL)
			put_image(game, game->sprite.wall, x, y - 1);
		put_image(game, game->sprite.arrow, x + 1, y - 1);
		game->arrow_position = DOWN;
	}
}

void	select_option(t_game *game)
{
	if (game->arrow_position == UP)
		reset_game(game);
	else if (game->arrow_position == DOWN)
		end_game(game);
}

int	restart_game(int key, void *game)
{
	if (key == DOWN)
		put_arrows(game, DOWN);
	if (key == UP)
		put_arrows(game, UP);
	if (key == ENTER)
		select_option(game);
	return (0);
}