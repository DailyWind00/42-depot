/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rendering.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:11:27 by mgallais          #+#    #+#             */
/*   Updated: 2024/01/15 15:10:59 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	put_collectible2(t_data *data, int y, int x, int gem_color)
{
	if (gem_color == 2)
	{
		mlx_image_to_window(data->mlx, data->image.wgem,
			x * SPRITE_SIZE, y * SPRITE_SIZE);
		data->map[y][x] = 'W';
	}
	if (gem_color == 3)
	{
		mlx_image_to_window(data->mlx, data->image.rgem,
			x * SPRITE_SIZE, y * SPRITE_SIZE);
		data->map[y][x] = 'R';
	}
}

static void	put_collectible(t_data *data, int y, int x)
{
	int	gem_color;

	gem_color = rand() % 4;
	if (gem_color == 0)
	{
		mlx_image_to_window(data->mlx, data->image.ggem,
			x * SPRITE_SIZE, y * SPRITE_SIZE);
		data->map[y][x] = 'G';
	}
	if (gem_color == 1)
	{
		mlx_image_to_window(data->mlx, data->image.bgem,
			x * SPRITE_SIZE, y * SPRITE_SIZE);
		data->map[y][x] = 'B';
	}
	put_collectible2(data, y, x, gem_color);
}

static void	put_sprite(t_data *data, int y, int x)
{
	mlx_image_to_window(data->mlx, data->image.back,
		x * SPRITE_SIZE, y * SPRITE_SIZE);
	if (data->map[y][x] == '1')
		mlx_image_to_window(data->mlx, data->image.wall,
			x * SPRITE_SIZE, y * SPRITE_SIZE);
	if (data->map[y][x] == 'E')
		mlx_image_to_window(data->mlx, data->image.exit,
			x * SPRITE_SIZE, y * SPRITE_SIZE);
	if (data->map[y][x] == 'T')
		mlx_image_to_window(data->mlx, data->image.sklt,
			x * SPRITE_SIZE, y * SPRITE_SIZE);
	if (data->map[y][x] == 'C')
		put_collectible(data, y, x);
}

void	map_rendering(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y != data->size_y)
	{
		x = 0;
		while (x != data->size_x)
		{
			put_sprite(data, y, x);
			x++;
		}
		y++;
	}
	mlx_image_to_window(data->mlx, data->image.play,
		data->cur_x * SPRITE_SIZE, data->cur_y * SPRITE_SIZE);
}
