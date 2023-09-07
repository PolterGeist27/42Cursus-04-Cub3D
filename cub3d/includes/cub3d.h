/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:59:40 by diogmart          #+#    #+#             */
/*   Updated: 2023/09/07 16:37:32 by pealexan         ###   ########.fr       */
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

//      KEY VALUES:     //
# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 65361
# define RIGHT 65363

# define ALLOWED_CHARS "01NSEW"

typedef struct s_textures
{
	char	*NO_path;
	char	*SO_path;
	char	*EA_path;
	char	*WE_path;
	char	*C_colour;
	char	*F_colour;
	void	*NO_img;
	void	*SO_img;
	void	*EA_img;
	void	*WE_img;
}	t_textures;

typedef struct s_player
{
	double	x;
	double	y;

	double		dirX;
	double		dirY;

	double planeX;
	double planeY;
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

	char		**map;
	int			map_w;
	int			map_h;

	char		**file;
	int			file_h;

	t_textures		*textures;

/* 	int			F[3];
	int			C[3]; */

	t_player	*player;

}	t_data;

//		NEEDED TEXTURES		//
/* typedef enum e_textures {
	NO,
	SO,
	WE,
	EA,
	F,
	C	
}	t_textures; */



//      init.c          //
void	init_data(t_data *data, t_mlx **st_mlx);
int		ft_close(t_data *data, t_mlx *st_mlx);
void	ft_error(t_data **data);
void	free_data(t_data *data);
void	init_window(t_data *data, t_mlx *mlx);

//      keys.c          //
int		check_keys(int key, t_data *data);

//		read_file.c		//
int		get_width(char *file_name);
int		get_height(char *file_name);
void	fill_row(char *row, char *line);
void	read_file(t_data **data, char *file_name);
//void	copy_file(t_data **data, char *file_name);

//		utils.c			//
int		ft_ccount(char *str);
char	*ft_remove_spaces(char *str);
int		is_line_c(char *line, char c);

//		validate.c		//
//void	file_type(char *file);
int		check_walls(t_data *data);
int		check_allowed_chars(t_data *data);

//		validate2.c		//
int		check_info(t_data *data, char *line);

//		draw.c			//
int		check_limits(t_data *data, int x, int y);
void	my_mlx_pixel_put(t_mlx *st_mlx, int x, int y, int color);
void	draw_map2D(t_data *data, t_mlx *st_mlx);
void	draw_celling_floor(t_data *data, t_mlx *st_mlx);



void	file_type(char *file, t_data *data);
void	file_elements(t_data *data);
void	handle_elements(char **check, t_data *data);
int		valid_element(char *identifier);
void	simple_init(t_data *data);
void	clean_structs(t_data *data, int i);
void	copy_file(t_data *data, char *file);
void	start_mapping(t_data *data, int i);


#endif