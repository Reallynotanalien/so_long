/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:26:32 by kafortin          #+#    #+#             */
/*   Updated: 2023/01/27 18:14:22 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_map(char *argv, t_game *game)
{
	game->map = open(argv, O_RDONLY);
	if (game->map < 0)
		ft_putstr_fd("File could not be opened\n", 2);
}

bool	validate_extension(char *argv)
{
	int	i;

	i = (ft_strlen(argv) - 4);
	if (ft_strncmp(".ber", &argv[i], 4) == 0)
		return (true);
	return (false);
}

bool	validate_map(char *argv, t_game game)
{
	if (!validate_extension(argv))
		return (false);
	open_map(argv, &game);
	/* OPEN MAP AND READ IT WITH GNL */
	/* MAP IS A RECTANGLE */
	/* MAP ONLY HAS WALLS AT THE BORDERS (1) */
	/* MAP ONLY HAS ONE EXIT (E) */
	/* MAP HAS AT LEAST ONE COLLECTIBLE (C) */
	/* MAP ONLY HAS ONE STARTING POSITION (P) */
	/* MAP CONTAINS A VALID PATH */
	/* MAP MUST NOT CONTAINS CHARACTERS OTHER THAN 0, 1, C, P, E) */
	return (true);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game.map = 0;
	if (argc != 2)
		ft_putstr_fd("Number of arguments is invalid\n", 2);
	if (!validate_map(argv[1], game))
		ft_putstr_fd("Map is invalid\n", 2);
	return (0);
	/*1- Parsing*/
	/*- Create a "game" struct and malloc it
	- Initiate MLX
	- XPM files: look for png files and redimension in another size
	- mlx_new_window: creates a new window
	- mlx_xpm_file_to_image
	- Create an exit function that contains: mlx_destroy_window, mlx_destroy_display + free, mlx_destroy_image */

	/*2- Initialize the struct (NULL, or mlx_init)*/
	/*3- Analyse map and show depending on element mlx_put_image_to_window*/
	/*4- Keyboard interactions: mlx_key_hooks, ft_event_key function (authorizes the character to move)*/
	/*5- Make images appear in a loop (mlx_loop, mlx_hook to close window with X */
}
