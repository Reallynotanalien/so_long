/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:43:10 by katherinefo       #+#    #+#             */
/*   Updated: 2023/03/14 18:35:37 by kafortin         ###   ########.fr       */
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

void	flood_fill(t_game *game)
{
	char		**map_copy;

	game->temp = game->collect_num;
	map_copy = create_map_copy(game);
	flood(map_copy, game->location.x, game->location.y, game);
	if (game->temp != 0)
	{
		free_map(game->map, game);
		free_map(map_copy, game);
		exit_error(PATH_COLL_ERROR);
	}
	if (game->exit_num != 0)
	{
		free_map(game->map, game);
		free_map(map_copy, game);
		exit_error(PATH_EXIT_ERROR);
	}
}
