/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:03:11 by kafortin          #+#    #+#             */
/*   Updated: 2022/05/10 16:50:59 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Writes int "n" on file descriptor passed as an argument.*/
void	ft_putnbr_fd(int n, int fd)
{
	if (n <= 9 && n >= 0)
		ft_putchar_fd(n + '0', fd);
	else if (n < 0)
	{	
		if (n == -2147483648)
		{
			write (fd, "-2147483648", 11);
			return ;
		}
		write (fd, "-", 1);
		n *= -1;
		ft_putnbr_fd(n, fd);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}
