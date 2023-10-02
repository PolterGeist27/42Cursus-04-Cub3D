/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:48:36 by diogmart          #+#    #+#             */
/*   Updated: 2023/10/02 14:26:19 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
TODO:
	- End program when textures dont work;
	- Memory leaks;
    - Norm;
*/

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
	{
		ft_putstr_fd("Error: Wrong number of arguments\n", 2);
		exit(2);
	}
	data = (t_data *)malloc(sizeof(t_data));
	init_data(data);
	file_type(argv[1], data);
	get_player_data(data);
	init_window(data);
	return (0);
}
