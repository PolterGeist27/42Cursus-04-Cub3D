/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:58:36 by diogmart          #+#    #+#             */
/*   Updated: 2023/09/05 12:19:54 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	save_texture(t_data *data, char *path)
{
	int fd;

	fd = open(path, O_RDONLY, 0);
	if (fd <= 0)
		return (1);
	
}


int	save_color(t_data *data, char *line)
{
    if (!ft_strncmp("C ", line, 2))
    {
		
		return (0);
    }
    if (!ft_strncmp("F ", line, 2))
    {
       
	   return (0);
    }
	return (1); 
}