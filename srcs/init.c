/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:56:49 by katherinefo       #+#    #+#             */
/*   Updated: 2023/04/18 16:21:04 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

/*Checks if the path to the asset can be opened. If not, frees the map and
destroy all the mlx renders before sending an error message and exiting the 
program. If it's accessible, it returns the image to store in the void **.*/
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
		destroy_images(game);
		mlx_clear_window(game->mlx, game->window);
		mlx_destroy_window(game->mlx, game->window);
		free_map(game->map, game);
		exit_error(IMAGE_ERROR);
	}
	close(fd);
	image = mlx_xpm_file_to_image(game->mlx, path, &size, &size);
	return (image);
}

/*Initializes all of the game sprites and stores them each in a separate void **
contained in the game struct.*/
void	init_sprites(t_game *game)
{
	game->sprite.base = xpm_to_image(game, "./assets/tile2.xpm");
	game->sprite.play = xpm_to_image(game, "./assets/character_face.xpm");
	game->sprite.wall = xpm_to_image(game, "./assets/tree.xpm");
	game->sprite.collect = xpm_to_image(game, "./assets/carrot.xpm");
	game->sprite.exit = xpm_to_image(game, "./assets/character_face.xpm");
	game->sprite.left = xpm_to_image(game, "./assets/character_left.xpm");
	game->sprite.right = xpm_to_image(game, "./assets/character_right.xpm");
	game->sprite.up = xpm_to_image(game, "./assets/character_back.xpm");
	game->sprite.right_kiss = xpm_to_image(game, "./assets/char_rkiss.xpm");
	game->sprite.down_kiss = xpm_to_image(game, "./assets/char_dkiss.xpm");
	game->sprite.up_kiss = xpm_to_image(game, "./assets/char_ukiss.xpm");
	game->sprite.left_kiss = xpm_to_image(game, "./assets/char_lkiss.xpm");
	game->sprite.arrow = xpm_to_image(game, "./assets/arrow.xpm");
	game->sprite.exit_sign = xpm_to_image(game, "./assets/exit_sign.xpm");
	game->sprite.start_sign = xpm_to_image(game, "./assets/start_sign.xpm");
}

/*Takes the initial state of the map and fills it with the right sprites 
depending on what the position is.*/
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
				put_image(game, game->sprite.wall, x, y);
			else if (game->map[x][y] == COLLECTIBLE)
				put_image(game, game->sprite.collect, x, y);
			else if (game->map[x][y] == EXIT)
				put_image(game, game->sprite.exit, x, y);
			y++;
		}
		x++;
	}
}
