/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game_options_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katherinefortin <katherinefortin@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:25:33 by kafortin          #+#    #+#             */
/*   Updated: 2023/03/30 18:24:42 by katherinefo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/*Destroys all the images, clears and destroy the mlx window and frees the map 
before writing "GAME ENDED" to the terminal and exiting the game.*/
int	end_game(t_game *game)
{
	destroy_images(game);
	mlx_clear_window(game->mlx, game->window);
	mlx_destroy_window(game->mlx, game->window);
	free_map(game->map, game);
	ft_putstr_fd("GAME ENDED\n", 1);
	exit(errno);
	return (0);
}

/*Destroys all the images, clears the mlx window, frees the map and starts a new
game.*/
void	reset_game(t_game *game)
{
	destroy_images(game);
	mlx_clear_window(game->mlx, game->window);
	mlx_destroy_window(game->mlx, game->window);
	free_map(game->map, game);
	start_game(game);
}

/*Moves the arrow to the position specified by the direction argument.*/
void	put_arrows(t_game *game, int direction)
{
	int	x;
	int	y;

	x = game->lines / 2;
	y = game->columns / 2;
	put_image(game, game->sprite.start_sign, x, y);
	put_image(game, game->sprite.exit_sign, x + 1, y);
	if (direction == UP)
	{
		put_image(game, game->sprite.black, x + 1, y - 1);
		put_image(game, game->sprite.arrow, x, y - 1);
		game->arrow_position = UP;
	}
	else if (direction == DOWN)
	{
		put_image(game, game->sprite.black, x, y - 1);
		put_image(game, game->sprite.arrow, x + 1, y - 1);
		game->arrow_position = DOWN;
	}
}

/*If the game->arrow_position is UP, resets the game. If it is DOWN, the
game ends.*/
void	select_option(t_game *game)
{
	if (game->arrow_position == UP)
		reset_game(game);
	else if (game->arrow_position == DOWN)
		end_game(game);
}

/*Linked to the mlx_key_hook function, so each time the allowed key is
pressed, it activates the associated function to either move the arrow
up or down, or select an option.*/
int	restart_game(int key, void *game)
{
	if (key == DOWN || key == 1)
		put_arrows(game, DOWN);
	if (key == UP || key == 13)
		put_arrows(game, UP);
	if (key == ENTER)
		select_option(game);
	return (0);
}
