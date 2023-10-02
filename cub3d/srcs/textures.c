/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:58:36 by diogmart          #+#    #+#             */
/*   Updated: 2023/10/02 11:28:34 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_xpm(t_textures *textures)
{
	int		tex;
	int		len;
	int		i;
	char	*filename;
	char	*filetype;

	tex = 0;
	filetype = ".xpm";
	while (tex < 4)
	{
		if (tex == 0)
			filename = ft_strdup(textures->NO_path);
		if (tex == 1)
			filename = ft_strdup(textures->SO_path);
		if (tex == 2)
			filename = ft_strdup(textures->EA_path);
		if (tex == 3)
			filename = ft_strdup(textures->WE_path);
		i = 4;
		len = ft_strlen(filename);
		while (i)
			if (filename[len--] != filetype[i--])
				return (free(filename), 1);
		free(filename);
		tex++;
	}
	return (0);
}

int	check_access(t_textures *textures)
{
	int	fd[4];

	fd[0] = open(textures->NO_path, O_RDONLY);
	fd[1] = open(textures->SO_path, O_RDONLY);
	fd[2] = open(textures->EA_path, O_RDONLY);
	fd[3] = open(textures->WE_path, O_RDONLY);
	close(fd[0]);
	close(fd[1]);
	close(fd[2]);
	close(fd[3]);
	if (fd[0] < 0 || fd[1] < 0 || fd[2] < 0 || fd[3] < 0)
		return (1);
	return (0);
}

void	load_xpm(t_data *data, t_image *img, char *file)
{
	img->height = 0;
	img->width = 0;
	img->img = mlx_xpm_file_to_image(data->st_mlx->mlx, file, &img->width, &img->height);
	if (!img->img)
	{
		printf("Error: Failed loading %s texture", file);
		exit(EXIT_FAILURE);
	}
}

void	convert_textures(t_data *data)
{
	data->textures->tex = ft_calloc(4, sizeof(int *));
	load_xpm(data, data->textures->NO, data->textures->NO_path);
	load_xpm(data, data->textures->SO, data->textures->SO_path);
	load_xpm(data, data->textures->EA, data->textures->EA_path);
	load_xpm(data, data->textures->WE, data->textures->WE_path);
	data->textures->tex[0] = get_texture_addr(data->textures->NO);
	data->textures->tex[1] = get_texture_addr(data->textures->SO);
	data->textures->tex[2] = get_texture_addr(data->textures->EA);
	data->textures->tex[3] = get_texture_addr(data->textures->WE);
}

int	check_textures(t_data *data)
{
	data->textures->NO = ft_calloc(1, sizeof(t_image));
	data->textures->SO = ft_calloc(1, sizeof(t_image));
	data->textures->EA = ft_calloc(1, sizeof(t_image));
	data->textures->WE = ft_calloc(1, sizeof(t_image));
	if (is_xpm(data->textures))
		return (1);
	if (check_access(data->textures))
		return (1);
	convert_textures(data);
	return (0);
}
