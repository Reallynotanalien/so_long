/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:31:55 by kafortin          #+#    #+#             */
/*   Updated: 2023/04/18 16:29:45 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

/*Changes the last location of the player on the map for a '0', meaning it is
now an empty space, according to the direction in which the character moved
and also changes the new location of the player on the map for a 'P'.*/
void	move_player_on_map(t_game *game, int direction)
{
	game->map[game->x][game->y] = 'P';
	if (direction == LEFT)
		game->map[game->x][game->y + 1] = '0';
	else if (direction == RIGHT)
		game->map[game->x][game->y - 1] = '0';
	else if (direction == UP)
		game->map[game->x + 1][game->y] = '0';
	else if (direction == DOWN)
		game->map[game->x - 1][game->y] = '0';
}

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
