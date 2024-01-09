/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_making.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 08:38:24 by mgallais          #+#    #+#             */
/*   Updated: 2024/01/09 09:26:36 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void ft_randomize(void *param)
{
	t_data *data = param;
	for (int32_t i = 0; i < (int32_t)data->image->width; ++i)
	{
		for (int32_t y = 0; y < (int32_t)data->image->height; ++y)
		{
			uint32_t color = ft_pixel(
				rand() % 0xFF, // R
				rand() % 0xFF, // G
				rand() % 0xFF, // B
				rand() % 0xFF  // A
			);
			mlx_put_pixel(data->image, i, y, color);
		}
	}
}

static void	player_commands(void *param)
{
	t_data *data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP) || mlx_is_key_down(data->mlx, MLX_KEY_W))
		data->image->instances[0].y -= 64;
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN) || mlx_is_key_down(data->mlx, MLX_KEY_S))
		data->image->instances[0].y += 64;
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT) || mlx_is_key_down(data->mlx, MLX_KEY_A))
		data->image->instances[0].x -= 64;
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT) || mlx_is_key_down(data->mlx, MLX_KEY_D))
		data->image->instances[0].x += 64;
}

void	map_making(t_data *data)
{
	data->mlx = mlx_init(data->size_x * 64, data->size_y * 64, "So_long", true);
	if (!(data->mlx))
		error_exit(data, "Window couldn't be created");
	data->image = mlx_new_image(data->mlx, 64, 64);
	if (!(data->image))
	{
		mlx_close_window(data->mlx);
		error_exit(data, "Image couldn't be created");
	}
	if (mlx_image_to_window(data->mlx, data->image, 0, 0) == -1)
	{
		mlx_close_window(data->mlx);
		error_exit(data, "Image couldn't be printed");
	}
	mlx_loop_hook(data->mlx, ft_randomize, data);
	mlx_loop_hook(data->mlx, player_commands, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
}
