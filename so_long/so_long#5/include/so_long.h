/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:05:47 by mgallais          #+#    #+#             */
/*   Updated: 2023/12/19 11:52:55 by mgallais         ###   ########.fr       */
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

typedef struct s_data
{
	int			window_height;
	int			window_width;
	char		**map;
	int			start_x;
	int			start_y;
	int			cur_x;
	int			cur_y;
	int			size_x;
	int			size_y;
	int			index;
	mlx_t		mlx;
	mlx_image_t	mlx_image;
}	t_data;

typedef struct s_error
{
	char	*gnl_result;
	char	*previous_result;
	char	**check;
	int		i;
	int		size;
	int		start_amount;
	int		collectible_i;
	int		collectible_amount;
	int		exit_i;
	int		exit_amount;
}	t_error;

// Checking
void	ber_check(int argc, char **argv, t_data *data);
void	doublon_error(t_error *error);
void	error_exit(char *strerror);
void	check_walls(int fd);
void	map_parsing(t_data *data, t_error *error, int fd);
int		check_is_possible(t_data *data, t_error *error, int y, int x);

int		fd_close_open(int fd, char *filepath, bool do_close);

#endif