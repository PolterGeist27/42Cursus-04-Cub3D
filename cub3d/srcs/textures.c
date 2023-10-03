/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:58:36 by diogmart          #+#    #+#             */
/*   Updated: 2023/10/03 10:31:40 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_xpm(t_textures *textures, int tex)
{
	int		len;
	int		i;
	char	*filename;
	char	*filetype;

	filetype = ".xpm";
	while (tex < 4)
	{
		if (tex == 0)
			filename = ft_strdup(textures->no_path);
		if (tex == 1)
			filename = ft_strdup(textures->so_path);
		if (tex == 2)
			filename = ft_strdup(textures->ea_path);
		if (tex == 3)
			filename = ft_strdup(textures->we_path);
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

	fd[0] = open(textures->no_path, O_RDONLY);
	fd[1] = open(textures->so_path, O_RDONLY);
	fd[2] = open(textures->ea_path, O_RDONLY);
	fd[3] = open(textures->we_path, O_RDONLY);
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
	img->img = mlx_xpm_file_to_image(data->st_mlx->mlx, file,
			&img->width, &img->height);
}

void	convert_textures(t_data *data)
{
	load_xpm(data, data->textures->no, data->textures->no_path);
	load_xpm(data, data->textures->so, data->textures->so_path);
	load_xpm(data, data->textures->ea, data->textures->ea_path);
	load_xpm(data, data->textures->we, data->textures->we_path);
	get_texture_addr(data->textures->no);
	get_texture_addr(data->textures->so);
	get_texture_addr(data->textures->ea);
	get_texture_addr(data->textures->we);
}

int	check_textures(t_data *data)
{
	data->textures->no = ft_calloc(1, sizeof(t_image));
	data->textures->so = ft_calloc(1, sizeof(t_image));
	data->textures->ea = ft_calloc(1, sizeof(t_image));
	data->textures->we = ft_calloc(1, sizeof(t_image));
	if (is_xpm(data->textures, 0))
		return (1);
	if (check_access(data->textures))
		return (1);
	convert_textures(data);
	return (0);
}
