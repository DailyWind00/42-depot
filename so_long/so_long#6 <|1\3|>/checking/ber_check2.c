/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ber_check2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:08:03 by mgallais          #+#    #+#             */
/*   Updated: 2024/01/03 13:40:27 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_rectangle(t_data *data)
{
	int	y;

	y = 0;
	ft_printf("|  Map shape check :\n");
	while (y != data->size_y)
	{
		if ((int)ft_strlen(data->map[y]) != data->size_x)
			error_exit("Not a rectangle");
		y++;
	}
	ft_printf("|\tMap is rectangle\n");
}

void	check_walls(t_data *data)
{
	int	y;
	int	x;

	y = 1;
	x = 0;
	ft_printf("|  Border walls check :\n");
	while (data->map[0][x])
	{
		if (data->map[0][x] != '1')
			error_exit("Border walls aren't closed");
		x++;
	}
	while (y != data->size_y - 1)
	{
		if (data->map[y][0] != '1' && data->map[y][data->size_x])
			error_exit("Border walls aren't closed");
		y++;
	}
	while (data->map[y][x])
	{
		if (data->map[0][x] != '1')
			error_exit("Border walls aren't closed");
		x++;
	}
	ft_printf("|\tBorder walls are closed\n");
}

static int	is_checked(t_data *data, int y, int x)
{
	return (data->check_map[y][x] == '1');
}

static void	count_element(t_data *data, int y, int x)
{
	if (data->map[y][x] == 'C')
		(data->collectible_i)++;
	if (data->map[y][x] == 'E')
		(data->exit_i)++;
	data->check_map[y][x] = '1';
}

int	check_is_possible(t_data *data, int y, int x)
{
	int	result[4];

	result[0] = 0;
	result[1] = 0;
	result[2] = 0;
	result[3] = 0;
	count_element(data, y, x);
	if (data->exit_i >= 1 && data->collectible_amount == data->collectible_i)
		return (1);
	if (x < 0 || x >= data->size_x || y < 0
		|| y >= data->size_y || data->map[y][x] == '1')
		return (0);
	if (data->map[y][x + 1] != '1' && !is_checked(data, y, x + 1))
		result[0] = check_is_possible(data, y, x + 1);
	if (data->map[y][x - 1] != '1' && !is_checked(data, y, x - 1))
		result[1] = check_is_possible(data, y, x - 1);
	if (data->map[y + 1][x] != '1' && !is_checked(data, y + 1, x))
		result[2] = check_is_possible(data, y + 1, x);
	if (data->map[y - 1][x] != '1' && !is_checked(data, y - 1, x))
		result[3] = check_is_possible(data, y - 1, x);
	return (result[0] || result[1] || result[2] || result[3]);
}