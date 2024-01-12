/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_making.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 08:38:24 by mgallais          #+#    #+#             */
/*   Updated: 2024/01/12 14:50:58 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	player_commands(void *param)
{
	t_data		*data;

	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP)
		|| mlx_is_key_down(data->mlx, MLX_KEY_W))
		up(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN)
		|| mlx_is_key_down(data->mlx, MLX_KEY_S))
		down(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT)
		|| mlx_is_key_down(data->mlx, MLX_KEY_A))
		left(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT)
		|| mlx_is_key_down(data->mlx, MLX_KEY_D))
		right(data);
}

void	map_making(t_data *data)
{
	data->mlx = mlx_init(data->size_x * SPRITE_SIZE,
			data->size_y * SPRITE_SIZE, "So_long", true);
	if (!(data->mlx))
		error_exit(data, "Window couldn't be created");
	load_textures(data);
	map_rendering(data);
	data->collectible_i = 0;
	mlx_loop_hook(data->mlx, player_commands, data);
	mlx_loop(data->mlx);
	destroy_textures(data);
	mlx_terminate(data->mlx);
}
