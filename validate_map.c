/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katherinefortin <katherinefortin@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:44:23 by kafortin          #+#    #+#             */
/*   Updated: 2023/02/14 16:43:22 by katherinefo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood(char	**map, int x, int y, t_game *game)
{
	while (map[x][y] != WALL && map[x][y] != 'X')
	{
		if (map[x][y] == COLLECTIBLE)
		{
			game->collect_num--;
			map[x][y] = 'X';
			flood(map, x + 1, y, game);
			flood(map, x - 1, y, game);
			flood(map, x, y + 1, game);
			flood(map, x, y - 1, game);
		}
		if (map[x][y] == EXIT)
		{
			game->exit_num--;
			map[x][y] = 'X';
			flood(map, x + 1, y, game);
			flood(map, x - 1, y, game);
			flood(map, x, y + 1, game);
			flood(map, x, y - 1, game);
		}
		if (map[x][y] == '0')
		{
			map[x][y] = 'X';
			flood(map, x + 1, y, game);
			flood(map, x - 1, y, game);
			flood(map, x, y + 1, game);
			flood(map, x, y - 1, game);
		}
		if (map[x][y] == PLAYER)
		{
			map[x][y] = 'X';
			flood(map, x + 1, y, game);
			flood(map, x - 1, y, game);
			flood(map, x, y + 1, game);
			flood(map, x, y - 1, game);
		}
	}
}

void	flood_fill(t_game *game)
{
	t_coordin	play;
	int			collect_num;
	char		**map;
	int			i;

	collect_num = game->collect_num;
	map = malloc(sizeof(char **) * game->lines);
	play = find_player(game);
	i = 0;
	while (game->lines > i)
	{
		map[i] = ft_calloc(sizeof(char), ft_strlen(game->map[i]));
		ft_memmove(map[i], game->map[i], ft_strlen(game->map[i]));
		i++;
	}
	flood(map, play.x, play.y, game);
	if (game->collect_num != 0)
		exit_error("(impossible to get to all the collectibles)\n");
	if (game->exit_num != 0)
		exit_error("(impossible to get to the exit)\n");
	game->collect_num = collect_num;
}

void	validate_characters(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->lines > i)
	{
		j = 0;
		while (game->columns > j)
		{
			if (game->map[i][j] == PLAYER)
				game->player_num++;
			else if (game->map[i][j] == COLLECTIBLE)
				game->collect_num++;
			else if (game->map[i][j] == EXIT)
				game->exit_num++;
			else if (game->map[i][j] != WALL && game->map[i][j] != '0')
				exit_error("(invalid character found)\n");
			j++;
		}
		i++;
	}
	if (game->player_num != 1)
		exit_error("(map should contain exactly one player)\n");
	if (game->collect_num < 1)
		exit_error("(map should have at least one collectible)\n");
	if (game->exit_num != 1)
		exit_error("(map should contain exactly one exit)\n");
}

void	validate_walls(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->columns)
	{
		if (game->map[0][i] != WALL || game->map[game->lines - 1][i] != WALL)
			exit_error("(map should be surrounded by walls)\n");
		if (i < game->lines)
			if (game->map[i][game->columns - 1] != WALL || game->map[i][0] != WALL)
				exit_error("(map should be surrounded by walls)\n");
		i++;
	}
}

void	check_if_rectangle(t_game *game)
{
	int i;

	i = 0;
	while (game->lines > i)
	{
		if (ft_strlen(game->map[i]) != (size_t)game->columns)
			exit_error("(map should be a rectangle)\n");
		i++;
	}
}

void	validate_extension(char *argv)
{
	int	i;

	i = (ft_strlen(argv) - 4);
	if (ft_strncmp(".ber", &argv[i], 4) != 0)
		exit_error("(extension should be .ber)\n");
}

void	validate_map(char *argv, t_game *game)
{
	validate_extension(argv);
	read_map(argv, game);
	check_if_rectangle(game);
	validate_walls(game);
	validate_characters(game);
	flood_fill(game);
	/* FREE MAP LINES + COLUMS + POINTER*/
}
