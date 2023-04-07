/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:31:55 by kafortin          #+#    #+#             */
/*   Updated: 2023/04/07 16:59:35 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/*Puts the number of move on the terminal, followed by a space bar. Also, the
same number is then showed on the bottom of the game window with the use of 
mlx_string_put.*/
void	put_moves(t_game *game)
{
	char	*str;

	game->moves++;
	str = ft_itoa(game->moves);
	ft_putnbr_fd(game->moves, 1);
	ft_putstr_fd("\n", 1);
	mlx_put_image_to_window(game->mlx, game->window,
		game->sprite.black, (2 * (SIZE - 1)), game->lines * SIZE);
	mlx_string_put(game->mlx, game->window,
		(SIZE * 2), (game->lines * SIZE) + (SIZE / 2) - 4, 16777215, str);
	free(str);
}

/*Moves the character in the desired direction specified in the arguments if
it does not encounter a wall or an exit. If it encounters a collectible, the
number of collectibles decreases. The game->moves counter increments with 
each move.*/
void	move(t_game *game, void **player, int direction)
{
	if (!is_wall(game, direction))
	{
		change_location_on_map(game, direction, TRUE);
		check_if_collectible(game);
		if (!is_exit(game, direction))
		{
			if (game->map[game->x][game->y] == FOX)
				game_over(game);
			else
			{
				put_image_direction(game, game->sprite.base, direction);
				move_player_on_map(game, direction);
				put_image_direction(game, player, POSITION);
				put_moves(game);
			}
		}
	}
}

/*Linked to the mlx key hook function, so each time one of the allowed keys is
pressed, it activates the associated move function and sends all of the 
necessary info to it so the character moves in the right direction. If the
ESC key is pressed, the game ends.*/
int	deal_key(int key, t_game *game)
{
	if (key == LEFT || key == 0)
		move(game, game->sprite.left, LEFT);
	else if (key == RIGHT || key == 2)
		move(game, game->sprite.right, RIGHT);
	else if (key == DOWN || key == 1)
		move(game, game->sprite.play, DOWN);
	else if (key == UP || key == 13)
		move(game, game->sprite.up, UP);
	else if (key == ESC)
		end_game(game);
	return (0);
}

int	fox_hook(t_game *game)
{
	int	random_x;
	int	random_y;
	int	speed;

	game->loop++;
	random_x = (rand() % 3) - 1;
	random_y = (rand() % 3) - 1;
	speed = 5555;
	game->ennemy = game->loop % speed;
	if (game->ennemy == 0 && game->status != OVER)
	{
		if (game->map[game->fox.x][game->fox.y + random_y] == '0')
		{
			put_image(game, game->sprite.base, game->fox.x, game->fox.y);
			game->map[game->fox.x][game->fox.y] = '0';
			game->fox.y = game->fox.y + random_y;
			game->map[game->fox.x][game->fox.y] = 'F';
			if (random_y < 0)
				put_image(game, game->sprite.fox_left, game->fox.x, game->fox.y);
			else
				put_image(game, game->sprite.fox, game->fox.x, game->fox.y);
		}
		else if (game->map [game->fox.x][game->fox.y + random_y] == 'P')
		{
			flood_map_with_black(game);
			game->status = OVER;
			put_arrows(game, UP);
			mlx_key_hook(game->window, restart_game, game);
		}
		else if (game->map[game->fox.x + random_x][game->fox.y] == '0')
		{
			put_image(game, game->sprite.base, game->fox.x, game->fox.y);
			game->map[game->fox.x][game->fox.y] = '0';
			game->fox.x = game->fox.x + random_x;
			game->map[game->fox.x][game->fox.y] = 'F';
			if (random_x < 0)
				put_image(game, game->sprite.fox_up, game->fox.x, game->fox.y);
			else
				put_image(game, game->sprite.fox_down, game->fox.x, game->fox.y);
		}
		else if (game->map [game->fox.x + random_x][game->fox.y] == 'P')
		{
			flood_map_with_black(game);
			game->status = OVER;
			put_arrows(game, UP);
			mlx_key_hook(game->window, restart_game, game);
		}
	}
	return (0);
}
