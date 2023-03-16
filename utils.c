/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:49:11 by kafortin          #+#    #+#             */
/*   Updated: 2023/03/16 16:17:07 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_error(char *error)
{
	ft_putstr_fd("ERROR - ", 2);
	ft_putstr_fd(error, 2);
	exit(1);
}

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

void	free_and_exit_error(char *error, t_game *game)
{
	free_map(game->map, game);
	exit_error(error);
}

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

int	end_game(t_game *game)
{
	free_map(game->map, game);
	destroy_images(game);
	mlx_clear_window(game->mlx, game->window);
	mlx_destroy_window(game->mlx, game->window);
	exit(1);
	return (0);
}
