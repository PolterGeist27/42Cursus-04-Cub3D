/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:27:56 by pealexan          #+#    #+#             */
/*   Updated: 2023/09/12 12:59:13 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	map_padding(t_data *data)
{
	char	**temp;

	
}

int	map_element(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (!ft_isspace(map[i]) && !ft_strchr(ALLOWED_CHARS, map[i]))
			return (0);
		i++;
	}
	return (1);
}

void	map_width(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		if (ft_strlen(data->map[i]) > (size_t)data->map_w)
			data->map_w = ft_strlen(data->map[i]);
		if (!map_element(data->map[i]))
			clean_structs(data, "Error\nNot a valid map element\n", 0, 1);
		i++;
	}
}

void	map_validation(t_data *data)
{
	map_width(data);
}