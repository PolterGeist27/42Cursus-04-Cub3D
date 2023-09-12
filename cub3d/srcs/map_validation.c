/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:27:56 by pealexan          #+#    #+#             */
/*   Updated: 2023/09/12 15:01:24 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	map_padding(t_data *data)
{
	char	**padded;
	int		y;
	int		x;

	y = -1;
	x = 0;
	padded = (char **)malloc(sizeof(char *) * (data->map_h + 1));
	while (data->map[++y])
	{
		x = 0;
		padded[y] = (char *)malloc(sizeof(char) * (data->map_w + 1));
		while (x < data->map_w)
		{
			if (!data->map[y][x] || ft_isspace(data->map[y][x]))
				padded[y][x] = 64;
			else
				padded[y][x] = data->map[y][x];
			x++;
		}
		padded[y][x] = 0;
	}
	padded[y] = NULL;
	y = -1;
	while (padded[++y])
		ft_printf("%s\n", padded[y]);
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

/* int	flood_fill(t_data *data, )
{
	static int	collectibles;
	static int	i;

	if (map[y][x] == '1')
		return (0);
	else if (map[y][x] == 'C')
		collectibles++;
	else if (map[y][x] == 'E')
	{
		i = 1;
		return (0);
	}
	if (map[y][x] != 'E')
		map[y][x] = '1';
	flood_fill(v, map, x + 1, y);
	flood_fill(v, map, x - 1, y);
	flood_fill(v, map, x, y + 1);
	flood_fill(v, map, x, y - 1);
	if (collectibles == v->c && i == 1)
		return (1);
	else
		return (0);
} */

void	map_width(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		if (!ft_strlen(data->map[i]))
			clean_structs(data, "Error\nDivided map detected\n", 0, 1);
		if (ft_strlen(data->map[i]) > (size_t)data->map_w)
			data->map_w = ft_strlen(data->map[i]);
		if (!map_element(data->map[i]))
			clean_structs(data, "Error\nInvalid map element detected\n", 0, 1);
		i++;
	}
}

void	map_validation(t_data *data)
{
	map_width(data);
	map_padding(data);
}