/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:10:05 by diogmart          #+#    #+#             */
/*   Updated: 2023/09/05 12:10:58 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_info(t_data *data, char *line)
{
    if (!ft_strncmp("NO ", line, 3))
    {
        //save_texture();
        return (0);
    }
    if (!ft_strncmp("SO ", line, 3))
    {
        //save_texture();
        return (0);
    }
    if (!ft_strncmp("WE ", line, 3))
    {
        //save_texture();
        return (0);
    }
    if (!ft_strncmp("EA ", line, 3))
    {
        //save_texture();
        return (0);
    }
    return (1);
}
