/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:37:19 by diogmart          #+#    #+#             */
/*   Updated: 2023/09/20 11:35:30 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_ccount(char *str)
{
	int i;
	int	count;

	i = 0;
	count = 0;
	while(str && str[i] != '\0')
	{
		if (str[i] != '\n' && str[i] != ' ')
			count++;
		i++;
	}
	return (count);
}

char	*ft_remove_spaces(char *str)
{
	int 	i;
	int		j;
	char	*final;

	i = 0;
	j = 0;
	final = (char *)malloc(sizeof(char) * (ft_ccount(str) + 1));
	while(str[i] != '\0' && str[i] != '\n')
	{
		if (str[i] != '\n' && str[i] != ' ')
		{
			final[j] = str[i];
			j++;
		}
		i++;
	}
	final[j] = '\0';
	return (final);
}

/*
	to pass rgb to hex:

	r * 0x010000 + g * 0x000100 + b
*/

int	rgb_to_hex(char *rgb)
{
	int		result;
	int 	red;
	int		green;
	int		blue;
	char	**rgb_split;

	if (!rgb)
		return (0);
	rgb_split = ft_split(rgb, ',');
	red = ft_atoi(rgb_split[0]);
	green = ft_atoi(rgb_split[1]);
	blue = ft_atoi(rgb_split[2]);
	result = (red * 0x010000) + (green * 0x000100) + blue;
	ft_free_split(rgb_split);
	free(rgb);
	return (result);
}

void	get_player_data(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < data->map_w)
	{
		y = 0;
		while (y < data->map_h)
		{
			if (ft_strchr("NSEW", data->map[y][x]) && data->map[y][x] != '\0')
			{
				data->player->pos_x = x + 0.5;
				data->player->pos_y = y - 0.5;
				get_player_dir(data, x, y);
				return ;
			}
			y++;
		}
		x++;
	}
}

void	get_player_dir(t_data *data, int x, int y)
{
	if (data->map[y][x] == 'N')
	{
		data->player->dir_x = 0;
		data->player->dir_y = -1;
		data->player->plane_x = 1;
		data->player->plane_y = 0;
	}
	else if (data->map[y][x] == 'S')
	{
		data->player->dir_x = 0;
		data->player->dir_y = 1;
		data->player->plane_x = -1;
		data->player->plane_y = 0;
	}
	else if (data->map[y][x] == 'E')
	{
		data->player->dir_x = 1;
		data->player->dir_y = 0;
		data->player->plane_x = 0;
		data->player->plane_y = -1;
	}
	else if (data->map[y][x] == 'W')
	{
		data->player->dir_x = -1;
		data->player->dir_y = 0;
		data->player->plane_x = 0;
		data->player->plane_y = 1;
	}
}
