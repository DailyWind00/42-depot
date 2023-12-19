/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ber_check2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:08:03 by mgallais          #+#    #+#             */
/*   Updated: 2023/12/19 10:43:29 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	check_top_bottom(char *previous_result)
{
	int	i;

	i = 0;
	while (previous_result[i + 1] != '\n')
	{
		if (previous_result[i] != '1')
		{
			free(previous_result);
			error_exit("walls aren't closed");
		}
		i++;
	}
}

void	check_walls(int fd)
{
	t_error	error;

	error.previous_result = get_next_line(fd);
	error.gnl_result = get_next_line(fd);
	error.i = ft_strlen(error.gnl_result);
	check_top_bottom(error.gnl_result);
	while (error.gnl_result)
	{
		if (error.gnl_result[0] != '1' && error.gnl_result[error.i - 1] != '1')
		{
			free(error.gnl_result);
			free(error.previous_result);
			error_exit("walls aren't closed");
		}
		error.previous_result = error.gnl_result;
		error.gnl_result = get_next_line(fd);
	}
	free(error.gnl_result);
	check_top_bottom(error.previous_result);
	free(error.previous_result);
}

static int	is_checked(t_error *error, int y, int x)
{
	return (error->check[y][x] == 1);
}

static void	count_element(t_data *data, t_error *error, int y, int x)
{
	if (data->map[y][x] == 'C')
		(error->collectible_i)++;
	if (data->map[y][x] == 'E')
		(error->exit_i)++;
	error->check[y][x] = 1;
}

int	check_is_possible(t_data *data, t_error *error, int y, int x)
{
	int	result[4];

	result[0] = 0;
	result[1] = 0;
	result[2] = 0;
	result[3] = 0;
	count_element(data, error, y, x);
	if (error->exit_i >= 1 && error->collectible_amount == error->collectible_i)
		return (1);
	if (x < 0 || x >= data->size_x || y < 0
		|| y >= data->size_y || data->map[y][x] == '1')
		return (0);
	if (data->map[y][x + 1] != '1' && !is_checked(error, y, x + 1))
		result[0] = check_is_possible(data, error, y, x + 1);
	if (data->map[y][x - 1] != '1' && !is_checked(error, y, x - 1))
		result[1] = check_is_possible(data, error, y, x - 1);
	if (data->map[y + 1][x] != '1' && !is_checked(error, y + 1, x))
		result[2] = check_is_possible(data, error, y + 1, x);
	if (data->map[y - 1][x] != '1' && !is_checked(error, y - 1, x))
		result[3] = check_is_possible(data, error, y - 1, x);
	return (result[0] || result[1] || result[2] || result[3]);
}
