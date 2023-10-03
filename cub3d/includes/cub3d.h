/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:59:40 by diogmart          #+#    #+#             */
/*   Updated: 2023/10/03 10:26:27 by diogmart         ###   ########.fr       */
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
# define FFILL "0NSEW"

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		height;
	int		width;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

}	t_image;

typedef struct s_textures
{
	float	tex_step;
	float	tex_pos;
	int		color;

	char	*no_path;
	char	*so_path;
	char	*ea_path;
	char	*we_path;
	int		c_colour;
	int		f_colour;
	t_image	*no;
	t_image	*so;
	t_image	*ea;
	t_image	*we;

}	t_textures;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;

	double	dir_x;
	double	dir_y;

	double	plane_x;
	double	plane_y;

	double	fov;

	double	camera_x;
	double	raydir_x;
	double	raydir_y;

	int		map_x;
	int		map_y;

	int		step_x;
	int		step_y;

	double	side_dist_x;
	double	side_dist_y;

	double	delta_dist_x;
	double	delta_dist_y;

	int		hit;
	int		side;

	double	wall_dist;
	int		line_height;

	int		draw_start;
	int		draw_end;

	int		up;
	int		down;
	int		left;
	int		right;

	int		rotcw;
	int		rotccw;
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
	t_mlx		*st_mlx;

	char		**map;
	int			map_w;
	int			map_h;

	char		**file;
	int			file_h;
	int			element_no;
	t_textures	*textures;
	t_player	*player;
	int			wall_dir;

}	t_data;

//      init.c          //
void	init_data(t_data *data);
int		ft_close(t_data *data);
void	ft_error(t_data *data, char *error);
void	free_data(t_data *data);
void	free_textures(t_textures *textures, t_mlx *st_mlx);

//		init2.c			//
void	init_mlx(t_data *data, t_mlx **st_mlx);
void	init_window(t_data *data);
void	init_player(t_player *player);

//      keys.c          //
int		check_keys(int key, t_data *data);
int		release_movement(int key, t_data *data);

//		read_file.c		//
int		get_width(char *file_name);
int		get_height(char *file_name);
void	fill_row(char *row, char *line);
void	read_file(t_data **data, char *file_name);

//		utils.c			//
void	get_wall_direction(t_data *data, t_player *player);
int		rgb_to_hex(char *rgb);
void	get_player_data(t_data *data);
void	get_player_dir(t_data *data, int x, int y);
void	get_player_dir2(t_data *data, int x, int y);

//		draw.c			//
void	my_mlx_pixel_put(t_mlx *st_mlx, int x, int y, int color);
void	draw_map2D(t_data *data, t_mlx *st_mlx);
void	draw_celling_floor(t_data *data, t_mlx *st_mlx);
void	draw_vertical_line(t_data *data, int x, int color);

//		raycasting.c	//
int		raycasting(t_data *data);
void	get_values(t_data *data, t_player *player, int x);
void	get_step(t_player *player);
void	get_wall_dist(t_data *data, t_player *player);
void	perform_dda(t_data *data, t_player *player);

//		movement.c		//
void	move_vertical(t_data *data, t_player *player, int dir);
void	move_horizontal(t_data *data, t_player *player, int dir);
void	rotate_player(t_data *data, t_player *player, int dir);

//		loop.c			//
int		raycasting_loop(t_data *data);

//		textures.c		//
int		is_xpm(t_textures *textures, int tex);
int		check_access(t_textures *textures);
void	load_xpm(t_data *data, t_image *img, char *file);
void	convert_textures(t_data *data);
int		check_textures(t_data *data);

//		textures_utils.c	//
int		get_texture_addr(t_image *img);
void	apply_textures(t_data *data, t_textures *textures, int x);

void	file_type(char *file, t_data *data);
void	file_elements(t_data *data);
void	handle_elements(char **check, t_data *data);
int		valid_element(char *identifier);
void	simple_init(t_data *data);
void	clean_structs(t_data *data, char *error, char **split, int i);
void	copy_file(t_data *data, char *file);
void	start_mapping(t_data *data, int i);
int		is_map(t_data *data, int i, int element_no);
void	map_validation(t_data *data);
int		flood_fill(t_data *data, char **map, int x, int y);

#endif