/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 09:48:13 by pealexan          #+#    #+#             */
/*   Updated: 2023/09/07 16:56:26 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* This validates and saves texture elements in the data structures.
	It also copies the map part to its corresponding matrix.
	Now need to parse map for validation and make sure texture elements are well parsed */

#include "../includes/cub3d.h"

void	clean_structs(t_data *data, int i)
{
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

int	valid_element(char *identifier)
{
	if ((ft_strlen(identifier) == 2 && !ft_strncmp(identifier, "NO", 2)) ||
		(ft_strlen(identifier) == 2 && !ft_strncmp(identifier, "SO", 2)) ||
		(ft_strlen(identifier) == 2 && !ft_strncmp(identifier, "WE", 2)) ||
		(ft_strlen(identifier) == 2 && !ft_strncmp(identifier, "EA", 2)) ||
		(ft_strlen(identifier) == 1 && !ft_strncmp(identifier, "F", 1)) ||
		(ft_strlen(identifier) == 1 && !ft_strncmp(identifier, "C", 1)))
		return (1);
	else
		return (0);
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
	{
		ft_putstr_fd("Error\nDuplicate identifiers detected\n", 2);
		ft_free_split(check);
		clean_structs(data, 1);
	}
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
/* 	while (data->map[temp])
		ft_printf("%s", data->map[temp++]); */
}

void	file_elements(t_data *data)
{
	char	**check;
	int		i;
	int		element_no;

	i = 0;
	element_no = 0;	
	while (data->file[i++])
	{
		if (data->file[i][0] == '\n')
			continue;
		else if (ft_isspace(data->file[i][0]) || 
			(!ft_strchr(ALLOWED_CHARS, data->file[i][0]) && element_no == 6))
		{
			start_mapping(data, i);
			break ;
		}
		check = ft_split(data->file[i], ' ');
		if (valid_element(check[0]))
		{
			handle_elements(check, data);
			element_no++;
		}
		else
		{
			ft_putstr_fd("Wrong identifier detected\n", 2);
			ft_free_split(check);
			clean_structs(data, 1);
		}
		ft_free_split(check);
	}
}

int	get_lines(char *file)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		i++;
	}
	free(line);
	close(fd);
	return (i);
}

void	copy_file(t_data *data, char *file)
{
	char	*line;
	int		fd;
	int		i;

	i = get_lines(file);
	fd = open(file, O_RDONLY);
	if (i <= 0)
	{
		ft_putstr_fd("Error\nFile is empty\n", 2);
		clean_structs(data, 1);
	}
	data->file = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		data->file[i] = ft_strdup(line);
		free(line);
		i++;
	}
	free(line);
	data->file[i] = NULL;
	close(fd);
}

void	file_type(char *file, t_data *data)
{
	char	*temp;
	int		fd;

	fd = 0;
	temp = ft_strrchr(file, '.');
	if (ft_strlen(temp) != 4 || ft_strncmp(temp, ".cub", 4))
	{
		ft_putstr_fd("Error: Invalid file type\n", 2);
		clean_structs(data, 1);
	}
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error: File does not exist\n", 2);
		clean_structs(data, 1);
	}
	close(fd);
	copy_file(data, file);
	file_elements(data);
}
