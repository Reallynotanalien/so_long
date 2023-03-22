/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:49:11 by kafortin          #+#    #+#             */
/*   Updated: 2023/03/22 17:21:56 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Writes ERROR - followed by the error message sent as an argument to the 
terminal before exiting the program with errno.*/
void	exit_error(char *error)
{
	ft_putstr_fd("ERROR - ", 2);
	ft_putstr_fd(error, 2);
	exit(errno);
}

/*Frees the whole game->map variable correctly.*/
void	free_map(char **tab, t_game *game)
{
	int	i;

	i = 0;
	while (game->lines > i)
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	if (tab)
	{
		free(tab);
		tab = NULL;
	}
}

/*Frees the whole game->map variable correctly, before writing ERROR - 
followed by the error message sent as an argument to the terminal and 
exiting the program with errno.*/
void	free_and_exit_error(char *error, t_game *game)
{
	free_map(game->map, game);
	exit_error(error);
}

/*Depending on the chosen option, either frees the lines in game->map or
frees the whole game->map variable, then closes the map file before 
writing ERROR - followed by the error message sent as an argument to the
terminal and exiting the program with errno.*/
void	free_close_and_exit_error(char *error, t_game *game, int option)
{
	if (option == 0)
	{
		free(game->map);
		game->map = NULL;
	}
	else if (option == 1)
		free_map(game->map, game);
	close(game->fd);
	exit_error(error);
}
