/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:25:26 by kafortin          #+#    #+#             */
/*   Updated: 2023/04/07 17:13:36 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/*If the character found in the map is a fox, the position is saved and the 
number of foxes is updated in the game struct.*/
void	is_fox(t_game *game, int x, int y)
{
	game->fox_num++;
	game->fox.x = x;
	game->fox.y = y;
}

/*If the character found in the map is a player, the position is saved and the 
number of players is updated in the game struct.*/
void	is_player(t_game *game, int x, int y)
{
	game->player_num++;
	game->x = x;
	game->y = y;
}

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
