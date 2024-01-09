/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rendering.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:11:27 by mgallais          #+#    #+#             */
/*   Updated: 2024/01/09 15:34:31 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	load_texture(t_data *data)
{
	ft_printf("| Loading textures :\n");
	data->texture.back = mlx_load_png("./sprites/Background.png");
	data->image.back = mlx_texture_to_image(data->mlx, data->texture.back); //SISGEV
	data->texture.wall = mlx_load_png("./sprites/Wall.png");
	data->image.wall = mlx_texture_to_image(data->mlx, data->texture.wall);
	data->texture.play = mlx_load_png("./sprites/Player.png");
	data->image.play = mlx_texture_to_image(data->mlx, data->texture.play);
	data->texture.exit = mlx_load_png("./sprites/Trapdoor.png");
	data->image.exit = mlx_texture_to_image(data->mlx, data->texture.exit);
	data->texture.ggem = mlx_load_png("./sprites/Green_Gem.png");
	data->image.ggem = mlx_texture_to_image(data->mlx, data->texture.ggem);
	data->texture.bgem = mlx_load_png("./sprites/Blue_Gem.png");
	data->image.bgem = mlx_texture_to_image(data->mlx, data->texture.bgem);
	data->texture.wgem = mlx_load_png("./sprites/White_Gem.png");
	data->image.wgem = mlx_texture_to_image(data->mlx, data->texture.wgem);
	data->texture.rgem = mlx_load_png("./sprites/Red_Gem.png");
	data->image.rgem = mlx_texture_to_image(data->mlx, data->texture.rgem);
	ft_printf("|\tTextures loaded !\n");
}

static void	put_collectible(t_data *data, int y, int x)
{
	int	gem_color;

	gem_color = rand() % 4;
	if (gem_color == 0)
		mlx_image_to_window(data->mlx, data->image.ggem,
			x * SPRITE_SIZE, y * SPRITE_SIZE);
	if (gem_color == 1)
		mlx_image_to_window(data->mlx, data->image.bgem,
			x * SPRITE_SIZE, y * SPRITE_SIZE);
	if (gem_color == 2)
		mlx_image_to_window(data->mlx, data->image.wgem,
			x * SPRITE_SIZE, y * SPRITE_SIZE);
	if (gem_color == 3)
		mlx_image_to_window(data->mlx, data->image.rgem,
			x * SPRITE_SIZE, y * SPRITE_SIZE);
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
	if (data->map[y][x] == 'C')
		put_collectible(data, y, x);
}

void	map_rendering(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	mlx_image_to_window(data->mlx, data->image.play,
		data->cur_x * SPRITE_SIZE, data->cur_y * SPRITE_SIZE);
	while (y != data->size_y)
	{
		x = 0;
		while (x != data->size_x)
			put_sprite(data, y, x);
		y++;
	}
}

void	destroy_texture(t_data *data)
{
	mlx_delete_texture(data->texture.back);
	mlx_delete_image(data->mlx, data->image.back);
	mlx_delete_texture(data->texture.wall);
	mlx_delete_image(data->mlx, data->image.wall);
	mlx_delete_texture(data->texture.play);
	mlx_delete_image(data->mlx, data->image.play);
	mlx_delete_texture(data->texture.exit);
	mlx_delete_image(data->mlx, data->image.exit);
	mlx_delete_texture(data->texture.ggem);
	mlx_delete_image(data->mlx, data->image.ggem);
	mlx_delete_texture(data->texture.bgem);
	mlx_delete_image(data->mlx, data->image.bgem);
	mlx_delete_texture(data->texture.wgem);
	mlx_delete_image(data->mlx, data->image.wgem);
	mlx_delete_texture(data->texture.rgem);
	mlx_delete_image(data->mlx, data->image.rgem);
}