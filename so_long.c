/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katherinefortin <katherinefortin@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:26:32 by kafortin          #+#    #+#             */
/*   Updated: 2023/02/10 14:51:29 by katherinefo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_coordin	find_player(t_game *game)
{
	t_coordin	axe;

	axe.x = 0;
	while (game->lines > axe.x)
	{
		axe.y = 0;
		while (game->columns > axe.y)
		{
			if (game->map[axe.x][axe.y] == PLAYER)
				return (axe);
			axe.y++;
		}
		axe.x++;
	}
	return (axe);
}

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

bool	flood_fill(t_game *game)
{
	t_coordin	play;
	char		**map;
	int			i;

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
	{
		ft_putstr_fd("Cannot get to all the collectibles\n", 2);
		return (false);
	}
	if (game->exit_num != 0)
	{
		ft_putstr_fd("Cannot get to the exit\n", 2);
		return (false);
	}
	return (true);
}

bool	validate_characters(t_game *game)
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
			{
				ft_putstr_fd("Invalid character found\n", 2);
				return (false);
			}
			j++;
		}
		i++;
	}
	if (game->player_num != 1)
	{
		ft_putstr_fd("Map doesn't have the right amount of players\n", 2);
		return (false);
	}
	if (game->collect_num < 1)
	{
		ft_putstr_fd("Map doesn't have any collectibles\n", 2);
		return (false);
	}
	if (game->exit_num != 1)
	{
		ft_putstr_fd("Map doesn't have the right amount of exits\n", 2);
		return (false);
	}
	return (true);
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

bool	validate_map(char *argv, t_game *game)
{
	if (!validate_extension(argv))
	{
		ft_putstr_fd("Extension is not valid\n", 2);
		return (false);
	}
	read_map(argv, game);
	if(!check_if_rectangle(game))
	{
		ft_putstr_fd("Map is not a rectangle\n", 2);
		return (false);
	}
	if (!validate_walls(game))
	{
		ft_putstr_fd("Map has broken WALLs\n", 2);
		return (false);
	}
	if (!validate_characters(game))
		return (false);
	if (!flood_fill(game))
		return (false);
	/* FREE MAP LINES + COLUMS + POINTER*/
	return (true);
}

int	deal_key(int key, void *param)
{
	ft_putnbr_fd(key, 1);
	if (param == NULL)
		return (0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;
	void	*mlx;
	void	**base;
	void	**play;
	void	**wal;
	void	**coll;
	void	**exit;
	int		size;
	int		x;
	int		y;

	ft_memset(&game, 0, sizeof(t_game));
	size = 32;
	if (argc != 2)
		ft_putstr_fd("Number of arguments is invalid\n", 2);
	if (!validate_map(argv[1], &game))
		ft_putstr_fd("Map is invalid\n", 2);
	mlx = mlx_init();
	game.mlx_win = mlx_new_window(mlx, (size * game.columns), (size * game.lines), "Bonnie & Friends");
	base = mlx_xpm_file_to_image(mlx, "./Assets/tile2.xpm", &size, &size);
	play = mlx_xpm_file_to_image(mlx, "./Assets/character_right.xpm", &size, &size);
	wal = mlx_xpm_file_to_image(mlx, "./Assets/tree.xpm", &size, &size);
	coll = mlx_xpm_file_to_image(mlx, "./Assets/carrot.xpm", &size, &size);
	exit = mlx_xpm_file_to_image(mlx, "./Assets/exit_face.xpm", &size, &size);
	x = 0;
	y = 0;
	while (game.lines > x)
	{
		y = 0;
		while (y < game.columns)
		{	
			mlx_put_image_to_window(mlx, game.mlx_win, base, y * 32, x * 32);
			if (game.map[x][y] == PLAYER)
				mlx_put_image_to_window(mlx, game.mlx_win, play, y * 32, x * 32);
			else if (game.map[x][y] == WALL)
				mlx_put_image_to_window(mlx, game.mlx_win, wal, y * 32, x * 32);
			else if (game.map[x][y] == COLLECTIBLE)
				mlx_put_image_to_window(mlx, game.mlx_win, coll, y * 32, x * 32);
			else if (game.map[x][y] == EXIT)
				mlx_put_image_to_window(mlx, game.mlx_win, exit, y * 32, x * 32);
			y++;
		}
		x++;
	}
	mlx_key_hook(game.mlx_win, deal_key, (void *)0);
	mlx_loop(mlx);
	return (0);
	/*
	- Create an exit function that contains: mlx_destroy_window, mlx_destroy_display + free, mlx_destroy_image */

	/*3- Analyse map and show depending on element mlx_put_image_to_window*/
	/*4- Keyboard interactions: mlx_key_hooks, ft_event_key function (authorizes the character to move)*/
	/*5- Make images appear in a loop (mlx_loop, mlx_hook to close window with X */
}
