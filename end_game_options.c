/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game_options.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:25:33 by kafortin          #+#    #+#             */
/*   Updated: 2023/02/22 17:57:52 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	reset_game(t_game *game)
{
	mlx_clear_window(game->mlx, game->window);
	start_game(game);
}

void	arrow_down(t_game *game)
{
	int	mid_lines;
	int	mid_columns;

	mid_lines = game->lines / 2;
	mid_columns = game->columns / 2;
	put_image(game, game->sprite.base, mid_lines, mid_columns - 1);
	if (game->map[game->lines / 2][(game->columns / 2) - 1] == WALL)
		put_image(game, game->sprite.wal, mid_lines, mid_columns - 1);
	put_image(game, game->sprite.arrow, mid_lines + 1, mid_columns - 1);
	game->arrow_position = 2;
}

void	arrow_up(t_game *game)
{
	int	mid_lines;
	int	mid_columns;

	mid_lines = game->lines / 2;
	mid_columns = game->columns / 2;
	put_image(game, game->sprite.base, mid_lines + 1, mid_columns - 1);
	if (game->map[(game->lines / 2) + 1][(game->columns / 2) - 1] == WALL)
		put_image(game, game->sprite.wal, mid_lines + 1, mid_columns - 1);
	put_image(game, game->sprite.arrow, mid_lines, mid_columns - 1);
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
