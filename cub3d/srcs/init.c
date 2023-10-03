/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:57:25 by diogmart          #+#    #+#             */
/*   Updated: 2023/10/03 10:29:22 by diogmart         ###   ########.fr       */
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
	if (!data->textures)
		ft_error(data, "malloc of t_textures failed.\n");
	data->textures->no_path = NULL;
	data->textures->so_path = NULL;
	data->textures->ea_path = NULL;
	data->textures->we_path = NULL;
	data->textures->c_colour = 0;
	data->textures->f_colour = 0;
	data->player = (t_player *)malloc(sizeof(t_player));
	if (!data->player)
		ft_error(data, "malloc of t_player failed/");
	init_player(data->player);
}

int	ft_close(t_data *data)
{
	t_mlx	*st_mlx;

	st_mlx = data->st_mlx;
	if (data->textures)
		free_textures(data->textures, data->st_mlx);
	mlx_destroy_window(st_mlx->mlx, st_mlx->mlx_win);
	mlx_destroy_image(st_mlx->mlx, st_mlx->img);
	mlx_destroy_display(st_mlx->mlx);
	free(st_mlx->mlx);
	free_data(data);
	exit(EXIT_SUCCESS);
}

void	ft_error(t_data *data, char *error)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(error, 2);
	if (data->textures)
		free_textures(data->textures, data->st_mlx);
	if (data->st_mlx->mlx)
	{
		mlx_destroy_window(data->st_mlx->mlx, data->st_mlx->mlx_win);
		mlx_destroy_image(data->st_mlx->mlx, data->st_mlx->img);
		mlx_destroy_display(data->st_mlx->mlx);
	}
	if (data->st_mlx->mlx)
		free(data->st_mlx->mlx);
	free_data(data);
	exit(1);
}

void	free_data(t_data *data)
{
	if (data->st_mlx)
		free(data->st_mlx);
	if (data->player)
		free(data->player);
	if (data->file)
		ft_free_split(data->file);
	if (data->map)
		ft_free_split(data->map);
	free(data);
}

void	free_textures(t_textures *textures, t_mlx *st_mlx)
{
	if (st_mlx && st_mlx->mlx && textures->no->img)
		mlx_destroy_image(st_mlx->mlx, textures->no->img);
	if (st_mlx && st_mlx->mlx && textures->so->img)
		mlx_destroy_image(st_mlx->mlx, textures->so->img);
	if (st_mlx && st_mlx->mlx && textures->ea->img)
		mlx_destroy_image(st_mlx->mlx, textures->ea->img);
	if (st_mlx && st_mlx->mlx && textures->we->img)
		mlx_destroy_image(st_mlx->mlx, textures->we->img);
	free(textures->no);
	free(textures->so);
	free(textures->ea);
	free(textures->we);
	free(textures->no_path);
	free(textures->so_path);
	free(textures->ea_path);
	free(textures->we_path);
	free(textures);
}
