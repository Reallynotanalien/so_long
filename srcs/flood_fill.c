/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:43:10 by katherinefo       #+#    #+#             */
/*   Updated: 2023/04/18 16:04:56 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*Recursive function to flood_fill the map.*/
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

/*Mallocs a char ** and returns a copy of the map stored in it.*/
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

/*Recursive function to flood_fill the map.*/
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

/*Basically, another flood fill but this time treats the exit like a wall
to make sure the exit is not blocking the path. If it does, returns true,
else it returns false.*/
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

/*Creates a copy of the map and floods it starting from the player, until 
it has nowhere to go due to walls/exit blocking the way. Then, checks if 
all of the collectibles have been collected and if the exit have been
found, meaning there is a valid path to all of them.*/
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
