/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:31:41 by kafortin          #+#    #+#             */
/*   Updated: 2023/04/18 16:21:23 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*Shortens the lenght of the mlx_put_image_to_window function to make the
norminette happy.*/
void	put_image(t_game *game, void **image, int x, int y)
{
	mlx_put_image_to_window
		(game->mlx, game->window, image, y * SIZE, x * SIZE);
}

/*Shortens the lenght of the put_image function to make the norminette happy
by already having some directions defined instead of re-writing the 
coordinates all the time. Also makes everything looks cleaner and less 
confusing.*/
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

void	destroy_if_not_null(t_game *game, void **image)
{
	if (image)
		mlx_destroy_image(game->mlx, image);
}

/*Destroys all of the image pointers.*/
void	destroy_images(t_game *game)
{
	destroy_if_not_null(game, game->sprite.base);
	destroy_if_not_null(game, game->sprite.play);
	destroy_if_not_null(game, game->sprite.wall);
	destroy_if_not_null(game, game->sprite.collect);
	destroy_if_not_null(game, game->sprite.exit);
	destroy_if_not_null(game, game->sprite.left);
	destroy_if_not_null(game, game->sprite.right);
	destroy_if_not_null(game, game->sprite.up);
	destroy_if_not_null(game, game->sprite.right_kiss);
	destroy_if_not_null(game, game->sprite.down_kiss);
	destroy_if_not_null(game, game->sprite.up_kiss);
	destroy_if_not_null(game, game->sprite.left_kiss);
	destroy_if_not_null(game, game->sprite.arrow);
	destroy_if_not_null(game, game->sprite.exit_sign);
	destroy_if_not_null(game, game->sprite.start_sign);
}
