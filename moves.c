/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:31:55 by kafortin          #+#    #+#             */
/*   Updated: 2023/03/17 18:16:55 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(t_game *game, void **player, char option)
{
	if (!is_wall(game, option))
	{
		is_collectible(game);
		if (!is_exit(game, option))
			move_character(game, player, option);
	}
}

int	deal_key(int key, t_game *game)
{
	if (key == 123)
		move(game, game->sprite.left, 'L');
	else if (key == 124)
		move(game, game->sprite.right, 'R');
	else if (key == 125)
		move(game, game->sprite.play, 'D');
	else if (key == 126)
		move(game, game->sprite.up, 'U');
	else if (key == 53)
		end_game(game);
	return (0);
}
