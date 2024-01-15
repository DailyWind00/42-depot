/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:15:05 by mgallais          #+#    #+#             */
/*   Updated: 2024/01/10 15:04:59 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	up(t_data *data)
{
	if (movement_check_wall(data, data->cur_y - 1, data->cur_x))
	{
		(data->cur_y)--;
		(data->movements)++;
		data->image.play->instances[0].y -= SPRITE_SIZE;
		ft_printf("| Movement : %i\n", data->movements);
		movement_check_collectible(data);
		movement_check_exit(data);
		usleep(FPS);
	}
}

void	down(t_data *data)
{
	if (movement_check_wall(data, data->cur_y + 1, data->cur_x))
	{
		(data->cur_y)++;
		(data->movements)++;
		data->image.play->instances[0].y += SPRITE_SIZE;
		ft_printf("| Movement : %i\n", data->movements);
		movement_check_collectible(data);
		movement_check_exit(data);
		usleep(FPS);
	}
}

void	left(t_data *data)
{
	if (movement_check_wall(data, data->cur_y, data->cur_x - 1))
	{
		(data->cur_x)--;
		(data->movements)++;
		data->image.play->instances[0].x -= SPRITE_SIZE;
		ft_printf("| Movement : %i\n", data->movements);
		movement_check_collectible(data);
		movement_check_exit(data);
		usleep(FPS);
	}
}

void	right(t_data *data)
{
	if (movement_check_wall(data, data->cur_y, data->cur_x + 1))
	{
		(data->cur_x)++;
		(data->movements)++;
		data->image.play->instances[0].x += SPRITE_SIZE;
		ft_printf("| Movement : %i\n", data->movements);
		movement_check_collectible(data);
		movement_check_exit(data);
		usleep(FPS);
	}
}
