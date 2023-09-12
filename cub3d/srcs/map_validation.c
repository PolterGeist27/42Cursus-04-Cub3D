/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:27:56 by pealexan          #+#    #+#             */
/*   Updated: 2023/09/12 11:40:08 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	map_width(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		if (data->map[i + 1]
			&& (ft_strlen(data->map[i]) > (size_t)data->map_w))
			data->map_w = ft_strlen(data->map[i]);
		ft_putnbr(data->map_w);
		ft_putstr(data->map[i]);
		i++;
	}
}

void	map_validation(t_data *data)
{
	map_width(data);
}