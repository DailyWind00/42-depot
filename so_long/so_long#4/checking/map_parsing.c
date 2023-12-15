/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:28:12 by mgallais          #+#    #+#             */
/*   Updated: 2023/12/15 15:17:50 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	map_alloc(t_data *data, t_error error)
{
	data->map = malloc(sizeof(char **) * data->size_y + 1);
	error.i = 0;
	if (!(data->map))
		error_exit("malloc error");
	data->map[data->size_y + 1] = NULL;
	while (data->index <= data->size_y)
	{
		data->map[data->index] = malloc(sizeof(char) * data->size_x + 1);
		if (!(data->map[data->index]))
			error_exit("malloc error");
		(data->index)++;
	}
}

void	map_parsing(t_data *data, int fd)
{
	t_error	error;

	map_alloc(data, error);
	error.gnl_result = get_next_line(fd);
	error.gnl_result[data->size_x + 1] = 0;
	while (error.gnl_result)
	{
		data->map[error.i] = error.gnl_result;
		(error.i)++;
		error.gnl_result = get_next_line(fd);
		if (error.gnl_result)
			error.gnl_result[data->size_x + 1] = 0;
	}
	close(fd);
	free(error.gnl_result);
}
