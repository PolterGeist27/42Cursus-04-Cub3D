/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:15:03 by diogmart          #+#    #+#             */
/*   Updated: 2023/09/20 10:42:07 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    move_vertical(t_data *data, t_player *player, int dir)
{
    if (dir == 1)
    {
        if (data->map[(int)player->pos_y]
                [(int)(player->pos_x + player->dir_x * 0.2)] == '0')
            player->pos_x += player->dir_x * 0.2;
        if (data->map[(int)(player->pos_y + player->dir_y * 0.2)]
                [(int)player->pos_x] == '0')
            player->pos_y += player->dir_y * 0.2;
    }
    else
    {
        if (data->map[(int)player->pos_y]
                [(int)(player->pos_x - player->dir_x * 0.2)] == '0')
            player->pos_x -= player->dir_x * 0.2;
        if (data->map[(int)(player->pos_y - player->dir_y * 0.2)]
                [(int)player->pos_x] == '0')
            player->pos_y -= player->dir_y * 0.2;
    }
}

void    move_horizontal(t_data *data, t_player *player, int dir)
{
	if (dir == 1)
    {
        if (data->map[(int)player->pos_y]
                [(int)(player->pos_x - player->dir_y * 0.2)] == '0')
            player->pos_x -= player->dir_y * 0.2;
        if (data->map[(int)(player->pos_y - player->dir_x * 0.2)]
                [(int)player->pos_x] == '0')
            player->pos_y -= player->dir_x * 0.2;
    }
    else
    {
        if (data->map[(int)player->pos_y]
                [(int)(player->pos_x + player->dir_y * 0.2)] == '0')
            player->pos_x += player->dir_y * 0.2;
        if (data->map[(int)(player->pos_y + player->dir_x * 0.2)]
                [(int)player->pos_x] == '0')
            player->pos_y += player->dir_x * 0.2;
    }
}
