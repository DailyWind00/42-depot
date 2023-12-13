/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:05:47 by mgallais          #+#    #+#             */
/*   Updated: 2023/12/13 11:41:53 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <MLX42/MLX42.h>

typedef struct s_data
{
	int			window_height;
	int			window_width;
	mlx_t		mlx;
	mlx_image_t	mlx_image;
}	t_data;

typedef struct s_error
{
	char	*gnl_result;
	char	*previous_result;
	int		i;
	int		start_amount;
	int		collectible_amount;
	int		exit_amount;
}	t_error;

#endif

