/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:26:32 by kafortin          #+#    #+#             */
/*   Updated: 2023/02/13 17:54:30 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	putnbr_screen(t_game *game, int moves, int position)
{
	if (moves <= 9 && moves >= 0)
	{
		if (moves == 0)
			mlx_put_image_to_window(game->mlx, game->mlx_win, game->sprite.zero, position, game->lines * 32);
		else if (moves == 1)
			mlx_put_image_to_window(game->mlx, game->mlx_win, game->sprite.one, position, game->lines * 32);
		else if (moves == 2)
			mlx_put_image_to_window(game->mlx, game->mlx_win, game->sprite.two, position, game->lines * 32);
		else if (moves == 3)
			mlx_put_image_to_window(game->mlx, game->mlx_win, game->sprite.three, position, game->lines * 32);
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

int	end_game(t_game *game)
{
	mlx_clear_window(game->mlx, game->mlx_win);
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit(0);
	return (0);
}

void	arrow_down(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->sprite.base, ((game->columns / 2) - 1) * 32, (game->lines / 2) * 32);
	if (game->map[game->lines / 2][(game->columns / 2) - 1] == WALL)
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->sprite.wal, ((game->columns / 2) - 1) * 32, (game->lines / 2) * 32);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->sprite.arrow, ((game->columns / 2) - 1) * 32, ((game->lines / 2) + 1) * 32);
	game->arrow_position = 2;
}

void	arrow_up(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->sprite.base, ((game->columns / 2) - 1) * 32, ((game->lines / 2) + 1) * 32);
	if (game->map[(game->lines / 2) + 1][(game->columns / 2) - 1] == WALL)
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->sprite.wal, ((game->columns / 2) - 1) * 32, ((game->lines / 2) + 1) * 32);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->sprite.arrow, ((game->columns / 2) - 1) * 32, ((game->lines / 2)) * 32);
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
			mlx_put_image_to_window(game->mlx, game->mlx_win, game->sprite.base, game->location.y * 32, game->location.x *32);
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
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->sprite.base, game->location.y * 32, (game->location.x + 1) * 32);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->sprite.up, game->location.y * 32, game->location.x * 32);
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
			mlx_put_image_to_window(game->mlx, game->mlx_win, game->sprite.base, game->location.y * 32, game->location.x *32);
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
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->sprite.base, game->location.y * 32, (game->location.x - 1) * 32);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->sprite.play, game->location.y * 32, game->location.x * 32);
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
			mlx_put_image_to_window(game->mlx, game->mlx_win, game->sprite.base, game->location.y * 32, game->location.x *32);
		}
		else if (game->map[game->location.x][game->location.y] == EXIT)
		{
			if (game->collect_num == 0)
			{
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->sprite.base, game->location.y * 32, game->location.x * 32);
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->sprite.left, game->location.y * 32, game->location.x * 32);
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->sprite.right_kiss, (game->location.y - 1) * 32, game->location.x * 32);
				game->moves++;
				putnbr_screen(game, game->moves, 0);
				ft_putnbr_fd(game->moves, 1);
				ft_putstr_fd("\n", 1);
				ft_putstr_fd("YOU WIN!!\n", 1);
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->sprite.start_sign, (game->columns / 2) * 32, (game->lines / 2) * 32);
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->sprite.exit_sign, (game->columns / 2) * 32, ((game->lines / 2) + 1) * 32);
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->sprite.arrow, ((game->columns / 2) - 1) * 32, (game->lines / 2) * 32);
				game->arrow_position = 1;
				mlx_key_hook(game->mlx_win, restart_game, game);
				return ;
			}
			else
				game->location.y--;
		}
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->sprite.base, (game->location.y - 1) * 32, game->location.x * 32);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->sprite.right, game->location.y * 32, game->location.x * 32);
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
			mlx_put_image_to_window(game->mlx, game->mlx_win, game->sprite.base, game->location.y * 32, game->location.x *32);
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
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->sprite.base, (game->location.y + 1) * 32, game->location.x * 32);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->sprite.left, game->location.y * 32, game->location.x * 32);
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
	game->sprite.base = mlx_xpm_file_to_image(game->mlx, "./Assets/tile2.xpm", &game->size, &game->size);
	game->sprite.play = mlx_xpm_file_to_image(game->mlx, "./Assets/character_face.xpm", &game->size, &game->size);
	game->sprite.wal = mlx_xpm_file_to_image(game->mlx, "./Assets/tree.xpm", &game->size, &game->size);
	game->sprite.coll = mlx_xpm_file_to_image(game->mlx, "./Assets/carrot.xpm", &game->size, &game->size);
	game->sprite.exit = mlx_xpm_file_to_image(game->mlx, "./Assets/character_face.xpm", &game->size, &game->size);
	game->sprite.left = mlx_xpm_file_to_image(game->mlx, "./Assets/character_left.xpm", &game->size, &game->size);
	game->sprite.right = mlx_xpm_file_to_image(game->mlx, "./Assets/character_right.xpm", &game->size, &game->size);
	game->sprite.up = mlx_xpm_file_to_image(game->mlx, "./Assets/character_back.xpm", &game->size, &game->size);
	game->sprite.right_kiss = mlx_xpm_file_to_image(game->mlx, "./Assets/character_right_kiss.xpm", &game->size, &game->size);
	game->sprite.arrow = mlx_xpm_file_to_image(game->mlx, "./Assets/arrow.xpm", &game->size, &game->size);
	game->sprite.exit_sign = mlx_xpm_file_to_image(game->mlx, "./Assets/exit_sign.xpm", &game->size, &game->size);
	game->sprite.start_sign = mlx_xpm_file_to_image(game->mlx, "./Assets/start_sign.xpm", &game->size, &game->size);
	game->sprite.zero = mlx_xpm_file_to_image(game->mlx, "./Assets/zero.xpm", &game->size, &game->size);
	game->sprite.one = mlx_xpm_file_to_image(game->mlx, "./Assets/one.xpm", &game->size, &game->size);
	game->sprite.two = mlx_xpm_file_to_image(game->mlx, "./Assets/two.xpm", &game->size, &game->size);
	game->sprite.three = mlx_xpm_file_to_image(game->mlx, "./Assets/three.xpm", &game->size, &game->size);
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
	validate_map(argv[1], &game);
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
			mlx_put_image_to_window(game.mlx, game.mlx_win, game.sprite.base, y * 32, x * 32);
			if (game.map[x][y] == PLAYER)
				mlx_put_image_to_window(game.mlx, game.mlx_win, game.sprite.play, y * 32, x * 32);
			else if (game.map[x][y] == WALL)
				mlx_put_image_to_window(game.mlx, game.mlx_win, game.sprite.wal, y * 32, x * 32);
			else if (game.map[x][y] == COLLECTIBLE)
				mlx_put_image_to_window(game.mlx, game.mlx_win, game.sprite.coll, y * 32, x * 32);
			else if (game.map[x][y] == EXIT)
				mlx_put_image_to_window(game.mlx, game.mlx_win, game.sprite.exit, y * 32, x * 32);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(game.mlx, game.mlx_win, game.sprite.zero, 0, game.lines * 32);
	mlx_hook(game.mlx_win, 17, 0, end_game, &game);
	mlx_key_hook(game.mlx_win, deal_key, &game);
	mlx_loop(game.mlx);
	return (0);
	/*
	- Create an exit function that contains: mlx_destroy_window, mlx_destroy_display + free, mlx_destroy_image */
}
