/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:27:56 by pealexan          #+#    #+#             */
/*   Updated: 2023/09/20 16:32:30 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	map_copy(t_data *data, char **padded)
{
	int	y;
	int	x;
	int	a;
	int	b;

	a = 0;
	y = 2;
	while (data->map[a])
	{
		x = 2;
		b = 0;
		while (data->map[a][b])
		{
			if (ft_isspace(data->map[a][b]))
				b++;
			else
			{
				padded[y][x] = data->map[a][b];
				b++;
			}
			x++;
		}
		y++;
		a++;
	}
}

void	map_padding(t_data *data, char **padded)
{
	int		y;
	int		x;

	y = 0;
	while (y < data->map_h + 4)
	{
		x = 0;
		padded[y] = (char *)malloc(sizeof(char) * (data->map_w + 5));
		while (x < data->map_w + 4)
		{
			if (y == 0 || x == 0 || y == data->map_h + 3
				|| x == data->map_w + 3)
				padded[y][x] = '$';
			else if (y == 1 || x == 1 || y == data->map_h + 3
				|| x == data->map_w)
				padded[y][x] = '@';
			else
				padded[y][x] = '@';
			x++;
		}
		padded[y][x] = '\0';
		y++;
	}
	padded[y] = NULL;
}

int	map_element(char *map, int *player)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (!ft_isspace(map[i]) && !ft_strchr(ALLOWED_CHARS, map[i]))
			return (0);
		if (ft_strchr("NSEW", map[i]) && *player <= 1)
			*player += 1;
		else if (ft_strchr("NSEW", map[i]) && *player > 1)
			return (2);
		i++;
	}
	return (1);
}

int	flood_fill(t_data *data, char **map, int x, int y)
{
	static int	i;

	if (map[y][x] == '$' || map[y][x] == '1')
		return (0);
	else if (ft_strchr(FFILL, map[y][x]))
	{
		i = 1;
		return (1);
	}
	if (map[y][x] != '1')
		map[y][x] = '$';
	flood_fill(data, map, x + 1, y);
	flood_fill(data, map, x - 1, y);
	flood_fill(data, map, x, y + 1);
	flood_fill(data, map, x, y - 1);
	if (i == 1)
		return (1);
	else
		return (0);
}

void	map_validation(t_data *data)
{
	int		i;
	int		player;
	char	**padded;

	i = 0;
	player = 0;
	while (data->map[i])
	{
		if (ft_strlen(data->map[i]) > (size_t)data->map_w)
			data->map_w = ft_strlen(data->map[i]);
		if (!map_element(data->map[i], &player))
			clean_structs(data, "Error\nInvalid map element detected\n", 0, 1);
		if (map_element(data->map[i], &player) == 2)
			clean_structs(data, "Error\nDouble player detected\n", 0, 1);
		i++;
	}
	if (player == 0)
		clean_structs(data, "Error\nNo player detected\n", 0, 1);
	padded = (char **)malloc(sizeof(char *) * (data->map_h + 5));
	map_padding(data, padded);
	map_copy(data, padded);
	if (flood_fill(data, padded, 1, 1))
		clean_structs(data, "Error\nMap is not surrounded\n", padded, 1);
}
