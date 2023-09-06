/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:37:19 by diogmart          #+#    #+#             */
/*   Updated: 2023/09/05 14:26:37 by diogmart         ###   ########.fr       */
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
