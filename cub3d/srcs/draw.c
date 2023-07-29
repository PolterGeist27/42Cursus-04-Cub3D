/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 10:48:07 by diogmart          #+#    #+#             */
/*   Updated: 2023/07/29 11:29:10 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_limits(t_data *data, int x, int y)
{
	if (data->img_w - 1 < x || x < 0)
		return (0);
	if (data->img_h - 1 < y || y < 0)
		return (0);
	return (1);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_map2D(t_data *data)
{
	int		y;
	int		x;
	char	pixel;

	y = 0;
	while (y < data->map_h)
	{
		x = 0;
		while (x < data->map_w)
		{
			pixel = data->map[y][x];
			if (pixel == '1')
				my_mlx_pixel_put(data, x, y, 0xff0000);
			if (pixel == '0')
				my_mlx_pixel_put(data, x, y, 0x00ff00);
			if (pixel == 'P')
				my_mlx_pixel_put(data, x, y, 0xffffff);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}
