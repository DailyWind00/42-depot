/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:05:47 by mgallais          #+#    #+#             */
/*   Updated: 2024/01/09 08:57:02 by mgallais         ###   ########.fr       */
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
	mlx_image_t* image;
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
}	t_data;


void	error_exit(t_data *data, char	*strerror);

// ber_checking
void	ber_check(int argc, char **argv, t_data *data);
void	map_parsing(t_data *data, char *filepath);
void	doublon_error(t_data *data);
void	check_rectangle(t_data *data);
void	check_walls(t_data *data);
int		check_is_possible(t_data *data, int y, int x);

// graphism
void	map_making(t_data *data);


#endif