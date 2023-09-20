/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:21:16 by diogmart          #+#    #+#             */
/*   Updated: 2023/09/20 10:54:21 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_movement(t_data *data, t_player *player)
{
	if (player->up)
		move_vertical(data, data->player, 1);
	if (player->down)
		move_vertical(data, data->player, -1);
	if (player->left)
		move_horizontal(data, data->player, -1);
	if (player->right)
		move_horizontal(data, data->player, 1);
	if (player->rotCW)
		;
	if (player->rotCCW)
		;
	if (player->up || player->down || player->left || player->right ||
			player->rotCW || player->rotCCW)
		return (1);
	return (0);
}

int raycasting_loop(t_data *data)
{
	if (!check_movement(data, data->player))
		return (0);
	mlx_destroy_image(data->st_mlx->mlx, data->st_mlx->img);
	data->st_mlx->img = mlx_new_image(data->st_mlx->mlx,
			data->st_mlx->img_w, data->st_mlx->img_h);
	draw_celling_floor(data, data->st_mlx);
    raycasting(data);
    return (0);
}
