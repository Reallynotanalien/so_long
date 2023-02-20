/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game_options.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:25:33 by kafortin          #+#    #+#             */
/*   Updated: 2023/02/20 18:32:16 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	reset_game(t_game *game)
{
	mlx_clear_window(game->mlx, game->mlx_win);
	start_game(game);
}

void	arrow_down(t_game *game)
{
	put_image(game, game->sprite.base, game->lines / 2, (game->columns / 2) - 1);
	if (game->map[game->lines / 2][(game->columns / 2) - 1] == WALL)
		put_image(game, game->sprite.wal, game->lines / 2, (game->columns / 2) - 1);
	put_image(game, game->sprite.arrow, (game->lines / 2) + 1, (game->columns / 2) - 1);
	game->arrow_position = 2;
}

void	arrow_up(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->sprite.base, ((game->columns / 2) - 1) * 32, ((game->lines / 2) + 1) * 32);
	if (game->map[(game->lines / 2) + 1][(game->columns / 2) - 1] == WALL)
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->sprite.wal, ((game->columns / 2) - 1) * 32, ((game->lines / 2) + 1) * 32);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->sprite.arrow, ((game->columns / 2) - 1) * 32, ((game->lines / 2)) * 32);
	game->arrow_position = 1;
}

void	select_option(t_game *game)
{
	if (game->arrow_position == 1)
		reset_game(game);
	else if (game->arrow_position == 2)
		end_game(game);
}

int	restart_game(int key, void *game)
{
	if (key == 125)
		arrow_down(game);
	if (key == 126)
		arrow_up(game);
	if (key == 36)
		select_option(game);
	return (0);
}
