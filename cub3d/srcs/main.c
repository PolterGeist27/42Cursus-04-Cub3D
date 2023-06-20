/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:48:36 by diogmart          #+#    #+#             */
/*   Updated: 2023/06/20 16:04:11 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{
    t_data *data;
    (void)argc;
    (void)argv;

    data = (t_data *)malloc(sizeof(t_data));
    init_data(data);
    mlx_hook(data->mlx_win, 17, 0, ft_close, data);
    mlx_loop(data->mlx);
    //ft_close(data);
    return (0);
}