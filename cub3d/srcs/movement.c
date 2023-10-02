/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:15:03 by diogmart          #+#    #+#             */
/*   Updated: 2023/10/02 14:28:05 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_vertical(t_data *data, t_player *player, int dir)
{
	if (dir == 1)
	{
		if (data->map[(int)(player->pos_y + player->dir_y * 0.2)]
				[(int)player->pos_x] != '1')
			player->pos_y += player->dir_y * 0.2;
		if (data->map[(int)player->pos_y]
			[(int)(player->pos_x + player->dir_x * 0.2)] != '1')
			player->pos_x += player->dir_x * 0.2;
	}
	else
	{
		if (data->map[(int)(player->pos_y - player->dir_y * 0.2)]
				[(int)player->pos_x] != '1')
			player->pos_y -= player->dir_y * 0.2;
		if (data->map[(int)player->pos_y]
			[(int)(player->pos_x - player->dir_x * 0.2)] != '1')
			player->pos_x -= player->dir_x * 0.2;
	}
}

void	move_horizontal(t_data *data, t_player *player, int dir)
{
	if (dir == 1)
	{
		if (data->map[(int)(player->pos_y + player->dir_x * 0.2)]
				[(int)player->pos_x] != '1')
			player->pos_y += player->dir_x * 0.2;
		if (data->map[(int)player->pos_y]
			[(int)(player->pos_x - player->dir_y * 0.2)] != '1')
			player->pos_x -= player->dir_y * 0.2;
	}
	else
	{
		if (data->map[(int)(player->pos_y - player->dir_x * 0.2)]
				[(int)player->pos_x] != '1')
			player->pos_y -= player->dir_x * 0.2;
		if (data->map[(int)player->pos_y]
			[(int)(player->pos_x + player->dir_y * 0.2)] != '1')
			player->pos_x += player->dir_y * 0.2;
	}
}

void	rotate_player(t_data *data, t_player *player, int dir)
{
	double	angle;
	double	temp_x;
	double	temp_y;

	(void)data;
	angle = 0.1;
	if (dir != 1)
		angle *= -1;
	temp_x = player->dir_x * cos(angle) - player->dir_y * sin(angle);
	temp_y = player->dir_x * sin(angle) + player->dir_y * cos(angle);
	player->dir_x = temp_x;
	player->dir_y = temp_y;
	temp_x = player->plane_x * cos(angle) - player->plane_y * sin(angle);
	temp_y = player->plane_x * sin(angle) + player->plane_y * cos(angle);
	player->plane_x = temp_x;
	player->plane_y = temp_y;
}
