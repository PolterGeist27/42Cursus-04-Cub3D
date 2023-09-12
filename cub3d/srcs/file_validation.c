/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 09:48:13 by pealexan          #+#    #+#             */
/*   Updated: 2023/09/12 11:23:26 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	clean_structs(t_data *data, char *error, char **split, int i)
{
	if (error)
		ft_putstr_fd(error, 2);
	if (split)
		ft_free_split(split);
	if (data->file)
		ft_free_split(data->file);
	free(data->player);
	if (data->textures->C_colour)
		free(data->textures->C_colour);
	if (data->textures->F_colour)
		free(data->textures->F_colour);
	if (data->textures->NO_path)
		free(data->textures->NO_path);
	if (data->textures->SO_path)
		free(data->textures->SO_path);
	if (data->textures->EA_path)
		free(data->textures->EA_path);
	if (data->textures->WE_path)
		free(data->textures->WE_path);
	free(data->textures);
	free(data);
	if (i == 1)
		exit(2);
}

void	handle_elements(char **check, t_data *data)
{
	if (!ft_strncmp(check[0], "NO", 2) && data->textures->NO_path == NULL)
		data->textures->NO_path = ft_strtrim(check[1], "\n");
	else if (!ft_strncmp(check[0], "SO", 2) && data->textures->SO_path == NULL)
		data->textures->SO_path = ft_strtrim(check[1], "\n");
	else if (!ft_strncmp(check[0], "WE", 2) && data->textures->WE_path == NULL)
		data->textures->WE_path = ft_strtrim(check[1], "\n");
	else if (!ft_strncmp(check[0], "EA", 2) && data->textures->EA_path == NULL)
		data->textures->EA_path = ft_strtrim(check[1], "\n");
	else if (!ft_strncmp(check[0], "C", 1) && data->textures->C_colour == NULL)
		data->textures->C_colour = ft_strtrim(check[1], "\n");
	else if (!ft_strncmp(check[0], "F", 1) && data->textures->F_colour == NULL)
		data->textures->F_colour = ft_strtrim(check[1], "\n");
	else
		clean_structs(data, "Error\nDuplicate identifier detected\n", check, 1);
}

void	start_mapping(t_data *data, int i)
{
	int	temp;

	temp = i;
	while (data->file[temp++])
		data->map_h++;
	data->map = (char **)malloc(sizeof(char *) * (data->map_h + 1));
	temp = 0;
	while (data->file[i])
	{
		data->map[temp] = ft_strdup(data->file[i]);
		data->file[i] = NULL;
		i++;
		temp++;
	}
	temp = 0;
	while (data->map[temp])
		ft_printf("%s", data->map[temp++]);
}

void	file_elements(t_data *data)
{
	char	**check;
	int		i;

	i = -1;
	while (data->file[++i])
	{
		if (data->file[i] && data->file[i][0] == '\n')
			continue ;
		else if ((data->file[i] && is_map(data, i, data->element_no)))
		{
			start_mapping(data, i);
			break ;
		}
		else if (!data->file[i])
			clean_structs(data, "Error\nNo map detected\n", 0, 1);
		check = ft_split(data->file[i], ' ');
		if (valid_element(check[0]))
		{
			handle_elements(check, data);
			data->element_no++;
		}
		else
			clean_structs(data, "Error\nWrong identifier detected\n", check, 1);
		ft_free_split(check);
	}
}

void	file_type(char *file, t_data *data)
{
	char	*temp;
	int		fd;

	fd = 0;
	temp = ft_strrchr(file, '.');
	if (ft_strlen(temp) != 4 || ft_strncmp(temp, ".cub", 4))
		clean_structs(data, "Error\nInvalid file type\n", 0, 1);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		clean_structs(data, "Error\nFile does not exist\n", 0, 1);
	close(fd);
	copy_file(data, file);
	file_elements(data);
}
