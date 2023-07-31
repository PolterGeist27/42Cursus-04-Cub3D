/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:21:50 by diogmart          #+#    #+#             */
/*   Updated: 2023/07/31 10:37:26 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_width(char *file_name)
{
	int		fd;
	int		width;
	int		word_count;
	char	*line;

	fd = open(file_name, 'r');
	line = get_next_line(fd);
	width = ft_ccount(line);
	while (line != NULL)
	{
		word_count = ft_ccount(line);
		if (width < word_count)
			width = word_count;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (width);
}

int	get_height(char *file_name)
{
	char	*line;
	int		height;
	int		fd;

	fd = open(file_name, 'r');
	height = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

void	read_file(t_data **data, char *file_name)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		ft_error(data);
	(*data)->map_h = get_height(file_name);
	(*data)->map_w = get_width(file_name);
	i = 0;
	(*data)->map = (char **)ft_calloc(sizeof(char *), ((*data)->map_h + 1));
	line = get_next_line(fd);
	while (line != NULL && i < ((*data)->map_h))
	{
		(*data)->map[i++] = ft_remove_spaces(line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
