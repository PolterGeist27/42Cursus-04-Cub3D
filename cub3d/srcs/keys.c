/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:05:55 by diogmart          #+#    #+#             */
/*   Updated: 2023/07/29 11:23:51 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_keys(int key, t_data *data)
{
	if (key == ESC)
		ft_close(data);
	else if (key == W)
		printf("W\n");
	else if (key == A)
		printf("A\n");
	else if (key == S)
		printf("S\n");
	else if (key == D)
		printf("D\n");
	else if (key == LEFT)
		printf("Left Arrow\n");
	else if (key == RIGHT)
		printf("Right Arrow\n");
	else
		printf("%d\n", key);
/* 	mlx_clear_window(data->mlx, data->mlx_win);
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, data->img_w, data->img_h); */
	return (0);
}