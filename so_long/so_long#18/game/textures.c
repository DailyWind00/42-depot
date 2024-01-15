/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 09:18:28 by mgallais          #+#    #+#             */
/*   Updated: 2024/01/15 15:14:15 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	load_textures(t_data *data)
{
	ft_printf("| Loading textures :\n");
	data->texture.back = mlx_load_png("./sprites/Background.png");
	data->image.back = mlx_texture_to_image(data->mlx, data->texture.back);
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
	data->texture.sklt = mlx_load_png("./sprites/Skeleton.png");
	data->image.sklt = mlx_texture_to_image(data->mlx, data->texture.sklt);
	ft_printf("|\tTextures loaded\n|\n");
}

void	destroy_textures(t_data *data)
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
	mlx_delete_texture(data->texture.sklt);
	mlx_delete_image(data->mlx, data->image.sklt);
}
