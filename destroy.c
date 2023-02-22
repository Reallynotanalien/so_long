/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:38:27 by kafortin          #+#    #+#             */
/*   Updated: 2023/02/22 17:46:44 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_images(t_game *game)
{
	mlx_destroy_image(game->mlx, game->sprite.base);
	mlx_destroy_image(game->mlx, game->sprite.play);
	mlx_destroy_image(game->mlx, game->sprite.wal);
	mlx_destroy_image(game->mlx, game->sprite.coll);
	mlx_destroy_image(game->mlx, game->sprite.exit);
	mlx_destroy_image(game->mlx, game->sprite.left);
	mlx_destroy_image(game->mlx, game->sprite.right);
	mlx_destroy_image(game->mlx, game->sprite.up);
	mlx_destroy_image(game->mlx, game->sprite.right_kiss);
	mlx_destroy_image(game->mlx, game->sprite.down_kiss);
	mlx_destroy_image(game->mlx, game->sprite.up_kiss);
	mlx_destroy_image(game->mlx, game->sprite.left_kiss);
	mlx_destroy_image(game->mlx, game->sprite.arrow);
	mlx_destroy_image(game->mlx, game->sprite.exit_sign);
	mlx_destroy_image(game->mlx, game->sprite.start_sign);
	mlx_destroy_image(game->mlx, game->sprite.zero);
	mlx_destroy_image(game->mlx, game->sprite.one);
	mlx_destroy_image(game->mlx, game->sprite.two);
	mlx_destroy_image(game->mlx, game->sprite.three);
	mlx_destroy_image(game->mlx, game->sprite.four);
	mlx_destroy_image(game->mlx, game->sprite.five);
	mlx_destroy_image(game->mlx, game->sprite.six);
	mlx_destroy_image(game->mlx, game->sprite.seven);
	mlx_destroy_image(game->mlx, game->sprite.eight);
	mlx_destroy_image(game->mlx, game->sprite.nine);
}
