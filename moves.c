/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:31:55 by kafortin          #+#    #+#             */
/*   Updated: 2023/03/17 16:37:35 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game)
{
	game->location.x--;
	if (game->map[game->location.x][game->location.y] == WALL)
		game->location.x++;
	else
	{
		if_collectible(game);
		if (game->map[game->location.x][game->location.y] == EXIT)
		{
			if (!win(game, game->sprite.up_kiss, game->sprite.play))
				game->location.x++;
			return ;
		}
		mlx_put_image_to_window(game->mlx, game->window, game->sprite.base, game->location.y * 32, (game->location.x + 1) * 32);
		mlx_put_image_to_window(game->mlx, game->window, game->sprite.up, game->location.y * 32, game->location.x * 32);
		game_moves(game);
	}
}

void	move_down(t_game *game)
{
	game->location.x++;
	if (game->map[game->location.x][game->location.y] == WALL)
		game->location.x--;
	else
	{
		if_collectible(game);
		if (game->map[game->location.x][game->location.y] == EXIT)
		{
			if (!win(game, game->sprite.down_kiss, game->sprite.up))
				game->location.x--;
			return ;
		}
		mlx_put_image_to_window(game->mlx, game->window, game->sprite.base, game->location.y * 32, (game->location.x - 1) * 32);
		mlx_put_image_to_window(game->mlx, game->window, game->sprite.play, game->location.y * 32, game->location.x * 32);
		game_moves(game);
	}
}

void	move_right(t_game *game)
{
	game->location.y++;
	if (game->map[game->location.x][game->location.y] == WALL)
		game->location.y--;
	else
	{
		if_collectible(game);
		if (game->map[game->location.x][game->location.y] == EXIT)
		{
			if (!win(game, game->sprite.right_kiss, game->sprite.left))
				game->location.y--;
			return ;
		}
		put_image(game, game->sprite.base, game->location.x, (game->location.y - 1));
		put_image(game, game->sprite.right, game->location.x, game->location.y);
		game_moves(game);
	}
}

void	move_left(t_game *game)
{
	game->location.y--;
	if (game->map[game->location.x][game->location.y] == WALL)
		game->location.y++;
	else
	{
		if_collectible(game);
		if (game->map[game->location.x][game->location.y] == EXIT)
		{
			if (!win(game, game->sprite.left_kiss, game->sprite.right))
				game->location.y++;
			return ;
		}
		mlx_put_image_to_window(game->mlx, game->window, game->sprite.base, (game->location.y + 1) * 32, game->location.x * 32);
		mlx_put_image_to_window(game->mlx, game->window, game->sprite.left, game->location.y * 32, game->location.x * 32);
		game_moves(game);
	}
}


int	deal_key(int key, void *game)
{
	if (key == 123)
		move_left(game);
	else if (key == 124)
		move_right(game);
	else if (key == 125)
		move_down(game);
	else if (key == 126)
		move_up(game);
	else if (key == 53)
		end_game(game);
	return (0);
}
