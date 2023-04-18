/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:18:25 by kafortin          #+#    #+#             */
/*   Updated: 2023/04/18 16:29:52 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

/*Sets the game status to OVER, fills the whole map with the black sprite and
shows the game over screen with the arrows. Activates the restart hook function
so the player can select if they want to exit or restart the game.*/
void	game_over(t_game *game)
{
	int	x;
	int	y;

	x = ((SIZE * game->columns) / 2);
	y = ((SIZE * game->lines) / 2);
	flood_map_with_black(game);
	game->status = OVER;
	if (game->lines > 4)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->sprite.game_over,
			x, y - (2 * SIZE));
		mlx_put_image_to_window(game->mlx, game->window, game->sprite.dead,
			x - (2 * SIZE), y - (2 * SIZE));
	}
	put_arrows(game, UP);
	mlx_key_hook(game->window, restart_game, game);
}

/*Moves the fox horizontally on the map and also changes all of the associated
sprites, unless the fox collides with the player, then the game is over.*/
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

/*Moves the fox vertically on the map and also changes all of the associated
sprites, unless the fox collides with the player, then the game is over.*/
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

/*Moves the fox in a random direction by creating two random numbers, one that
will define if the fox will move vertically or horizontally, and to other to
define whether it will move forward or backwards in that direction. This loop
continues until the game status is set to OVER. The speed is set so that it
does not move too fast, so the fox does not move on each loop.*/
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
	if (game->ennemy == 0 && game->status != OVER && game->status != WIN)
	{
		if (random_value == 0)
			move_fox_horizontally(game, random_direction);
		else if (random_value == 1)
			move_fox_vertically(game, random_direction);
	}
	return (0);
}
