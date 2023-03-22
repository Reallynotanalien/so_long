/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:44:23 by kafortin          #+#    #+#             */
/*   Updated: 2023/03/22 16:40:27 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Goes through the whole map and counts the number of exits, players, and
collectibles and stores them in the game structure. If it finds a character
that is not permitted in the map, the program exits.*/
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
				game->x = x;
				game->y = y;
			}
			else if (game->map[x][y] == COLLECTIBLE)
				game->collect_num++;
			else if (game->map[x][y] == EXIT)
				game->exit_num++;
			else if (game->map[x][y] != WALL && game->map[x][y] != '0')
				free_and_exit_error(CHAR_ERROR, game);
			y++;
		}
		x++;
	}
}

/*Checks if the map is surrounded by walls by making sure the first and last
line are only made of the char '1' and also that each first and last 
character of each lines are '1'. Exits the program if it is not the case.*/
void	validate_walls(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->columns)
	{
		if (game->map[0][i] != WALL || game->map[game->lines - 1][i] != WALL)
			free_and_exit_error(WALL_ERROR, game);
		if (i < game->lines && (game->map[i][game->columns - 1] != WALL
			|| game->map[i][0] != WALL))
			free_and_exit_error(WALL_ERROR, game);
		i++;
	}
}

/*Checks if the map is a rectangle by verifying that each line is the same 
size. Exits the program if it is not the case.*/
void	check_if_rectangle(t_game *game)
{
	int	i;

	i = 0;
	while (game->lines > i)
	{
		if (ft_strlen(game->map[i]) != (size_t)game->columns)
			free_and_exit_error(RECTANGLE_ERROR, game);
		i++;
	}
}

/*Checks if the last 4 characters of the map sent as an argument are .ber.
Exits the program if it is not the case.*/
void	validate_extension(char *argv)
{
	int	i;

	i = (ft_strlen(argv) - 4);
	if (ft_strncmp(".ber", &argv[i], 4) != 0)
		exit_error(EXTENSION_ERROR);
}

/*Checks if the extension of the map sent as an argument to the 
program is .ber, then reads and mallocates the map to keep it in the
game->map variable. 
After doing so, the map passes through a series of verifications to 
check if it is a valid map. If it is not, the program frees and exits.*/
void	validate_map(char *argv, t_game *game)
{
	validate_extension(argv);
	read_map(argv, game);
	check_if_rectangle(game);
	validate_walls(game);
	validate_characters(game);
	if (game->player_num != 1)
		free_and_exit_error(PLAY_ERROR, game);
	if (game->collect_num < 1)
		free_and_exit_error(COLL_ERROR, game);
	if (game->exit_num != 1)
		free_and_exit_error(EXIT_ERROR, game);
	flood_fill(game);
}
