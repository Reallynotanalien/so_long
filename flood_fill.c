/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:43:10 by katherinefo       #+#    #+#             */
/*   Updated: 2023/03/17 18:30:42 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood(char **map, int x, int y, t_game *game)
{
	while (map[x][y] != WALL && map[x][y] != 'X')
	{
		if (map[x][y] == COLLECTIBLE)
			game->temp--;
		else if (map[x][y] == EXIT)
			game->exit_num--;
		map[x][y] = 'X';
		flood(map, x + 1, y, game);
		flood(map, x - 1, y, game);
		flood(map, x, y + 1, game);
		flood(map, x, y - 1, game);
	}
}

char	**create_map_copy(t_game *game)
{
	char	**map_copy;
	int		i;

	map_copy = malloc(sizeof(char **) * game->lines);
	i = 0;
	while (game->lines > i)
	{
		map_copy[i] = ft_calloc(sizeof(char), ft_strlen(game->map[i]));
		ft_memmove(map_copy[i], game->map[i], ft_strlen(game->map[i]));
		i++;
	}
	return (map_copy);
}

void	exit_flood(char **map, int x, int y, t_game *game)
{
	while (map[x][y] != WALL && map[x][y] != 'X' && map[x][y] != EXIT)
	{
		if (map[x][y] == COLLECTIBLE)
			game->temp--;
		map[x][y] = 'X';
		exit_flood(map, x + 1, y, game);
		exit_flood(map, x - 1, y, game);
		exit_flood(map, x, y + 1, game);
		exit_flood(map, x, y - 1, game);
	}
}

bool	exit_blocks_path(t_game *game)
{
	char		**map_copy;

	game->temp = game->collect_num;
	map_copy = create_map_copy(game);
	exit_flood(map_copy, game->x, game->y, game);
	free_map(map_copy, game);
	if (game->temp != 0)
		return (true);
	return (false);
}

void	flood_fill(t_game *game)
{
	char		**map_copy;

	game->temp = game->collect_num;
	map_copy = create_map_copy(game);
	flood(map_copy, game->x, game->y, game);
	free_map(map_copy, game);
	if (game->temp != 0)
		free_and_exit_error(PATH_COLL_ERROR, game);
	if (game->exit_num != 0)
		free_and_exit_error(PATH_EXIT_ERROR, game);
	if (exit_blocks_path(game))
		free_and_exit_error(BLOCKED_ERROR, game);
}
