/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:17:25 by pealexan          #+#    #+#             */
/*   Updated: 2023/06/13 15:45:49 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	exit_window(t_cub *cub)
{
	//add all frees as necessary
	mlx_destroy_window(cub->mlx_ptr, cub->win_ptr);
	mlx_destroy_display(cub->mlx_ptr);
	free(cub->mlx_ptr);
	exit(0);
}

int	check_key(int keycode, t_cub *cub)
{
	if (keycode == ESC)
		exit_window(cub);
	else if (keycode == W)
		printf("W\n");
	else if (keycode == A)
		printf("A\n");
	else if (keycode == S)
		printf("S\n");
	else if (keycode == D)
		printf("D\n");
	else if (keycode == LEFT)
		printf("Left Arrow\n");
	else if (keycode == RIGHT)
		printf("Right Arrow\n");
	else
		printf("%d\n", keycode);
	return (0);
}

void	window_start(t_cub *cub)
{
	cub->mlx_ptr = mlx_init();
	if (!cub->mlx_ptr)
	{
		ft_putstr_fd("Could not allocate mlx_ptr\n", 2);
		exit(2);
	}
	cub->win_ptr = mlx_new_window(cub->mlx_ptr, 1920, 1080, "cub3D");
	if (!cub->win_ptr)
	{
		ft_putstr_fd("Could not allocate win_ptr\n", 2);
		mlx_destroy_display(cub->mlx_ptr);
		free(cub->mlx_ptr);
		exit(2);
	}
}

void	file_type(char *file)
{
	char	*temp;
	int		fd;
	
	fd = 0;
	temp = ft_strrchr(file, '.');
	if (ft_strlen(temp) != 4 || ft_strncmp(temp, ".cub", 4))
	{
		ft_putstr_fd("Invalid file type\n", 2);
		exit(2);
	}
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("File does not exist\n", 2);
		exit(2);
	}
	close(fd);
}

void	init_cub(t_cub *cub)
{
	cub->mlx_ptr = NULL;
	cub->win_ptr = NULL;
}

int	main(int ac, char **av)
{
	t_cub	cub;
	
	init_cub(&cub);
	if (ac != 2)
	{
		ft_putstr_fd("Wrong number of arguments\n", 2);
		exit(2);
	}
	file_type(av[1]);
	window_start(&cub);
	mlx_hook(cub.win_ptr, 17, 0, exit_window, &cub);
	mlx_hook(cub.win_ptr, KeyPress, KeyPressMask, check_key, &cub);
	mlx_loop(cub.mlx_ptr);
	printf("OLA\n");
	return (0);
}