/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 10:48:07 by diogmart          #+#    #+#             */
/*   Updated: 2023/10/03 10:10:17 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_mlx *st_mlx, int x, int y, int color)
{
	char	*dst;

	dst = st_mlx->addr + (y * st_mlx->line_length + x
			* (st_mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_celling_floor(t_data *data, t_mlx *st_mlx)
{
	int	x;
	int	y;

	(void)data;
	x = 0;
	while (x < st_mlx->img_w)
	{
		y = 0;
		while (y < st_mlx->img_h / 2)
		{
			my_mlx_pixel_put(st_mlx, x, y, data->textures->c_colour);
			y++;
		}
		while (y < st_mlx->img_h)
		{
			my_mlx_pixel_put(st_mlx, x, y, data->textures->f_colour);
			y++;
		}
		x++;
	}
}

void	draw_vertical_line(t_data *data, int x, int color)
{
	int	y;

	(void)color;
	y = data->player->draw_start;
	while (y < data->player->draw_end)
	{
		if (data->player->side == 1)
			my_mlx_pixel_put(data->st_mlx, x, y, 0xFF0000);
		else
			my_mlx_pixel_put(data->st_mlx, x, y, 0xFFF000);
		y++;
	}
}
