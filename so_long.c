/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katherinefortin <katherinefortin@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:26:32 by kafortin          #+#    #+#             */
/*   Updated: 2023/02/03 15:54:55 by katherinefo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	validate_borders(t_game *game)
{
	int	i;
	int	j;
	
	i = 0;
	j = 1;
	while (game->map[0][i] != '\n')
	{
		if (game->map[0][i] != BORDER)
			return (false);
		i++;
	}
	while (j < game->lines)
	{
		if (game->map[j][i - 1] != BORDER)
			return (false);
		if (game->map[j][0] != BORDER)
			return (false);
		j++;
	}
	i = 0;
	while (ft_strlen(game->map[j - 1]) > (size_t)i)
	{
		if (game->map[j - 1][i] != BORDER)
			return (false);
		i++;
	}
	return (true);
}

bool	check_if_rectangle(t_game *game)
{
	int i;

	i = 0;
	while (game->lines > i + 1)
	{
		if (ft_strlen(game->map[i]) - 1 != (size_t)game->columns)
			return(false);
		i++;
	}
	return(true);
}

void	open_map(char *argv, t_game *game)
{
	game->fd = open(argv, O_RDONLY);
	if (game->fd < 0)
		ft_putstr_fd("File could not be opened\n", 2);
}

void	malloc_lines(char *argv, t_game *game)
{
	game->lines = 0;
	open_map(argv, game);
	while (get_next_line(game->fd))
		game->lines++;
	game->map = malloc(sizeof(char **) * game->lines);
	close(game->fd);
}

void	malloc_columns(char *argv, t_game *game)
{
	char	*str;
	// int		i;

	game->columns = 0;
	// i = 0;
	open_map(argv, game);
	str = get_next_line(game->fd);
	while (str[game->columns] != '\n')
		game->columns++;
	free(str);
	// while (game->lines >= i++)
	// 	game->map = ft_calloc(sizeof(char *), game->columns + 1);
	close(game->fd);
}

void	read_map(char *argv, t_game *game)
{
	int	i;

	i = 0;
	malloc_lines(argv, game);
	printf("lines: %i\n", game->lines);
	// malloc_columns(argv, game);
	open_map(argv, game);
	while (game->lines > i)
	{
		game->map[i] = get_next_line(game->fd);
		printf("%s", game->map[i]);
		game->columns = ft_strlen(game->map[i]);
		i++;
	}
	printf("\ncolumns: %i\n", game->columns);
	close(game->fd);
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
	{
		ft_putstr_fd("Extension is not valid\n", 2);
		return (false);
	}
	read_map(argv, &game);
	if(!check_if_rectangle(&game))
	{
		ft_putstr_fd("Map is not a rectangle\n", 2);
		return (false);
	}
	if (!validate_borders(&game))
	{
		ft_putstr_fd("Map has broken borders\n", 2);
		return (false);
	}
	/* MAP ONLY HAS WALLS AT THE BORDERS (1) */
	/* MAP ONLY HAS ONE EXIT (E) */
	/* MAP HAS AT LEAST ONE COLLECTIBLE (C) */
	/* MAP ONLY HAS ONE STARTING POSITION (P) */
	/* MAP CONTAINS A VALID PATH FLOODFILL*/
	/* MAP MUST NOT CONTAINS CHARACTERS OTHER THAN 0, 1, C, P, E) */
	/* FREE MAP LINES + COLUMS + POINTER*/
	return (true);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game.map = NULL;
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
