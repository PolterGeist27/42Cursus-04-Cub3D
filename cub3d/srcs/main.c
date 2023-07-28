/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:48:36 by diogmart          #+#    #+#             */
/*   Updated: 2023/07/28 11:16:51 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
TODO:
    - change the read_file and other functions to better
    comply with the subject (eg. handle spaces);
    - check for errors in the maps;
    - create a player;
    - add movement;
    - raytracing;
    - textures;
    ...
    - norm;
*/

int main(int argc, char **argv)
{
    t_data *data;
    (void)argc;
    (void)argv;

	if (argc != 2)
	{
		ft_putstr_fd("Wrong number of arguments\n", 2);
		exit(2);
	}
	file_type(argv[1]);
    data = (t_data *)malloc(sizeof(t_data));
	init_data(data);
    read_file(&data, argv[1]);
    if (check_walls(data))
        ft_error(&data);
    mlx_hook(data->mlx_win, 17, 0, ft_close, data);
    mlx_hook(data->mlx_win, KeyPress, KeyPressMask, check_keys, data);
    mlx_loop(data->mlx);
    ft_close(data);
    return (0);
}