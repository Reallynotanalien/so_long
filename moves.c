/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:31:55 by kafortin          #+#    #+#             */
/*   Updated: 2023/03/20 16:57:55 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(t_game *game, void **player, int option)
{
	if (!is_wall(game, option))
	{
		check_if_collectible(game);
		if (!is_exit(game, option))
		{
			if (option == LEFT)
				put_image(game, game->sprite.base, game->x, game->y + 1);
			else if (option == RIGHT)
				put_image(game, game->sprite.base, game->x, game->y - 1);
			else if (option == DOWN)
				put_image(game, game->sprite.base, game->x - 1, game->y);
			else if (option == UP)
				put_image(game, game->sprite.base, game->x + 1, game->y);
			put_image(game, player, game->x, game->y);
			put_moves(game);
		}
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
	else if (key == ESC)
		end_game(game);
	return (0);
}
