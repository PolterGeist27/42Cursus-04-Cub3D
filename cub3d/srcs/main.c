/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:48:36 by diogmart          #+#    #+#             */
/*   Updated: 2023/09/07 16:01:20 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
TODO:
    - Completly change the way we read the file to manage a way to read textures;
    - Add a way to read textures from the map files and
    change the map checks so that the program works with the texture indicators;
    - Textures;
    - Create a player;
    - Add movement;
    - Raytracing;
    ...
    - Norm;

Known issues:
    - Valgrind seems to complain about padding ? need more research to
    find the source of the errror (the error is supressed, use "valgrind -s");
*/

int main(int argc, char **argv)
{
    t_data *data;

	if (argc != 2)
	{
		ft_putstr_fd("Error: Wrong number of arguments\n", 2);
		exit(2);
	}
    data = (t_data *)malloc(sizeof(t_data));
	init_data(data, &(data->st_mlx));
	file_type(argv[1], data);
/*  copy_file(&data, argv[1]);
    read_file(&data, argv[1]);
    if (check_walls(data))
        ft_error(&data);
    init_window(data, data->st_mlx); */
    return (0);
}
