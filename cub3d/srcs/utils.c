/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:37:19 by diogmart          #+#    #+#             */
/*   Updated: 2023/09/05 11:21:34 by diogmart         ###   ########.fr       */
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
	This function will receive the color values of the celling ("C")
	and floor ("F") and convert them into their hex value, saving the
	result in the variables in data;

	Notes:
		-funtion is wrong;
		-is it really needed to pass to hex ???
*/

/* void	char_to_hex(t_data **data, char *nbr)
{
	char	**array;
	char	option;
	int		i;
	int		n;
	int		result;

	i = 0;
	while (*nbr && (*nbr != 'F' || *nbr != 'C'))
		nbr++;
	option = *nbr;
	while (*nbr && !ft_isnumeric(*nbr))
		nbr++;
	result = 0x0;
	array = ft_split(nbr, ',');
	while (array && array[i] != NULL)
	{
		n = ft_atoi(array[i]);
		if (n < 0 || n > 255)
		{
			ft_free_split(array);
			ft_error(data);
		}
		result = (result * 256) + n;
		i++;
	}
	if (option == 'F')
		(*data)->F = result;
	else if (option == 'C')
		(*data)->C = result;
	else
		ft_error(data);
} */
