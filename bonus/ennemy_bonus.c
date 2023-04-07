/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:18:25 by kafortin          #+#    #+#             */
/*   Updated: 2023/04/07 17:46:48 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_fox_horizontally(t_game *game, int random)
{
	if (game->map[game->fox.x][game->fox.y + random] == '0')
	{
		put_image(game, game->sprite.base, game->fox.x, game->fox.y);
		game->map[game->fox.x][game->fox.y] = '0';
		game->fox.y = game->fox.y + random;
		game->map[game->fox.x][game->fox.y] = 'F';
		if (random < 0)
			put_image(game, game->sprite.fox_left, game->fox.x, game->fox.y);
		else
			put_image(game, game->sprite.fox, game->fox.x, game->fox.y);
	}
	else if (game->map [game->fox.x][game->fox.y + random] == 'P')
		game_over(game);
}

void	move_fox_vertically(t_game *game, int random)
{
	if (game->map[game->fox.x + random][game->fox.y] == '0')
	{
		put_image(game, game->sprite.base, game->fox.x, game->fox.y);
		game->map[game->fox.x][game->fox.y] = '0';
		game->fox.x = game->fox.x + random;
		game->map[game->fox.x][game->fox.y] = 'F';
		if (random < 0)
			put_image(game, game->sprite.fox_up, game->fox.x, game->fox.y);
		else
			put_image(game, game->sprite.fox_down, game->fox.x, game->fox.y);
	}
	else if (game->map [game->fox.x + random][game->fox.y] == 'P')
		game_over(game);
}

int	fox_hook(t_game *game)
{
	int	random_direction;
	int	random_value;
	int	speed;

	game->loop++;
	random_value = (rand() % 2);
	random_direction = (rand() % 2);
	if (random_direction == 0)
		random_direction = -1;
	speed = 5555;
	game->ennemy = game->loop % speed;
	if (game->ennemy == 0 && game->status != OVER)
	{
		if (random_value == 0)
			move_fox_horizontally(game, random_direction);
		else if (random_value == 1)
			move_fox_vertically(game, random_direction);
	}
	return (0);
}
