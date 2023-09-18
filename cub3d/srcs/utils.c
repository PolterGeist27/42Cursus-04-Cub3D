/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:37:19 by diogmart          #+#    #+#             */
/*   Updated: 2023/09/18 12:47:36 by diogmart         ###   ########.fr       */
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
	Check is a given line is only made up of a char "c" and spaces
*/

int	is_line_c(char *line, char c)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != c && line[i] != ' ' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

/*
	to pass rgb to hex:

	r * 0x010000 + g * 0x000100 + b
*/

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
			if (ft_strchr("NSEW", data->map[y][x]))
			{
				data->player->pos_x = x;
				data->player->pos_y = y;
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
