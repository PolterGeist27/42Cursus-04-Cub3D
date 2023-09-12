/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:57:25 by diogmart          #+#    #+#             */
/*   Updated: 2023/09/12 12:48:57 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_data(t_data *data)
{
	data->map = NULL;
	data->map_h = 0;
	data->map_w = 0;
	data->file = NULL;
	data->file_h = 0;
	data->element_no = 0;
	data->textures = (t_textures *)malloc(sizeof(t_textures));
	//add malloc protection function
	data->textures->NO_path = NULL;
	data->textures->SO_path = NULL;
	data->textures->EA_path = NULL;
	data->textures->WE_path = NULL;
	data->textures->C_colour = NULL;
	data->textures->F_colour = NULL;
	data->player = (t_player *)malloc(sizeof(t_player));
	//add malloc protection function
	data->player->planeX = 0;
	data->player->planeY = 1;
}

int	ft_close(t_data *data)
{
	t_mlx *st_mlx;

	st_mlx = data->st_mlx;
	mlx_destroy_window(st_mlx->mlx, st_mlx->mlx_win);
	mlx_destroy_image(st_mlx->mlx, st_mlx->img);
	mlx_destroy_display(st_mlx->mlx);
	free(st_mlx->mlx);
	(void)data;
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
	if (data->player)
		free(data->player);
	if (data->textures)
		free_textures(data->textures);
	if (data->file)
		ft_free_split(data->file);
	if (data->map)
		ft_free_split(data->map);
	free(data);
}

void	free_textures(t_textures *textures)
{
	free(textures->NO_path);
	free(textures->SO_path);
	free(textures->EA_path);
	free(textures->WE_path);
	free(textures->C_colour);
	free(textures->F_colour);
	free(textures);
}