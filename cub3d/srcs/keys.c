/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:05:55 by diogmart          #+#    #+#             */
/*   Updated: 2023/09/19 11:40:49 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_keys(int key, t_data *data)
{
	if (key == ESC)
		ft_close(data);
	else if (key == W)
		move_vertical(data, data->player, 1);
	else if (key == A)
		printf("A\n");
	else if (key == S)
		move_vertical(data, data->player, -1);
	else if (key == D)
		printf("D\n");
	else if (key == LEFT)
		printf("Left Arrow\n");
	else if (key == RIGHT)
		printf("Right Arrow\n");
	else
		printf("%d\n", key);
 	mlx_clear_window(data->st_mlx->mlx, data->st_mlx->mlx_win);
	mlx_destroy_image(data->st_mlx->mlx, data->st_mlx->img);
	data->st_mlx->img = mlx_new_image(data->st_mlx->mlx,
			data->st_mlx->img_w, data->st_mlx->img_h);
	//draw_celling_floor(data, data->st_mlx); Still need to draw celling and floor					(!)
	raycasting(data, data->st_mlx);
	return (0);
}