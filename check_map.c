/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:44:23 by kafortin          #+#    #+#             */
/*   Updated: 2023/02/13 18:17:58 by kafortin         ###   ########.fr       */
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

void	open_map(char *argv, t_game *game)
{
	game->fd = open(argv, O_RDONLY);
	if (game->fd < 0)
		ft_putstr_fd("File could not be opened\n", 2);
}

void	malloc_lines(char *argv, t_game *game)
{
	open_map(argv, game);
	while (get_next_line(game->fd))
		game->lines++;
	game->map = malloc(sizeof(char **) * game->lines);
	close(game->fd);
}

void	malloc_columns(char *argv, t_game *game)
{
	int		i;

	game->columns = 0;
	i = 0;
	open_map(argv, game);
	game->columns = ft_strlen(get_next_line(game->fd));
	while (game->lines >= i)
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
		game->columns = ft_strlen(game->map[i]);
		i++;
	}	
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

void	validate_map(char *argv, t_game *game)
{
	if (!validate_extension(argv))
		exit_error("(extension should be .ber)\n");
	read_map(argv, game);
	if (!check_if_rectangle(game))
		exit_error("(map should be a rectangle)\n");
	if (!validate_walls(game))
		exit_error("(map should be surrounded by walls)\n");
	validate_characters(game);
	flood_fill(game);
	/* FREE MAP LINES + COLUMS + POINTER*/
}
