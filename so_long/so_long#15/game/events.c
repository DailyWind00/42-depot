/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:56:43 by mgallais          #+#    #+#             */
/*   Updated: 2024/01/12 08:44:34 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	movement_check_wall(t_data *data, int y, int x)
{
	return (!(data->map[y][x] == '1'));
}

static void	delete_gem_sprite(t_data *data, char gem_color, int gem_instance)
{
	if (gem_color == 'G')
		data->image.ggem->instances[gem_instance].enabled = false;
	if (gem_color == 'B')
		data->image.bgem->instances[gem_instance].enabled = false;
	if (gem_color == 'W')
		data->image.wgem->instances[gem_instance].enabled = false;
	if (gem_color == 'R')
		data->image.rgem->instances[gem_instance].enabled = false;
}

void	remove_gem(t_data *data)
{
	t_gem	gem;

	gem.y = 0;
	gem.x = 0;
	gem.gem_instance = -1;
	gem.gem_color = data->map[data->cur_y][data->cur_x];
	while (gem.y <= data->cur_y)
	{
		if (gem.y == data->cur_y)
		{
			while (gem.x <= data->cur_x)
				if (data->map[gem.y][gem.x++] == gem.gem_color
					|| data->map[gem.y][gem.x - 1] == gem.gem_color + 32)
					gem.gem_instance++;
		}
		else
			while (gem.x <= data->size_x)
				if (data->map[gem.y][gem.x++] == gem.gem_color
					|| data->map[gem.y][gem.x - 1] == gem.gem_color + 32)
					gem.gem_instance++;
		gem.x = 0;
		gem.y++;
	}
	delete_gem_sprite(data, gem.gem_color, gem.gem_instance);
}

void	movement_check_collectible(t_data *data)
{
	if (data->map[data->cur_y][data->cur_x] == 'G'
		|| data->map[data->cur_y][data->cur_x] == 'B'
		|| data->map[data->cur_y][data->cur_x] == 'W'
		|| data->map[data->cur_y][data->cur_x] == 'R')
	{
		remove_gem(data);
		data->map[data->cur_y][data->cur_x] += 32;
		(data->collectible_i)++;
		ft_printf("|\tGems : %i\n", data->collectible_i);
		if (data->collectible_i == data->collectible_amount)
			ft_printf("|\t\tYou find all gems ! Find the exit\n");
	}
}

void	movement_check_exit(t_data *data)
{
	if (data->map[data->cur_y][data->cur_x] == 'E'
		&& data->collectible_i == data->collectible_amount)
	{
		ft_printf("| You flee with all the gems !\n");
		mlx_close_window(data->mlx);
	}
	else if (data->map[data->cur_y][data->cur_x] == 'E')
		ft_printf("|\n| Your greed keep you from exiting without all gems !\n");
}
