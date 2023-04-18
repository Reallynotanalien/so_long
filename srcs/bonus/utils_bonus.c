/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:25:26 by kafortin          #+#    #+#             */
/*   Updated: 2023/04/18 16:29:35 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

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
