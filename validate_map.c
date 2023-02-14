/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katherinefortin <katherinefortin@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:44:23 by kafortin          #+#    #+#             */
/*   Updated: 2023/02/14 16:26:59 by katherinefo      ###   ########.fr       */
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
	game->player_num = 0;
	game->collect_num = 0;
	game->exit_num = 0;
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

bool	validate_walls(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < game->columns)
	{
		if (game->map[0][i] != WALL)
			return (false);
		i++;
	}
	while (j < game->lines)
	{
		if (game->map[j][i - 1] != WALL)
			return (false);
		if (game->map[j][0] != WALL)
			return (false);
		j++;
	}
	i = 0;
	while (ft_strlen(game->map[j - 1]) > (size_t)i)
	{
		if (game->map[j - 1][i] != WALL)
			return (false);
		i++;
	}
	return (true);
}

bool	check_if_rectangle(t_game *game)
{
	int i;

	i = 0;
	while (game->lines > i)
	{
		if (ft_strlen(game->map[i]) != (size_t)game->columns)
			return(false);
		i++;
	}
	return(true);
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
	if (!check_if_rectangle(game))
		exit_error("(map should be a rectangle)\n");
	if (!validate_walls(game))
		exit_error("(map should be surrounded by walls)\n");
	validate_characters(game);
	flood_fill(game);
	/* FREE MAP LINES + COLUMS + POINTER*/
}
