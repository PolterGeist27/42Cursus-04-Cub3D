/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:48:36 by diogmart          #+#    #+#             */
/*   Updated: 2023/07/19 11:28:35 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
    mlx_hook(data->mlx_win, 17, 0, ft_close, data);
    mlx_hook(data->mlx_win, KeyPress, KeyPressMask, check_keys, data);
    mlx_loop(data->mlx);
    //ft_close(data);
    return (0);
}