/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:31:41 by kafortin          #+#    #+#             */
/*   Updated: 2023/03/17 16:51:13 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_game *game, void **image, int x, int y)
{
	mlx_put_image_to_window
		(game->mlx, game->window, image, y * SIZE, x * SIZE);
}

void	put_arrows(t_game *game)
{
	int	x;
	int	y;

	x = game->lines / 2;
	y = game->columns / 2;
	put_image(game, game->sprite.start_sign, x, y);
	put_image(game, game->sprite.exit_sign, x + 1, y);
	put_image(game, game->sprite.arrow, x, y - 1);
	game->arrow_position = 1;
}
