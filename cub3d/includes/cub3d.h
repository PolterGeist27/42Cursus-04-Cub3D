/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:59:40 by diogmart          #+#    #+#             */
/*   Updated: 2023/09/04 12:40:06 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>

typedef struct s_player
{
	float	x;
	float	y;
	char	direction;
}	t_player;

typedef struct s_mlx {
	void		*mlx;
	void		*mlx_win;
	int			img_w;
	int			img_h;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}	t_mlx;

typedef struct s_data {

	t_mlx	*st_mlx; // st = struct

	int			map_w;
	int			map_h;
	char		**map;

	t_player	player;

}	t_data;

//		NEEDED TEXTURES		//
typedef enum e_textures {
	NO,
	SO,
	WE,
	EA,
	F,
	C	
}	t_textures;

//      KEY VALUES:     //
# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 65361
# define RIGHT 65363

//      init.c          //
void	init_data(t_data *data, t_mlx **st_mlx);
int		ft_close(t_data *data, t_mlx *st_mlx);
void	ft_error(t_data **data);
void	free_data(t_data *data);
void	init_mlx(t_data *data, t_mlx *mlx);

//      keys.c          //
int		check_keys(int key, t_data *data);

//		read_file.c		//
int		get_width(char *file_name);
int		get_height(char *file_name);
void	fill_row(char *row, char *line);
void	read_file(t_data **data, char *file_name);

//		utils.c			//
int		ft_ccount(char *str);
char	*ft_remove_spaces(char *str);

//		validate.c		//
void	file_type(char *file);
int		check_walls(t_data *data);
int		check_allowed_chars(t_data *data);

//		draw.c			//
int		check_limits(t_data *data, int x, int y);
void	my_mlx_pixel_put(t_mlx *st_mlx, int x, int y, int color);
void	draw_map2D(t_data *data, t_mlx *st_mlx);

#endif