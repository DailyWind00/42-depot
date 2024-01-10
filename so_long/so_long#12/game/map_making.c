/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_making.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 08:38:24 by mgallais          #+#    #+#             */
/*   Updated: 2024/01/10 09:32:45 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	player_commands(void *param)
{
	t_data	*data;

	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP)
		|| mlx_is_key_down(data->mlx, MLX_KEY_W))
		(data->cur_x)--;
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN)
		|| mlx_is_key_down(data->mlx, MLX_KEY_S))
		(data->cur_y)++;
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT)
		|| mlx_is_key_down(data->mlx, MLX_KEY_A))
		(data->cur_x)--;
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT)
		|| mlx_is_key_down(data->mlx, MLX_KEY_D))
		(data->cur_x)++;
}

void	map_making(t_data *data)
{
	init_textures(data);
	load_textures(data);
	data->mlx = mlx_init(data->size_x * SPRITE_SIZE,
			data->size_y * SPRITE_SIZE, "So_long", true);
	if (!(data->mlx))
		error_exit(data, "Window couldn't be created");
	map_rendering(data);
	mlx_loop_hook(data->mlx, player_commands, data);
	mlx_loop(data->mlx);
	destroy_textures(data);
	mlx_terminate(data->mlx);
}
