/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:31:55 by kafortin          #+#    #+#             */
/*   Updated: 2023/03/17 18:25:51 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(t_game *game, void **player, int option)
{
	if (!is_wall(game, option))
	{
		check_if_collectible(game);
		if (!is_exit(game, option))
			move_character(game, player, option);
	}
}

int	deal_key(int key, t_game *game)
{
	if (key == LEFT)
		move(game, game->sprite.left, LEFT);
	else if (key == RIGHT)
		move(game, game->sprite.right, RIGHT);
	else if (key == DOWN)
		move(game, game->sprite.play, DOWN);
	else if (key == UP)
		move(game, game->sprite.up, UP);
	else if (key == 53)
		end_game(game);
	return (0);
}
