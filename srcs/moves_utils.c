/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:50:01 by kafortin          #+#    #+#             */
/*   Updated: 2023/04/18 17:41:49 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*Changes the position of the player on the map. This does not impact the
sprites.*/
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

/*Puts the heart image and turns the exit character so that it faces the
player. Then, the restart_game options appear.*/
void	is_win(t_game *game, void **player, void **exit, int direction)
{
	put_image_direction(game, game->sprite.base, POSITION);
	put_image_direction(game, exit, POSITION);
	put_image_direction(game, game->sprite.base, direction);
	put_image_direction(game, player, direction);
	put_moves(game);
	ft_putstr_fd("\nYOU WON!!\n", 1);
	put_arrows(game, UP);
	mlx_key_hook(game->window, restart_game, game);
}

/*Checks if the position that we are on is the exit. If so, checks if all
collectibles have been collected and executes the is_win function if that is
the case. Else, the position will change for the last one to make it appear
as if the character never moved at all and the function will return true. If 
the position is not an exit, then it returns false.*/
bool	is_exit(t_game *game, int direction)
{
	if (game->map[game->x][game->y] == EXIT)
	{
		if (game->collect_num == 0)
		{
			if (direction == LEFT)
				is_win(game, game->sprite.left_kiss, game->sprite.right, LEFT);
			if (direction == RIGHT)
				is_win(game, game->sprite.right_kiss, game->sprite.left, RIGHT);
			if (direction == DOWN)
				is_win(game, game->sprite.down_kiss, game->sprite.up, DOWN);
			if (direction == UP)
				is_win(game, game->sprite.up_kiss, game->sprite.play, UP);
		}
		change_location_on_map(game, direction, FALSE);
		return (true);
	}
	return (false);
}

/*Checks if the next position (depending of the direction sent as an argument)
is a wall. Returns true if it is, false if it is not.*/
bool	is_wall(t_game *game, int direction)
{
	if ((direction == LEFT && (game->map[game->x][game->y - 1] != WALL))
		|| (direction == RIGHT && (game->map[game->x][game->y + 1] != WALL))
		|| (direction == DOWN && (game->map[game->x + 1][game->y] != WALL))
		|| (direction == UP && (game->map[game->x - 1][game->y] != WALL)))
		return (false);
	return (true);
}

/*Checks if the position that we are on is a collectible. If so, changes the 
position for the char '0' and reduces the number of collectibles missing,
then changes the sprite for a base one to make the collectible disappear.*/
void	check_if_collectible(t_game *game)
{
	if (game->map[game->x][game->y] == COLLECTIBLE)
	{
		game->map[game->x][game->y] = 0;
		game->collect_num--;
		put_image_direction(game, game->sprite.base, POSITION);
	}
}
