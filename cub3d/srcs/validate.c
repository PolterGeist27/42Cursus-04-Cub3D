/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:31:28 by diogmart          #+#    #+#             */
/*   Updated: 2023/09/27 12:30:16 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

/*
	Subject rules:
		"The map must be composed of only 6 possible characters: 0 for an empty space,
		1 for a wall, and N,S,E or W for the player’s start position and spawning
		orientation."
*/

int	check_allowed_chars(t_data *data)
{
	char	*allowed_chars;
	int		i;
	int		j;

	i = 0;
	j = 0;
	allowed_chars = "01NSEW";
	while (data->map[i] && i < data->map_h)
	{
		while (data->map[i][j] != '\0' && j < data->map_w)
		{
			if (!ft_strchr(allowed_chars, data->map[i][j]))
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
