/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:26:32 by kafortin          #+#    #+#             */
/*   Updated: 2023/04/18 16:21:35 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*Initiates all of the necessary t_game struct data and saves the map after 
validating it. Then, initiates a new mlx window with the map and sprites
and starts the game loop.*/
void	start_game(t_game *game)
{
	init_data(game);
	validate_map(game->argv[1], game);
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, (SIZE * game->columns),
			(SIZE * game->lines), "Bonnie & Friends");
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
		exit_error(ARG_ERROR);
	init_game_struct(&game, argv);
	start_game(&game);
	return (0);
}
