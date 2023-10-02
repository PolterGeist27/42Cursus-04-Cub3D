/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:24:21 by diogmart          #+#    #+#             */
/*   Updated: 2023/10/02 13:02:07 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	my_mlx_pixel_get(t_image *img, int x, int y)
{
	return (*(unsigned int *)((img->addr + (y * img->line_length) + \
	(x * img->bits_per_pixel / 8))));
}

int	*get_texture_addr(t_image *img)
{
	int	*tmp;
	int	row_start;
	int	y;

	tmp = ft_calloc(img->height * img->width, sizeof(int));
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	y = 0;
	while (y < img->height)
	{
		row_start = y * img->width;
		ft_memcpy(tmp + row_start, img->addr + row_start,
				img->width * sizeof(int));
		y++;
	}
	return (tmp);
}

double	get_wall_x(t_player *player)
{
	double	wall_x;

	if (!player->side)
	{
		wall_x = player->pos_y + player->wall_dist * player->raydir_y;
		wall_x -= player->map_y;
	}
	else
	{
		wall_x = player->pos_x + player->wall_dist * player->raydir_x;
		wall_x -= player->map_x;
	}
	return (wall_x);
}

t_image *get_img_struct(t_data *data)
{
	if (data->wall_dir == 1)
		return (data->textures->NO);
	if (data->wall_dir == 2)
		return (data->textures->SO);
	if (data->wall_dir == 3)
		return (data->textures->EA);
	if (data->wall_dir == 4)
		return (data->textures->WE);
	return (NULL);
}

void	apply_textures(t_data *data, t_textures *textures, int x)
{
	t_image	*img;
	double	wall_x;
	double	tx;
	double	ty;
	int		y;

	img = get_img_struct(data);
	wall_x = get_wall_x(data->player);
	tx = (int)(wall_x * (double)img->width);
	tx = img->width - tx - 1;
	textures->tex_step = 1.0 * img->width / data->player->line_height;
	textures->tex_pos = (data->player->draw_start - data->st_mlx->img_h
			/ 2 + data->player->line_height) * textures->tex_step;
	y = data->player->draw_start;
	while (y < data->player->draw_end)
	{
		ty = ((int) textures->tex_pos & ((img->height / 2) - 1));
		textures->tex_pos += textures->tex_step;
		if (x >= 0 && y >= 0 && tx >= 0 && ty >= 0)
		{
			textures->color = my_mlx_pixel_get(img, tx, ty);
			my_mlx_pixel_put(data->st_mlx, x ,y , textures->color);
		}
		y++;
	}
}
