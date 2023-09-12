/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:04:17 by diogmart          #+#    #+#             */
/*   Updated: 2023/09/12 14:58:30 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycasting(t_data *data, t_player *player)
{
	int		x;

	x = 0;
	while (x < data->map_w)
	{
		get_values(data, data->player, x);
		get_step(data, data->player);
		x++;
	}
}

void	get_values(t_data *data, t_player *player, int x)
{
	player->camera_x = 2 * x / (double)data->map_w - 1;
	player->raydir_x = player->dir_x + player->plane_x *player->camera_x;
	player->raydir_y = player->dir_y + player->plane_y *player->camera_x;
	player->map_x = (int)player->pos_x;
	player->map_y = (int)player->pos_y;
	if (player->raydir_x == 0)
		player->delta_dist_x = 1e30; // to avoid dividing by 0 we set it to a really big number
	else
		player->delta_dist_x = abs(1 / player->raydir_x);
	if (player->raydir_y == 0)
		player->delta_dist_y = 1e30;
	else
		player->delta_dist_y = abs(1 / player->raydir_y);
}

void	get_step(t_data *data, t_player *player)
{
	if (player->raydir_x < 0)
	{
		player->step_x = -1;
		player->side_dist_x = (player->pos_x - player->map_x) * player->delta_dist_x;
	}
	else
	{
		player->step_x = 1;
		player->side_dist_x = (player->map_x + 1 - player->pos_x) * player->delta_dist_x;
	}
	if (player->raydir_y < 0)
	{
		player->step_y = -1;
		player->side_dist_y = (player->pos_y - player->map_y) * player->delta_dist_y;
	}
	else
	{
		player->step_y = 1;
		player->side_dist_y = (player->map_y + 1 - player->pos_y) * player->delta_dist_y;
	}
}
