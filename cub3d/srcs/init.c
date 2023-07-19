/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:57:25 by diogmart          #+#    #+#             */
/*   Updated: 2023/07/19 11:24:26 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_data(t_data *data)
{
	data->map_h = 0;
	data->map_w = 0;
	data->map = NULL;

    // Minilibx
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, 1920, 1080, "Cub3D");
	data->img_w = 1920;
	data->img_h = 1080;
	data->img = mlx_new_image(data->mlx, data->img_w, data->img_h);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
}

void	file_type(char *file)
{
	char	*temp;
	int		fd;
	
	fd = 0;
	temp = ft_strrchr(file, '.');
	if (ft_strlen(temp) != 4 || ft_strncmp(temp, ".cub", 4))
	{
		ft_putstr_fd("Invalid file type\n", 2);
		exit(2);
	}
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("File does not exist\n", 2);
		exit(2);
	}
	close(fd);
}

int	ft_close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	//free_data(data);
    free(data);
	exit(EXIT_SUCCESS);
}
