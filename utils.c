/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katherinefortin <katherinefortin@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:49:11 by kafortin          #+#    #+#             */
/*   Updated: 2023/02/14 16:49:24 by katherinefo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_error(char *error)
{
	ft_putstr_fd("ERROR - MAP IS INVALID ", 2);
	ft_putstr_fd(error, 2);
	exit(1);
}
