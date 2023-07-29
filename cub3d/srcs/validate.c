/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:31:28 by diogmart          #+#    #+#             */
/*   Updated: 2023/07/29 10:44:19 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int	check_walls(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i] != NULL)
	{
		if (i == 0 || i == (data->map_h - 1))
		{
			while (data->map[i][j] != '\0')
			{
				if (data->map[i][j] != '1')
					return (1);
				j++;
			}
			j = 0;
		}
		else
		{
			if (data->map[i][0] != '1' || data->map[i][data->map_w - 1] != '1')
				return (1);
		}
		i++;
	}
	return (0);
}
