/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:04:17 by diogmart          #+#    #+#             */
/*   Updated: 2023/09/19 15:22:19 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	raycasting(t_data *data)
{
	int		x;
	t_mlx *st_mlx;
	
	x = 0;
	st_mlx = data->st_mlx;
	while (x < st_mlx->img_w)
	{
		get_values(data, data->player, x);
		get_step(data->player);
		get_wall_dist(data, data->player);
		perform_dda(data, data->player);
		draw_vertical_line(data, x, 0xFF0000);
		x++;
	}
	mlx_put_image_to_window(st_mlx->mlx, st_mlx->mlx_win, st_mlx->img, 0, 0);
	return (0);
}

void	get_values(t_data *data, t_player *player, int x)
{
	player->camera_x = 2 * x / (double)data->st_mlx->img_w - 1;
	player->raydir_x = player->dir_x + player->plane_x * player->camera_x;
	player->raydir_y = player->dir_y + player->plane_y * player->camera_x;
	player->map_x = floor(player->pos_x);
	player->map_y = floor(player->pos_y);
	if (player->raydir_x == 0)
		player->delta_dist_x = 1e30; // to avoid dividing by 0 we set it to a really big number
	else
		player->delta_dist_x = fabs(1 / player->raydir_x);
	if (player->raydir_y == 0)
		player->delta_dist_y = 1e30;
	else
		player->delta_dist_y = fabs(1 / player->raydir_y);
	player->hit = 0;
	player->side = 0;
}

void	get_step(t_player *player)
{
	if (player->raydir_x < 0)
	{
		player->step_x = -1;
		player->side_dist_x = (player->pos_x - player->map_x) * player->delta_dist_x;
	}
	else
	{
		player->step_x = 1;
		player->side_dist_x = (player->map_x + 1.0 - player->pos_x) * player->delta_dist_x;
	}
	if (player->raydir_y < 0)
	{
		player->step_y = -1;
		player->side_dist_y = (player->pos_y - player->map_y) * player->delta_dist_y;
	}
	else
	{
		player->step_y = 1;
		player->side_dist_y = (player->map_y + 1.0 - player->pos_y) * player->delta_dist_y;
	}
}

void	get_wall_dist(t_data *data, t_player *player)
{
	while (player->hit == 0)
	{
		if (player->side_dist_x < player->side_dist_y)
		{
			player->side_dist_x += player->delta_dist_x;
			player->map_x += player->step_x;
			player->side = 0;
		}
		else
		{
			player->side_dist_y += player->delta_dist_y;
			player->map_y += player->step_y;
			player->side = 1;
		}
		if (data->map[player->map_y][player->map_x] == '1')
			player->hit = 1;
	}
	if (player->side == 0)
		player->wall_dist = (player->side_dist_x - player->delta_dist_x);
	else
		player->wall_dist = (player->side_dist_y - player->delta_dist_y);
}

void	perform_dda(t_data *data, t_player *player)
{
	int h;

	h = data->st_mlx->img_h;
	if (player->wall_dist)
		player->line_height = (int)(h / player->wall_dist);
	else
		player->line_height = h;
	player->draw_start = -player->line_height / 2 + h / 2;
	if (player->draw_start < 0)
		player->draw_start = 0;
	player->draw_end = player->line_height / 2 + h / 2;
	if (player->draw_end >= h)
		player->draw_end = h - 1;
}
