/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:26:15 by katherinefo       #+#    #+#             */
/*   Updated: 2023/03/14 18:26:39 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_map(char *argv, t_game *game)
{
	game->fd = open(argv, O_RDONLY);
	if (game->fd < 0)
	{
		close(game->fd);
		exit_error(OPEN_ERROR);
	}
}

void	malloc_lines(char *argv, t_game *game)
{
	open_map(argv, game);
	while (get_next_line(game->fd))
		game->lines++;
	if (game->lines == 0)
	{
		close(game->fd);
		exit_error(EMPTY_ERROR);
	}
	game->map = malloc(sizeof(char **) * game->lines);
	close(game->fd);
}

void	malloc_columns(char *argv, t_game *game)
{
	int		i;

	i = 0;
	open_map(argv, game);
	game->columns = ft_strlen(get_next_line(game->fd));
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
	open_map(argv, game);
	while (game->lines > i)
	{
		ft_memcpy(game->map[i], get_next_line(game->fd), game->columns + 1);
		i++;
	}	
	close(game->fd);
}
