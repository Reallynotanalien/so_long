/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:56:49 by katherinefo       #+#    #+#             */
/*   Updated: 2023/04/07 19:07:24 by kafortin         ###   ########.fr       */
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
collectibles/exits/ennemies/moves/loop/status) to zero.*/
void	init_data(t_game *game)
{
	game->lines = 0;
	game->columns = 0;
	game->player_num = 0;
	game->collect_num = 0;
	game->exit_num = 0;
	game->fox_num = 0;
	game->moves = 0;
	game->loop = 0;
	game->status = 0;
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
	game->sprite.base = xpm_to_image(game, "./Assets/tile2.xpm");
	game->sprite.play = xpm_to_image(game, "./Assets/character_face.xpm");
	game->sprite.wall = xpm_to_image(game, "./Assets/tree.xpm");
	game->sprite.collect = xpm_to_image(game, "./Assets/carrot.xpm");
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
	game->sprite.fox = xpm_to_image(game, "./Assets/fox.xpm");
	game->sprite.fox_left = xpm_to_image(game, "./Assets/fox_left.xpm");
	game->sprite.fox_up = xpm_to_image(game, "./Assets/fox_up.xpm");
	game->sprite.fox_down = xpm_to_image(game, "./Assets/fox_down.xpm");
	game->sprite.game_over = xpm_to_image(game, "./Assets/game_over.xpm");
	game->sprite.dead = xpm_to_image(game, "./Assets/dead.xpm");
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
			else if (game->map[x][y] == FOX)
				put_image(game, game->sprite.fox, x, y);
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
