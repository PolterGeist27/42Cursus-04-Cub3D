/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:59:40 by diogmart          #+#    #+#             */
/*   Updated: 2023/06/20 16:10:40 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "libft.h"
#include "../minilibx-linux/mlx.h"
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

typedef struct s_data {
	int		map_w;
	int		map_h;
	int		**map;

    // Minilibx
	void	*mlx;
	void	*mlx_win;
	int		img_w;
	int		img_h;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

//      KEY VALUES:     //
#define ESC 65307

//      init.c          //
void	init_data(t_data *data);
int	    ft_close(t_data *data);

//      keys.c          //
int	    check_keys(int key, t_data *data);

#endif