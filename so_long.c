/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katherinefortin <katherinefortin@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:26:32 by kafortin          #+#    #+#             */
/*   Updated: 2023/02/10 21:27:34 by katherinefo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	putnbr_screen(t_game *game, int moves, int position)
{
	if (moves <= 9 && moves >= 0)
	{
		if (moves == 0)
			mlx_put_image_to_window(game->mlx, game->mlx_win, game->zero, position, game->lines * 32);
		else if (moves == 1)
			mlx_put_image_to_window(game->mlx, game->mlx_win, game->one, position, game->lines * 32);
		else if (moves == 2)
			mlx_put_image_to_window(game->mlx, game->mlx_win, game->two, position, game->lines * 32);
		else if (moves == 3)
			mlx_put_image_to_window(game->mlx, game->mlx_win, game->three, position, game->lines * 32);
	}
	else if (moves >= 10 && moves <= 99)
	{
		putnbr_screen(game, moves / 10, position);
		putnbr_screen(game, moves % 10, position + 32);
	}
	// else
	// {
	// 	putnbr_screen(game, moves / 10, position);
	// 	putnbr_screen(game, moves % 100, position + 64);
	// }
}

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
	{
		ft_putstr_fd("Cannot get to all the collectibles\n", 2);
		return (false);
	}
	if (game->exit_num != 0)
	{
		ft_putstr_fd("Cannot get to the exit\n", 2);
		return (false);
	}
	game->collect_num = collect_num;
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

int	end_game(t_game *game)
{
	mlx_clear_window(game->mlx, game->mlx_win);
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit(0);
	return (0);
}

void	arrow_down(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->base, ((game->columns / 2) - 1) * 32, (game->lines / 2) * 32);
	if (game->map[game->lines / 2][(game->columns / 2) - 1] == WALL)
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->wal, ((game->columns / 2) - 1) * 32, (game->lines / 2) * 32);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->arrow, ((game->columns / 2) - 1) * 32, ((game->lines / 2) + 1) * 32);
	game->arrow_position = 2;
}

void	arrow_up(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->base, ((game->columns / 2) - 1) * 32, ((game->lines / 2) + 1) * 32);
	if (game->map[(game->lines / 2) + 1][(game->columns / 2) - 1] == WALL)
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->wal, ((game->columns / 2) - 1) * 32, ((game->lines / 2) + 1) * 32);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->arrow, ((game->columns / 2) - 1) * 32, ((game->lines / 2)) * 32);
	game->arrow_position = 1;
}

void	select_option(t_game *game)
{
	if (game->arrow_position == 1)
		ft_putstr_fd("RESTART\n", 1);
	else if (game->arrow_position == 2)
		end_game(game);
}

int	restart_game(int key, void *game)
{
	if (key == 125)
		arrow_down(game);
	if (key == 126)
		arrow_up(game);
	if (key == 36)
		select_option(game);
	return (0);
}

void	move_up(t_game *game)
{
	game->location.x--;
	if (game->map[game->location.x][game->location.y] == WALL)
		game->location.x++;
	else
	{
		if (game->map[game->location.x][game->location.y] == COLLECTIBLE)
		{
			game->map[game->location.x][game->location.y] = 0;
			game->collect_num--;
			mlx_put_image_to_window(game->mlx, game->mlx_win, game->base, game->location.y * 32, game->location.x *32);
		}
		else if (game->map[game->location.x][game->location.y] == EXIT)
		{
			if (game->collect_num == 0)
			{
				game->moves++;
				putnbr_screen(game, game->moves, 0);
				ft_putnbr_fd(game->moves, 1);
				ft_putstr_fd("\n", 1);
				ft_putstr_fd("YOU WIN!!\n", 1);
				return ;
			}
			else
				game->location.x++;
		}
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->base, game->location.y * 32, (game->location.x + 1) * 32);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->up, game->location.y * 32, game->location.x * 32);
		game->moves++;
		putnbr_screen(game, game->moves, 0);
		ft_putnbr_fd(game->moves, 1);
		ft_putstr_fd("\n", 1);
	}
}

void	move_down(t_game *game)
{
	game->location.x++;
	if (game->map[game->location.x][game->location.y] == WALL)
		game->location.x--;
	else
	{
		if (game->map[game->location.x][game->location.y] == COLLECTIBLE)
		{
			game->map[game->location.x][game->location.y] = 0;
			game->collect_num--;
			mlx_put_image_to_window(game->mlx, game->mlx_win, game->base, game->location.y * 32, game->location.x *32);
		}
		else if (game->map[game->location.x][game->location.y] == EXIT)
		{
			if (game->collect_num == 0)
			{
				game->moves++;
				putnbr_screen(game, game->moves, 0);
				ft_putnbr_fd(game->moves, 1);
				ft_putstr_fd("\n", 1);
				ft_putstr_fd("YOU WIN!!\n", 1);
				return ;
			}
			else
				game->location.x--;
		}
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->base, game->location.y * 32, (game->location.x - 1) * 32);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->play, game->location.y * 32, game->location.x * 32);
		game->moves++;
		putnbr_screen(game, game->moves, 0);
		ft_putnbr_fd(game->moves, 1);
		ft_putstr_fd("\n", 1);
	}
}

void	move_right(t_game *game)
{
	game->location.y++;
	if (game->map[game->location.x][game->location.y] == WALL)
		game->location.y--;
	else
	{
		if (game->map[game->location.x][game->location.y] == COLLECTIBLE)
		{
			game->map[game->location.x][game->location.y] = 0;
			game->collect_num--;
			mlx_put_image_to_window(game->mlx, game->mlx_win, game->base, game->location.y * 32, game->location.x *32);
		}
		else if (game->map[game->location.x][game->location.y] == EXIT)
		{
			if (game->collect_num == 0)
			{
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->base, game->location.y * 32, game->location.x * 32);
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->left, game->location.y * 32, game->location.x * 32);
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->right_kiss, (game->location.y - 1) * 32, game->location.x * 32);
				game->moves++;
				putnbr_screen(game, game->moves, 0);
				ft_putnbr_fd(game->moves, 1);
				ft_putstr_fd("\n", 1);
				ft_putstr_fd("YOU WIN!!\n", 1);
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->start_sign, (game->columns / 2) * 32, (game->lines / 2) * 32);
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->exit_sign, (game->columns / 2) * 32, ((game->lines / 2) + 1) * 32);
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->arrow, ((game->columns / 2) - 1) * 32, (game->lines / 2) * 32);
				game->arrow_position = 1;
				mlx_key_hook(game->mlx_win, restart_game, game);
				return ;
			}
			else
				game->location.y--;
		}
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->base, (game->location.y - 1) * 32, game->location.x * 32);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->right, game->location.y * 32, game->location.x * 32);
		game->moves++;
		putnbr_screen(game, game->moves, 0);
		ft_putnbr_fd(game->moves, 1);
		ft_putstr_fd("\n", 1);
	}
}

void	move_left(t_game *game)
{
	game->location.y--;
	if (game->map[game->location.x][game->location.y] == WALL)
		game->location.y++;
	else
	{
		if (game->map[game->location.x][game->location.y] == COLLECTIBLE)
		{
			game->map[game->location.x][game->location.y] = 0;
			game->collect_num--;
			mlx_put_image_to_window(game->mlx, game->mlx_win, game->base, game->location.y * 32, game->location.x *32);
		}
		else if (game->map[game->location.x][game->location.y] == EXIT)
		{
			if (game->collect_num == 0)
			{
				game->moves++;
				putnbr_screen(game, game->moves, 0);
				ft_putnbr_fd(game->moves, 1);
				ft_putstr_fd("\n", 1);
				ft_putstr_fd("YOU WIN!!\n", 1);
				return ;
			}
			else
				game->location.y++;
		}
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->base, (game->location.y + 1) * 32, game->location.x * 32);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->left, game->location.y * 32, game->location.x * 32);
		game->moves++;
		putnbr_screen(game, game->moves, 0);
		ft_putnbr_fd(game->moves, 1);
		ft_putstr_fd("\n", 1);
	}
}

int	deal_key(int key, void *game)
{
	if (key == 123)
		move_left(game);
	else if (key == 124)
		move_right(game);
	else if (key == 125)
		move_down(game);
	else if (key == 126)
		move_up(game);
	else if (key == 53)
		end_game(game);
	return (0);
}

void	initialize_sprites(t_game *game)
{
	game->base = mlx_xpm_file_to_image(game->mlx, "./Assets/tile2.xpm", &game->size, &game->size);
	game->play = mlx_xpm_file_to_image(game->mlx, "./Assets/character_face.xpm", &game->size, &game->size);
	game->wal = mlx_xpm_file_to_image(game->mlx, "./Assets/tree.xpm", &game->size, &game->size);
	game->coll = mlx_xpm_file_to_image(game->mlx, "./Assets/carrot.xpm", &game->size, &game->size);
	game->exit = mlx_xpm_file_to_image(game->mlx, "./Assets/character_face.xpm", &game->size, &game->size);
	game->left = mlx_xpm_file_to_image(game->mlx, "./Assets/character_left.xpm", &game->size, &game->size);
	game->right = mlx_xpm_file_to_image(game->mlx, "./Assets/character_right.xpm", &game->size, &game->size);
	game->up = mlx_xpm_file_to_image(game->mlx, "./Assets/character_back.xpm", &game->size, &game->size);
	game->right_kiss = mlx_xpm_file_to_image(game->mlx, "./Assets/character_right_kiss.xpm", &game->size, &game->size);
	game->arrow = mlx_xpm_file_to_image(game->mlx, "./Assets/arrow.xpm", &game->size, &game->size);
	game->exit_sign = mlx_xpm_file_to_image(game->mlx, "./Assets/exit_sign.xpm", &game->size, &game->size);
	game->start_sign = mlx_xpm_file_to_image(game->mlx, "./Assets/start_sign.xpm", &game->size, &game->size);
	game->zero = mlx_xpm_file_to_image(game->mlx, "./Assets/zero.xpm", &game->size, &game->size);
	game->one = mlx_xpm_file_to_image(game->mlx, "./Assets/one.xpm", &game->size, &game->size);
	game->two = mlx_xpm_file_to_image(game->mlx, "./Assets/two.xpm", &game->size, &game->size);
	game->three = mlx_xpm_file_to_image(game->mlx, "./Assets/three.xpm", &game->size, &game->size);
}

int	main(int argc, char **argv)
{
	t_game	game;
	int		x;
	int		y;

	ft_memset(&game, 0, sizeof(t_game));
	game.size = SIZE;
	if (argc != 2)
		ft_putstr_fd("Number of arguments is invalid\n", 2);
	if (!validate_map(argv[1], &game))
		ft_putstr_fd("Map is invalid\n", 2);
	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx, (SIZE * game.columns), (SIZE * game.lines) + SIZE, "Bonnie & Friends");
	initialize_sprites(&game);
	game.location = find_player(&game);
	game.moves = 0;
	x = 0;
	y = 0;
	while (game.lines > x)
	{
		y = 0;
		while (y < game.columns)
		{	
			mlx_put_image_to_window(game.mlx, game.mlx_win, game.base, y * 32, x * 32);
			if (game.map[x][y] == PLAYER)
				mlx_put_image_to_window(game.mlx, game.mlx_win, game.play, y * 32, x * 32);
			else if (game.map[x][y] == WALL)
				mlx_put_image_to_window(game.mlx, game.mlx_win, game.wal, y * 32, x * 32);
			else if (game.map[x][y] == COLLECTIBLE)
				mlx_put_image_to_window(game.mlx, game.mlx_win, game.coll, y * 32, x * 32);
			else if (game.map[x][y] == EXIT)
				mlx_put_image_to_window(game.mlx, game.mlx_win, game.exit, y * 32, x * 32);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(game.mlx, game.mlx_win, game.zero, 0, game.lines * 32);
	mlx_hook(game.mlx_win, 17, 0, end_game, &game);
	mlx_key_hook(game.mlx_win, deal_key, &game);
	mlx_loop(game.mlx);
	return (0);
	/*
	- Create an exit function that contains: mlx_destroy_window, mlx_destroy_display + free, mlx_destroy_image */
}
