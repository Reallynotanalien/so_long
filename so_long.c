/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:26:32 by kafortin          #+#    #+#             */
/*   Updated: 2023/02/22 18:05:09 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	if_collectible(t_game *game)
{
	if (game->map[game->location.x][game->location.y] == COLLECTIBLE)
	{
		game->map[game->location.x][game->location.y] = 0;
		game->collect_num--;
		put_image(game, game->sprite.base, game->location.x, game->location.y);
	}
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

bool	win(t_game *game, void **player, void **exit)
{
	if (game->collect_num == 0)
	{
		put_image(game, game->sprite.base, game->location.x, game->location.y);
		put_image(game, exit, game->location.x, game->location.y);
		put_image(game, player, (game->location.x), game->location.y - 1);
		game_moves(game);
		ft_putstr_fd("\nYOU WIN!!\n", 1);
		put_arrows(game);
		mlx_key_hook(game->window, restart_game, game);
		return (true);
	}
	return (false);
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

void	start_game(t_game *game)
{
	init_data(game);
	validate_map(game->argv[1], game);
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, (SIZE * game->columns),
			(SIZE * game->lines) + SIZE, "Bonnie & Friends");
	init_sprites(game);
	init_map(game);
	mlx_hook(game->window, 17, 0, end_game, game);
	mlx_key_hook(game->window, deal_key, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_putstr_fd("Number of arguments is invalid\n", 2);
		exit(1);
	}
	ft_memset(&game, 0, sizeof(t_game));
	game.argv = argv;
	start_game(&game);
	return (0);
}
