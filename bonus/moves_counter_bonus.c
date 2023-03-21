/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_counter_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:16:15 by kafortin          #+#    #+#             */
/*   Updated: 2023/03/21 15:06:12 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	putnbr_screen(t_game *game, int moves, int position)
{
	if (moves == 0)
		put_image(game, game->sprite.zero, game->lines, position);
	else if (moves == 1)
		put_image(game, game->sprite.one, game->lines, position);
	else if (moves == 2)
		put_image(game, game->sprite.two, game->lines, position);
	else if (moves == 3)
		put_image(game, game->sprite.three, game->lines, position);
	else if (moves == 4)
		put_image(game, game->sprite.four, game->lines, position);
	else if (moves == 5)
		put_image(game, game->sprite.five, game->lines, position);
	else if (moves == 6)
		put_image(game, game->sprite.six, game->lines, position);
	else if (moves == 7)
		put_image(game, game->sprite.seven, game->lines, position);
	else if (moves == 8)
		put_image(game, game->sprite.eight, game->lines, position);
	else if (moves == 9)
		put_image(game, game->sprite.nine, game->lines, position);
}

void	putnbr_recursive(t_game *game, int moves, int position)
{
	if (moves <= 9 && moves >= 0)
		putnbr_screen(game, moves, position);
	else if (moves >= 10 && moves <= 99)
	{
		putnbr_recursive(game, moves / 10, position);
		putnbr_recursive(game, moves % 10, position + 1);
	}
	else
	{
		putnbr_recursive(game, moves / 10, position);
		putnbr_recursive(game, moves % 10, position + 2);
	}
}

void	put_moves(t_game *game)
{
	game->moves++;
	putnbr_recursive(game, game->moves, 0);
	ft_putnbr_fd(game->moves, 1);
	ft_putstr_fd(" ", 1);
}
