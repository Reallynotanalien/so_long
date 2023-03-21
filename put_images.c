/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:31:41 by kafortin          #+#    #+#             */
/*   Updated: 2023/03/21 18:45:02 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_game *game, void **image, int x, int y)
{
	mlx_put_image_to_window
		(game->mlx, game->window, image, y * SIZE, x * SIZE);
}

void	put_image_direction(t_game *game, void **image, int direction)
{
	if (direction == POSITION)
		mlx_put_image_to_window
		(game->mlx, game->window, image, game->y * SIZE, game->x * SIZE);
	else if (direction == LEFT)
		mlx_put_image_to_window
		(game->mlx, game->window, image, (game->y + 1) * SIZE, game->x * SIZE);
	else if (direction == RIGHT)
		mlx_put_image_to_window
		(game->mlx, game->window, image, (game->y - 1) * SIZE, game->x * SIZE);
	else if (direction == DOWN)
		mlx_put_image_to_window
		(game->mlx, game->window, image, game->y * SIZE, (game->x - 1) * SIZE);
	else if (direction == UP)
		mlx_put_image_to_window
		(game->mlx, game->window, image, game->y * SIZE, (game->x + 1) * SIZE);
}

void	destroy_images(t_game *game)
{
	mlx_destroy_image(game->mlx, game->sprite.base);
	mlx_destroy_image(game->mlx, game->sprite.play);
	mlx_destroy_image(game->mlx, game->sprite.wall);
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
}
