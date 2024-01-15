/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:28:12 by mgallais          #+#    #+#             */
/*   Updated: 2024/01/15 15:09:07 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	map_malloc(t_data *data)
{
	int	i;

	i = 0;
	data->map = malloc(sizeof(char *) * data->size_y);
	data->check_map = malloc(sizeof(char *) * data->size_y);
	while (i != data->size_y)
	{
		data->map[i] = malloc(sizeof(char) * data->size_x + 1);
		data->check_map[i++] = malloc(sizeof(char) * data->size_x + 1);
	}
}

static void	check_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y != data->size_y)
	{
		while (x != data->size_x)
		{
			if (data->map[y][x] != '1' && data->map[y][x] != '0'
				&& data->map[y][x] != 'P' && data->map[y][x] != 'C'
				&& data->map[y][x] != 'E' && data->map[y][x] != 'T')
				error_exit(data, "Invalid character in map");
			x++;
		}
		x = 0;
		y++;
	}
}

static void	check_nothing(t_data *data, char *buf, int fd)
{
	if (!buf)
	{
		free(buf);
		close(fd);
		error_exit(data, "There's nothing is the map");
	}
}

void	map_parsing(t_data *data, char *filepath)
{
	int		fd;
	char	*buf;

	ft_printf("|  Map parsing :\n");
	fd = open(filepath, O_RDONLY);
	buf = get_next_line(fd);
	check_nothing(data, buf, fd);
	data->size_x = ft_strlen(buf) - 1;
	while (buf)
	{
		free(buf);
		(data->size_y)++;
		buf = get_next_line(fd);
	}
	if (data->size_x < 3 || data->size_y < 3)
		error_exit(data, "Invalid map");
	free(buf);
	close(fd);
	map_malloc(data);
	create_map(data, filepath);
	check_map(data);
	ft_printf("|\tMap valid\n");
}
