/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:26:32 by kafortin          #+#    #+#             */
/*   Updated: 2023/01/27 17:51:57 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	validate_extension(char *argv)
{
	int	i;

	i = (ft_strlen(argv) - 4);
	if (ft_strncmp(".ber", &argv[i], 4) == 0)
		return (true);
	return (false);
}

bool	validate_map(char *argv)
{
	if (!validate_extension(argv))
		return (false);
	return (true);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		ft_putstr_fd("Number of arguments is invalid\n", 2);
	if (!validate_map(argv[1]))
		ft_putstr_fd("Map is invalid\n", 2);
	return (0);
	/*1- Parsing*/
	/*- Create a "game" struct and malloc it
	- Create a function to check that map is a .ber
	- Initiate MLX
	- Open map and read it (with gnl)
	- Check if map is valid (validate_map) (rectangle/nb of characters is OK, only walls in the borders)
	- XPM files: look for png files and redimension in another size
	- mlx_new_window: creates a new window
	- mlx_xpm_file_to_image
	- Create an exit function that contains: mlx_destroy_window, mlx_destroy_display + free, mlx_destroy_image */

	/*2- Initialize the struct (NULL, or mlx_init)*/
	/*3- Analyse map and show depending on element mlx_put_image_to_window*/
	/*4- Keyboard interactions: mlx_key_hooks, ft_event_key function (authorizes the character to move)*/
	/*5- Make images appear in a loop (mlx_loop, mlx_hook to close window with X */
}
