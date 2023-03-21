/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:56:49 by katherinefo       #+#    #+#             */
/*   Updated: 2023/03/21 17:46:07 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/*Initializes the t_game struct without mallocating it, and saves argv in it.*/
void	init_game_struct(t_game *game, char **argv)
{
	ft_memset(game, 0, sizeof(t_game));
	game->argv = argv;
}

/*Initializes the t_game struct data (number of lines/columns/players/
collectibles/exits/moves) to zero.*/
void	init_data(t_game *game)
{
	game->lines = 0;
	game->columns = 0;
	game->player_num = 0;
	game->collect_num = 0;
	game->exit_num = 0;
	game->moves = 0;
}

void	**xpm_to_image(t_game *game, char *path)
{
	int		size;
	int		fd;
	void	**image;

	size = SIZE;
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		// destroy_images(game);
		mlx_clear_window(game->mlx, game->window);
		mlx_destroy_window(game->mlx, game->window);
		free_map(game->map, game);
		exit_error(IMAGE_ERROR);
	}
	close(fd);
	image = mlx_xpm_file_to_image(game->mlx, path, &size, &size);
	return (image);
}

void	init_sprites(t_game *game)
{
	game->sprite.base = xpm_to_image(game, "./Assets/tile2.xpm");
	game->sprite.play = xpm_to_image(game, "./Assets/character_face.xpm");
	game->sprite.wal = xpm_to_image(game, "./Assets/tree.xpm");
	game->sprite.coll = xpm_to_image(game, "./Assets/carrot.xpm");
	game->sprite.exit = xpm_to_image(game, "./Assets/character_face.xpm");
	game->sprite.left = xpm_to_image(game, "./Assets/character_left.xpm");
	game->sprite.right = xpm_to_image(game, "./Assets/character_right.xpm");
	game->sprite.up = xpm_to_image(game, "./Assets/character_back.xpm");
	game->sprite.right_kiss = xpm_to_image(game, "./Assets/char_rkiss.xpm");
	game->sprite.down_kiss = xpm_to_image(game, "./Assets/char_dkiss.xpm");
	game->sprite.up_kiss = xpm_to_image(game, "./Assets/char_ukiss.xpm");
	game->sprite.left_kiss = xpm_to_image(game, "./Assets/char_lkiss.xpm");
	game->sprite.arrow = xpm_to_image(game, "./Assets/arrow.xpm");
	game->sprite.exit_sign = xpm_to_image(game, "./Assets/exit_sign.xpm");
	game->sprite.start_sign = xpm_to_image(game, "./Assets/start_sign.xpm");
	game->sprite.black = xpm_to_image(game, "./Assets/black.xpm");
}

void	init_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->lines > x)
	{
		y = 0;
		while (y < game->columns)
		{	
			put_image(game, game->sprite.base, x, y);
			if (game->map[x][y] == PLAYER)
				put_image(game, game->sprite.play, x, y);
			else if (game->map[x][y] == WALL)
				put_image(game, game->sprite.wal, x, y);
			else if (game->map[x][y] == COLLECTIBLE)
				put_image(game, game->sprite.coll, x, y);
			else if (game->map[x][y] == EXIT)
				put_image(game, game->sprite.exit, x, y);
			y++;
		}
		x++;
	}
	mlx_string_put(game->mlx, game->window, 16, (game->lines + 1) * (SIZE - 1) , 16777215, "Moves:");
}
