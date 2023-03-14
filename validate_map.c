/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:44:23 by kafortin          #+#    #+#             */
/*   Updated: 2023/03/14 18:33:35 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_characters(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->lines > x)
	{
		y = 0;
		while (game->columns > y)
		{
			if (game->map[x][y] == PLAYER)
			{
				game->player_num++;
				game->location.x = x;
				game->location.y = y;
			}
			else if (game->map[x][y] == COLLECTIBLE)
				game->collect_num++;
			else if (game->map[x][y] == EXIT)
				game->exit_num++;
			else if (game->map[x][y] != WALL && game->map[x][y] != '0')
			{
				free_map(game->map, game);
				exit_error(CHAR_ERROR);
			}
			y++;
		}
		x++;
	}
}

void	validate_walls(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->columns)
	{
		if (game->map[0][i] != WALL || game->map[game->lines - 1][i] != WALL)
		{
			free_map(game->map, game);
			exit_error(WALL_ERROR);
		}
		if (i < game->lines && (game->map[i][game->columns - 1] != WALL
			|| game->map[i][0] != WALL))
		{
			free_map(game->map, game);
			exit_error(WALL_ERROR);
		}
		i++;
	}
}

void	check_if_rectangle(t_game *game)
{
	int	i;

	i = 0;
	while (game->lines > i)
	{
		if (ft_strlen(game->map[i]) != (size_t)game->columns)
		{
			free_map(game->map, game);
			exit_error(RECTANGLE_ERROR);
		}
		i++;
	}
}

void	validate_extension(char *argv)
{
	int	i;

	i = (ft_strlen(argv) - 4);
	if (ft_strncmp(".ber", &argv[i], 4) != 0)
		exit_error(EXTENSION_ERROR);
}

void	validate_map(char *argv, t_game *game)
{
	validate_extension(argv);
	read_map(argv, game);
	check_if_rectangle(game);
	validate_walls(game);
	validate_characters(game);
	if (game->player_num != 1)
		exit_error(PLAY_ERROR);
	if (game->collect_num < 1)
		exit_error(COLL_ERROR);
	if (game->exit_num != 1)
		exit_error(EXIT_ERROR);
	flood_fill(game);
	/* FREE MAP LINES + COLUMS + POINTER*/
}
