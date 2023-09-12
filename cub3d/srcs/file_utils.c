/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:22:06 by pealexan          #+#    #+#             */
/*   Updated: 2023/09/12 11:23:38 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	valid_element(char *identifier)
{
	if ((ft_strlen(identifier) == 2 && !ft_strncmp(identifier, "NO", 2))
		|| (ft_strlen(identifier) == 2 && !ft_strncmp(identifier, "SO", 2))
		|| (ft_strlen(identifier) == 2 && !ft_strncmp(identifier, "WE", 2))
		|| (ft_strlen(identifier) == 2 && !ft_strncmp(identifier, "EA", 2))
		|| (ft_strlen(identifier) == 1 && !ft_strncmp(identifier, "F", 1))
		|| (ft_strlen(identifier) == 1 && !ft_strncmp(identifier, "C", 1)))
		return (1);
	else
		return (0);
}

int	is_map(t_data *data, int i, int element_no)
{
	if (ft_isspace(data->file[i][0]) && element_no == 6)
		return (1);
	if (ft_strchr(ALLOWED_CHARS, data->file[i][0]) && element_no == 6)
		return (1);
	return (0);
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
		clean_structs(data, "Error\nFile is empty\n", 0, 1);
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