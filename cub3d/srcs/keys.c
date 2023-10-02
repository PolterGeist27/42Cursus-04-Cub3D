/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:05:55 by diogmart          #+#    #+#             */
/*   Updated: 2023/10/02 14:24:51 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_keys(int key, t_data *data)
{
	if (key == ESC)
		ft_close(data);
	else if (key == W)
		data->player->up = 1;
	else if (key == A)
		data->player->left = 1;
	else if (key == S)
		data->player->down = 1;
	else if (key == D)
		data->player->right = 1;
	else if (key == RIGHT)
		data->player->rotcw = -1;
	else if (key == LEFT)
		data->player->rotccw = 1;
	else
		printf("%d\n", key);
	return (0);
}

int	release_movement(int key, t_data *data)
{
	if (key == W)
		data->player->up = 0;
	else if (key == A)
		data->player->left = 0;
	else if (key == S)
		data->player->down = 0;
	else if (key == D)
		data->player->right = 0;
	else if (key == RIGHT)
		data->player->rotcw = 0;
	else if (key == LEFT)
		data->player->rotccw = 0;
	return (0);
}
