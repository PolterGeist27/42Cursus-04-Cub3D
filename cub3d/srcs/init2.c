/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:49:52 by diogmart          #+#    #+#             */
/*   Updated: 2023/09/12 12:49:43 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    init_mlx(t_data *data, t_mlx **st_mlx)
{
    data->st_mlx = malloc(sizeof(t_mlx));
	(*st_mlx)->mlx = mlx_init();
	(*st_mlx)->mlx_win = mlx_new_window((*st_mlx)->mlx, 1920, 1080, "Cub3D");
	(*st_mlx)->img_w = 1920;
	(*st_mlx)->img_h = 1080;
	(*st_mlx)->img = mlx_new_image((*st_mlx)->mlx, (*st_mlx)->img_w, (*st_mlx)->img_h);
	(*st_mlx)->addr = mlx_get_data_addr((*st_mlx)->img, &(*st_mlx)->bits_per_pixel,
			&(*st_mlx)->line_length, &(*st_mlx)->endian);
}

void	init_window(t_data *data, t_mlx *mlx)
{
	init_mlx(data, &(data->st_mlx));
	draw_celling_floor(data, data->st_mlx);
    mlx_hook(mlx->mlx_win, 17, 0, ft_close, data);
    mlx_hook(mlx->mlx_win, KeyPress, KeyPressMask, check_keys, data);
    mlx_loop(mlx->mlx);
}
