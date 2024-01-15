/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:05:47 by mgallais          #+#    #+#             */
/*   Updated: 2024/01/15 15:04:58 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <MLX42/MLX42.h>
# include "libft.h"

/* WARNING : YOU MUST CHANGE THE RESOLUTION OF THE */
/* SPRITES TO EFFECTIVELY CHANGE THE SPRITE SIZE   */
# define SPRITE_SIZE 64

/* FPS is used for the usleep in the movements controls */
/* Keep in mind the function usleed take microsecond    */
# define FPS 100000

typedef struct s_gem
{
	int		y;
	int		x;
	char	gem_color;
	int		gem_instance;
}	t_gem;

typedef struct s_texture
{
	mlx_texture_t	*back;
	mlx_texture_t	*wall;
	mlx_texture_t	*play;
	mlx_texture_t	*exit;
	mlx_texture_t	*ggem;
	mlx_texture_t	*bgem;
	mlx_texture_t	*wgem;
	mlx_texture_t	*rgem;
	mlx_texture_t	*sklt;
}	t_texture;

typedef struct s_image
{
	mlx_image_t		*back;
	mlx_image_t		*wall;
	mlx_image_t		*play;
	mlx_image_t		*exit;
	mlx_image_t		*ggem;
	mlx_image_t		*bgem;
	mlx_image_t		*wgem;
	mlx_image_t		*rgem;
	mlx_image_t		*sklt;
}	t_image;

typedef struct s_data
{
	t_texture	texture;
	t_image		image;
	mlx_t		*mlx;
	char		**map;
	char		**check_map;
	int			cur_x;
	int			cur_y;
	int			size_x;
	int			size_y;
	int			start_amount;
	int			collectible_i;
	int			collectible_amount;
	int			exit_i;
	int			exit_amount;
	int			movements;
}	t_data;

void	error_exit(t_data *data, char *strerror);

// ber_checking
void	ber_check(int argc, char **argv, t_data *data);
void	map_parsing(t_data *data, char *filepath);
void	create_map(t_data *data, char *filepath);
void	doublon_error(t_data *data);
void	check_walls(t_data *data);
int		check_is_possible(t_data *data, int y, int x);
void	putmap(t_data *data);

// graphism
void	map_making(t_data *data);
void	map_rendering(t_data *data);
void	load_textures(t_data *data);
void	destroy_textures(t_data *data);
void	up(t_data *data);
void	down(t_data *data);
void	left(t_data *data);
void	right(t_data *data);
int		movement_check_wall(t_data *data, int y, int x);
void	movement_check_collectible(t_data *data);
void	movement_check_exit(t_data *data);
#endif
