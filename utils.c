/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:49:11 by kafortin          #+#    #+#             */
/*   Updated: 2023/02/13 18:11:15 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_error(char *error)
{
	ft_putstr_fd("ERROR - MAP IS INVALID ", 2);
	ft_putstr_fd(error, 2);
	exit(1);
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
