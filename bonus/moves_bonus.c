/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katherinefortin <katherinefortin@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:31:55 by kafortin          #+#    #+#             */
/*   Updated: 2023/03/24 12:42:31 by katherinefo      ###   ########.fr       */
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
			{
				flood_map(game);
				game->status = OVER;
				put_arrows(game, UP);
				mlx_key_hook(game->window, restart_game, game);
			}
			else
			{
				put_image_direction(game, game->sprite.base, direction);
				if (direction == LEFT)
					game->map[game->x][game->y + 1] = '0';
				else if (direction == RIGHT)
					game->map[game->x][game->y - 1] = '0';
				else if (direction == UP)
					game->map[game->x + 1][game->y] = '0';
				else if (direction == DOWN)
					game->map[game->x - 1][game->y] = '0';
				put_image_direction(game, player, POSITION);
				game->map[game->x][game->y] = 'P';
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

void	flood_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->lines > x)
	{
		y = 0;
		while (y < game->columns)
		{	
			if (game->map[x][y] == '0')
				game->map[x][y] = 'X';
			y++;
		}
		x++;
	}
}

int	fox_hook(t_game *game)
{
	int	random_x;
	int	random_y;
	int	speed;

	game->loop++;
	random_x = (rand() % 3) - 1;
	random_y = (rand() % 3) - 1;
	speed = 80;
	game->ennemy = game->loop % speed;
	if (game->ennemy == speed - 1 && game->status != OVER)
	{
		if (random_x > 0)
		{
			if (game->map[game->fox.x + 1][game->fox.y] == '0')
			{
				put_image(game, game->sprite.base, game->fox.x, game->fox.y);
				game->map[game->fox.x][game->fox.y] = '0';
				game->fox.x++;
				game->map[game->fox.x][game->fox.y] = 'F';
				put_image(game, game->sprite.fox, game->fox.x, game->fox.y);
			}
			else if (game->map [game->fox.x + 1][game->fox.y] == 'P')
			{
				flood_map(game);
				game->status = OVER;
				put_arrows(game, UP);
				mlx_key_hook(game->window, restart_game, game);
			}
		}
		else if (random_x < 0)
		{
			if (game->map[game->fox.x - 1][game->fox.y] == '0')
			{
				put_image(game, game->sprite.base, game->fox.x, game->fox.y);
				game->map[game->fox.x][game->fox.y] = '0';
				game->fox.x--;
				game->map[game->fox.x][game->fox.y] = 'F';
				put_image(game, game->sprite.fox, game->fox.x, game->fox.y);
			}
			else if (game->map [game->fox.x - 1][game->fox.y] == 'P')
			{
				flood_map(game);
				game->status = OVER;
				put_arrows(game, UP);
				mlx_key_hook(game->window, restart_game, game);
			}
		}
		else if (random_y < 0)
		{
			if (game->map[game->fox.x][game->fox.y - 1] == '0')
			{
				put_image(game, game->sprite.base, game->fox.x, game->fox.y);
				game->map[game->fox.x][game->fox.y] = '0';
				game->fox.y--;
				game->map[game->fox.x][game->fox.y] = 'F';
				put_image(game, game->sprite.fox, game->fox.x, game->fox.y);
			}
			else if (game->map [game->fox.x][game->fox.y - 1] == 'P')
			{
				flood_map(game);
				game->status = OVER;
				put_arrows(game, UP);
				mlx_key_hook(game->window, restart_game, game);
			}
		}
		else if (random_y > 0)
		{
			if (game->map[game->fox.x][game->fox.y + 1] == '0')
			{
				put_image(game, game->sprite.base, game->fox.x, game->fox.y);
				game->map[game->fox.x][game->fox.y] = '0';
				game->fox.y++;
				game->map[game->fox.x][game->fox.y] = 'F';
				put_image(game, game->sprite.fox, game->fox.x, game->fox.y);
			}
			else if (game->map [game->fox.x][game->fox.y + 1] == 'P')
			{
				flood_map(game);
				game->status = OVER;
				put_arrows(game, UP);
				mlx_key_hook(game->window, restart_game, game);
			}
		}
	}
	return (0);
}
