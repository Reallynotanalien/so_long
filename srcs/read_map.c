/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:26:15 by katherinefo       #+#    #+#             */
/*   Updated: 2023/04/18 17:46:38 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*Calculates the number of lines and mallocs that amount of strings to the 
game->map table.*/
void	malloc_lines(char *argv, t_game *game)
{
	game->fd = open(argv, O_RDONLY);
	if (game->fd < 0)
		free_close_and_exit_error(OPEN_ERROR, game, 3);
	while (get_next_line(game->fd))
		game->lines++;
	if (game->lines == 0)
		free_close_and_exit_error(EMPTY_ERROR, game, 3);
	if (game->lines >= HEIGHT)
		free_close_and_exit_error(HEIGHT_ERROR, game, 3);
	game->map = malloc(sizeof(char **) * game->lines);
	close(game->fd);
}

/*Calculates the number of columns and if it is less/equal to 128,
mallocs that amount of characters in each game->map string.*/
void	malloc_columns(char *argv, t_game *game)
{
	int		i;

	i = 0;
	game->fd = open(argv, O_RDONLY);
	if (game->fd < 0)
		free_close_and_exit_error(OPEN_ERROR, game, 0);
	game->columns = ft_strlen(get_next_line(game->fd));
	if (game->columns >= LENGHT)
		free_close_and_exit_error(LENGHT_ERROR, game, 0);
	while (game->lines > i)
	{
		game->map[i] = ft_calloc(sizeof(char *), game->columns + 1);
		i++;
	}
	close(game->fd);
}

/*Mallocs the lines and the columns of the game->map variable, then uses 
get_next_line to read the map file and copies it's content to game->map.*/
void	read_map(char *argv, t_game *game)
{
	int	i;

	i = 0;
	malloc_lines(argv, game);
	malloc_columns(argv, game);
	game->fd = open(argv, O_RDONLY);
	if (game->fd < 0)
		free_close_and_exit_error(OPEN_ERROR, game, 1);
	while (game->lines > i)
	{
		ft_memcpy(game->map[i], get_next_line(game->fd), game->columns + 1);
		i++;
	}	
	close(game->fd);
}
