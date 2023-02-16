/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:26:32 by kafortin          #+#    #+#             */
/*   Updated: 2023/02/16 18:08:43 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	putnbr_screen(t_game *game, int moves, int position)
{
	if (moves <= 9 && moves >= 0)
	{
		if (moves == 0)
			put_image(game, game->sprite.zero, game->lines, position);
		else if (moves == 1)
			put_image(game, game->sprite.one, game->lines, position);
		else if (moves == 2)
			put_image(game, game->sprite.two, game->lines, position);
		else if (moves == 3)
			put_image(game, game->sprite.three, game->lines, position);
		else if (moves == 4)
			put_image(game, game->sprite.four, game->lines, position);
		else if (moves == 5)
			put_image(game, game->sprite.five, game->lines, position);
		else if (moves == 6)
			put_image(game, game->sprite.six, game->lines, position);
		else if (moves == 7)
			put_image(game, game->sprite.seven, game->lines, position);
		else if (moves == 8)
			put_image(game, game->sprite.eight, game->lines, position);
		else if (moves == 9)
			put_image(game, game->sprite.nine, game->lines, position);
	}
	else if (moves >= 10 && moves <= 99)
	{
		putnbr_screen(game, moves / 10, position);
		putnbr_screen(game, moves % 10, position + 1);
	}
	else
	{
		putnbr_screen(game, moves / 10, position);
		putnbr_screen(game, moves % 10, position + 2);
	}
}

void	game_moves(t_game *game)
{
	game->moves++;
	putnbr_screen(game, game->moves, 0);
	ft_putnbr_fd(game->moves, 1);
	ft_putstr_fd(" ", 1);
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

void	if_collectible(t_game *game)
{
	if (game->map[game->location.x][game->location.y] == COLLECTIBLE)
	{
		game->map[game->location.x][game->location.y] = 0;
		game->collect_num--;
		put_image(game, game->sprite.base, game->location.x, game->location.y);
	}
}

void	move_up(t_game *game)
{
	game->location.x--;
	if (game->map[game->location.x][game->location.y] == WALL)
		game->location.x++;
	else
	{
		if_collectible(game);
		if (game->map[game->location.x][game->location.y] == EXIT)
		{
			if (game->collect_num == 0)
			{
				game_moves(game);
				ft_putstr_fd("\nYOU WIN!!\n", 1);
				return ;
			}
			else
			{
				game->location.x++;
				return ;
			}
		}
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->sprite.base, game->location.y * 32, (game->location.x + 1) * 32);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->sprite.up, game->location.y * 32, game->location.x * 32);
		game_moves(game);
	}
}

void	move_down(t_game *game)
{
	game->location.x++;
	if (game->map[game->location.x][game->location.y] == WALL)
		game->location.x--;
	else
	{
		if_collectible(game);
		if (game->map[game->location.x][game->location.y] == EXIT)
		{
			if (game->collect_num == 0)
			{
				game_moves(game);
				ft_putstr_fd("\nYOU WIN!!\n", 1);
				return ;
			}
			else
			{
				game->location.x--;
				return ;
			}
		}
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->sprite.base, game->location.y * 32, (game->location.x - 1) * 32);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->sprite.play, game->location.y * 32, game->location.x * 32);
		game_moves(game);
	}
}

void	move_right(t_game *game)
{
	game->location.y++;
	if (game->map[game->location.x][game->location.y] == WALL)
		game->location.y--;
	else
	{
		if_collectible(game);
		if (game->map[game->location.x][game->location.y] == EXIT)
		{
			if (game->collect_num == 0)
			{
				put_image(game, game->sprite.base, game->location.x, game->location.y);
				put_image(game, game->sprite.left, game->location.x, game->location.y);
				put_image(game, game->sprite.right_kiss, (game->location.x), game->location.y - 1);
				game_moves(game);
				ft_putstr_fd("\nYOU WIN!!\n", 1);
				put_image(game, game->sprite.start_sign, (game->lines / 2), (game->columns / 2));
				put_image(game, game->sprite.exit_sign, (game->lines / 2) + 1, (game->columns / 2));
				put_image(game, game->sprite.arrow, (game->lines / 2), (game->columns / 2) - 1);
				game->arrow_position = 1;
				mlx_key_hook(game->mlx_win, restart_game, game);
				return ;
			}
			else
			{
				game->location.y--;
				return ;
			}
		}
		put_image(game, game->sprite.base, game->location.x, (game->location.y - 1));
		put_image(game, game->sprite.right, game->location.x, game->location.y);
		game_moves(game);
	}
}

void	move_left(t_game *game)
{
	game->location.y--;
	if (game->map[game->location.x][game->location.y] == WALL)
		game->location.y++;
	else
	{
		if_collectible(game);
		if (game->map[game->location.x][game->location.y] == EXIT)
		{
			if (game->collect_num == 0)
			{
				game_moves(game);
				ft_putstr_fd("\nYOU WIN!!\n", 1);
				return ;
			}
			else
			{
				game->location.y++;
				return ;
			}
		}
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->sprite.base, (game->location.y + 1) * 32, game->location.x * 32);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->sprite.left, game->location.y * 32, game->location.x * 32);
		game_moves(game);
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

int	main(int argc, char **argv)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	if (argc != 2)
		ft_putstr_fd("Number of arguments is invalid\n", 2);
	init_data(&game);
	validate_map(argv[1], &game);
	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx, (SIZE * game.columns),
			(SIZE * game.lines) + SIZE, "Bonnie & Friends");
	init_sprites(&game);
	init_game_start(&game);
	mlx_hook(game.mlx_win, 17, 0, end_game, &game);
	mlx_key_hook(game.mlx_win, deal_key, &game);
	mlx_loop(game.mlx);
	return (0);
	/*
	- Create an exit function that contains: mlx_destroy_window, mlx_destroy_display + free, mlx_destroy_image */
}
