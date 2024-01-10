/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 09:18:28 by mgallais          #+#    #+#             */
/*   Updated: 2024/01/10 09:41:00 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_textures(t_data *data)
{
	ft_printf("| Allocing textures :\n");
	data->texture.back = malloc(sizeof(mlx_texture_t));
	data->image.back = malloc(sizeof(mlx_image_t));
	data->texture.wall = malloc(sizeof(mlx_texture_t));
	data->image.wall = malloc(sizeof(mlx_image_t));
	data->texture.play = malloc(sizeof(mlx_texture_t));
	data->image.play = malloc(sizeof(mlx_image_t));
	data->texture.exit = malloc(sizeof(mlx_texture_t));
	data->image.exit = malloc(sizeof(mlx_image_t));
	data->texture.ggem = malloc(sizeof(mlx_texture_t));
	data->image.ggem = malloc(sizeof(mlx_image_t));
	data->texture.bgem = malloc(sizeof(mlx_texture_t));
	data->image.bgem = malloc(sizeof(mlx_image_t));
	data->texture.wgem = malloc(sizeof(mlx_texture_t));
	data->image.wgem = malloc(sizeof(mlx_image_t));
	data->texture.rgem = malloc(sizeof(mlx_texture_t));
	data->image.rgem = malloc(sizeof(mlx_image_t));
	ft_printf("|\tTextures allocs !\n");
}

void	load_textures(t_data *data)
{
	ft_printf("| Loading textures :\n");
	data->texture.back = mlx_load_png("./sprites/Background.png");
	ft_printf("%p\n", data->texture.back);
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
}

void	free_textures(t_data *data)
{
	if (data->texture.back)
	{
		free(data->texture.back);
		free(data->image.back);
		free(data->texture.wall);
		free(data->image.wall);
		free(data->texture.play);
		free(data->image.play);
		free(data->texture.exit);
		free(data->image.exit);
		free(data->texture.ggem);
		free(data->image.ggem);
		free(data->texture.bgem);
		free(data->image.bgem);
		free(data->texture.wgem);
		free(data->image.wgem);
		free(data->texture.rgem);
		free(data->image.rgem);
	}
}
