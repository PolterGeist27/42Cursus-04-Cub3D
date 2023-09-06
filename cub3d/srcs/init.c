/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:57:25 by diogmart          #+#    #+#             */
/*   Updated: 2023/09/06 11:54:48 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_data(t_data *data, t_mlx **st_mlx)
{
	data->map = NULL;
	data->map_h = 0;
	data->map_w = 0;
	data->file = NULL;
	data->file_h = 0;
	data->st_mlx = malloc(sizeof(t_mlx));

	data->player->planeX = 0;
	data->player->planeY = 1;
    // Minilibx
	(*st_mlx)->mlx = mlx_init();
	(*st_mlx)->mlx_win = mlx_new_window((*st_mlx)->mlx, 1920, 1080, "Cub3D");
	(*st_mlx)->img_w = 1920;
	(*st_mlx)->img_h = 1080;
	(*st_mlx)->img = mlx_new_image((*st_mlx)->mlx, (*st_mlx)->img_w, (*st_mlx)->img_h);
	(*st_mlx)->addr = mlx_get_data_addr((*st_mlx)->img, &(*st_mlx)->bits_per_pixel,
			&(*st_mlx)->line_length, &(*st_mlx)->endian);
}

int	ft_close(t_data *data, t_mlx *st_mlx)
{
	mlx_destroy_window(st_mlx->mlx, st_mlx->mlx_win);
	mlx_destroy_image(st_mlx->mlx, st_mlx->img);
	mlx_destroy_display(st_mlx->mlx);
	free(st_mlx->mlx);
	free_data(data);
	exit(EXIT_SUCCESS);
}

void	ft_error(t_data **data)
{
	ft_putstr_fd("Error\n", 2);
	mlx_destroy_window((*data)->st_mlx->mlx, (*data)->st_mlx->mlx_win);
	mlx_destroy_image((*data)->st_mlx->mlx, (*data)->st_mlx->img);
	mlx_destroy_display((*data)->st_mlx->mlx);
	free((*data)->st_mlx->mlx);
	free_data(*data);
	exit(1);
}

void	free_data(t_data *data)
{
	free(data->st_mlx);
	ft_free_split(data->file);
	ft_free_split(data->map);
	free(data);
}

void	init_window(t_data *data, t_mlx *mlx)
{
	//draw_map2D(data, data->st_mlx);
	draw_celling_floor(data, data->st_mlx);
    mlx_hook(mlx->mlx_win, 17, 0, ft_close, data);
    mlx_hook(mlx->mlx_win, KeyPress, KeyPressMask, check_keys, data);
    mlx_loop(mlx->mlx);
    ft_close(data, data->st_mlx);
}
