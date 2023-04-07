/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:31:41 by kafortin          #+#    #+#             */
/*   Updated: 2023/04/07 16:59:42 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

/*Shortens the lenght of the destroy_image function to make the norminette happy
by directly sending the image we want to destroy as an argument, then checking 
if the image sent is not empty before destroying it.*/
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
	destroy_if_not_null(game, game->sprite.fox);
	destroy_if_not_null(game, game->sprite.fox_left);
	destroy_if_not_null(game, game->sprite.fox_up);
	destroy_if_not_null(game, game->sprite.fox_down);
	destroy_if_not_null(game, game->sprite.game_over);
	destroy_if_not_null(game, game->sprite.dead);
}

void	flood_map_with_black(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->lines > x)
	{
		y = 0;
		while (y < game->columns)
		{
			put_image(game, game->sprite.black, x, y);
			if (game->map[x][y] == '0')
				game->map[x][y] = 'X';
			y++;
		}
		x++;
	}
}
