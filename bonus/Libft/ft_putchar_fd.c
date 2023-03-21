/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:03:11 by kafortin          #+#    #+#             */
/*   Updated: 2022/05/10 14:14:35 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Writes character "c" on file descriptor passed as an argument.*/
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
