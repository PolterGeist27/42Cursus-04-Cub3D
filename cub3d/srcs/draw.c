/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 10:48:07 by diogmart          #+#    #+#             */
/*   Updated: 2023/09/04 12:35:08 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_limits(t_data *data, int x, int y)
{
	if (data->st_mlx->img_w - 1 < x || x < 0)
		return (0);
	if (data->st_mlx->img_h - 1 < y || y < 0)
		return (0);
	return (1);
}

void	my_mlx_pixel_put(t_mlx *st_mlx, int x, int y, int color)
{
	char	*dst;

	dst = st_mlx->addr + (y * st_mlx->line_length + x * (st_mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_map2D(t_data *data, t_mlx *st_mlx)
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
				my_mlx_pixel_put(st_mlx, x, y, 0xff0000);
			if (pixel == '0')
				my_mlx_pixel_put(st_mlx, x, y, 0x00ff00);
			if (ft_strchr("NSEW", pixel))
				my_mlx_pixel_put(st_mlx, x, y, 0xffffff);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(st_mlx->mlx, st_mlx->mlx_win, st_mlx->img, 0, 0);
}