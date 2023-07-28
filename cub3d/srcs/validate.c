/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:31:28 by diogmart          #+#    #+#             */
/*   Updated: 2023/07/28 11:10:39 by diogmart         ###   ########.fr       */
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
