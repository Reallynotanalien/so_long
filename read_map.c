/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:26:15 by katherinefo       #+#    #+#             */
/*   Updated: 2023/03/16 15:41:24 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	malloc_lines(char *argv, t_game *game)
{
	game->fd = open(argv, O_RDONLY);
	if (game->fd < 0)
		free_close_and_exit_error(OPEN_ERROR, game, 3);
	while (get_next_line(game->fd))
		game->lines++;
	if (game->lines == 0)
		free_close_and_exit_error(EMPTY_ERROR, game, 3);
	game->map = malloc(sizeof(char **) * game->lines);
	close(game->fd);
}

void	malloc_columns(char *argv, t_game *game)
{
	int		i;

	i = 0;
	game->fd = open(argv, O_RDONLY);
	if (game->fd < 0)
		free_close_and_exit_error(OPEN_ERROR, game, 0);
	game->columns = ft_strlen(get_next_line(game->fd));
	if (game->columns >= 128)
		free_close_and_exit_error(LINES_ERROR, game, 0);
	while (game->lines > i)
	{
		game->map[i] = ft_calloc(sizeof(char *), game->columns + 1);
		i++;
	}
	close(game->fd);
}

void	read_map(char *argv, t_game *game)
{
	int	i;

	i = 0;
	malloc_lines(argv, game);
	malloc_columns(argv, game);
	//from now on, if I need to exit I need to free all the game->map tab.
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
